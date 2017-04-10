#include "medianfilter.h"
#include <QDebug>

MedianFilter* MedianFilter::mfStatic = NULL;

MedianFilter::MedianFilter(QObject *parent) : QObject(parent)
{
    mfStatic = this;
    image = NULL;
    extensionImage = NULL;
    resImage = NULL;
    futureWatcher = new QFutureWatcher<void>(this);
    progressDialog = new QProgressDialog(NULL);
    connect(futureWatcher, SIGNAL(progressValueChanged(int)), progressDialog, SLOT(setValue(int)));
    connect(futureWatcher, SIGNAL(progressRangeChanged(int,int)), progressDialog, SLOT(setRange(int,int)));
    connect(progressDialog, SIGNAL(canceled()), this, SLOT(cancelMedianFilter()));
}

MedianFilter::~MedianFilter()
{
    if (futureWatcher->isRunning())
    {
        futureWatcher->cancel();
        futureWatcher->waitForFinished();
    }

    if(extensionImage)
        delete [] extensionImage;
}

void MedianFilter::cancelMedianFilter()
{
    if (futureWatcher->isRunning())
    {
        futureWatcher->cancel();
        futureWatcher->waitForFinished();
    }
}

void getResPixelValueST(IndexPair &p)
{
    MedianFilter::mfStatic->getResPixelValue(p);
}

void MedianFilter::getResPixelValue(IndexPair &p)
{
    int k = 0, workingWeight = originImageweight+2*radius;
    element window[windowSize];

    for (int i = p.i - radius; i < p.i + radius+1; i++)
    {
        for (int j = p.j - radius; j < p.j + radius + 1; j++)
            window[k++] = this->extensionImage[i * (workingWeight) + j];
    }

    for (int j = 0; j <= windowSizeHalf; j++)
    {
        int min = j;
        for (int l = j + 1; l < windowSize; l++)
            if (window[l] < window[min])
                min = l;
        const element el = window[j];
        window[j] = window[min];
        window[min] = el;
    }

    resImage[(p.i - radius) * originImageweight + (p.j - radius)] = window[windowSizeHalf];
}

void MedianFilter::applyMedianFilter(element *i, element *res, const int imageHeight, const int imageWidth, const int r)
{ 
    if (!i || imageHeight < 1 || imageWidth < 1)
        return;

    if (futureWatcher->isRunning())
    {
        futureWatcher->cancel();
        futureWatcher->waitForFinished();
    }

    this->originImageweight = imageWidth;
    this->radius = r;
    image = i;

    int extWidth = imageWidth + 2*radius, extHeight = imageHeight + 2*radius;
    this->windowSize = (2*radius+1) * (2*radius+1);
    this->windowSizeHalf = windowSize/2;

    extensionImage = new element[extWidth * extHeight];
    if (!extensionImage)
        return;
    resImage = res;

    //Init working extented image
    for (int i = 0; i < imageHeight; i++)
    {
        //memcpy(extensionImage + (w + 2) * (i + 1) + 1, image + w * i, w * sizeof(element));
        //extensionImage[(w + 2) * (i + 1)] = image[w * i]; //first cells on the line
        //extensionImage[(w + 2) * (i + 2) - 1] = image[w * (i + 1) - 1];
        memcpy(extensionImage + extWidth * (i + radius) + radius, image + imageWidth * i, imageWidth * sizeof(element));
        memcpy(extensionImage + extWidth * (i + radius), image + (imageWidth * i), radius * sizeof(element)); //first cells on the line
        memcpy(extensionImage + (extWidth * (i + radius + 1) - radius), image + imageWidth * (i + 1) - radius, radius * sizeof(element));
    }

    for(int i = 0; i < radius; i++)
    {
        memcpy(extensionImage + i * extWidth, extensionImage + extWidth * (i + imageHeight - 1), extWidth * sizeof(element)); //first lines of  the window
        memcpy(extensionImage + extWidth * (imageHeight + radius + i), extensionImage + extWidth * (imageHeight + radius - i - 1), extWidth * sizeof(element)); //last lines
        //qDebug()<<i+h-1<<h+r+i<<h+r-i-1;

        //memcpy(extensionImage, extensionImage + w + 2, (w + 2) * sizeof(element)); //first line
        //memcpy(extensionImage + (w + 2) * (h + 1), extensionImage + (w + 2) * h, (w + 2) * sizeof(element)); //last line
    }

    QList<IndexPair> indexes;
    for (int i = radius; i < imageHeight + radius; i++)
    {   for (int j = radius; j < imageWidth + radius; j++)
        {
            IndexPair p(i,j);
            indexes<<p;
        }
    }

    futureWatcher->setFuture(QtConcurrent::map(indexes, getResPixelValueST));
    progressDialog->exec();
    futureWatcher->waitForFinished();

}



