#include "histogram.h"

#include <sstream>
#include <iostream>


Histogram::Histogram(QWidget * parent) : QLabel(parent)
{
    for(int i = 0;i<256;i++)
    {
        bwHstgrm[i] = 0;
        redHstgrm[i] = 0;
        greenHstgrm[i] = 0;
        blueHstgrm[i] = 0;
    }

    bwHstgrm[256] = -1;
    redHstgrm[256] = -1;
    greenHstgrm[256] = -1;
    blueHstgrm[256] = -1;

    redHstgrm[257] = 0;
    greenHstgrm[257] = 0;
    blueHstgrm[257] = 0;

    bwHstgrm[257] = 0;
    bwHstgrm[258] = 0;
}



Histogram::Histogram(QWidget * parent, Histogram * hstgrm) : QLabel(parent)
{
    for(int i = 0;i<258;i++)
    {
        bwHstgrm[i] = hstgrm->bwHstgrm[i];
        redHstgrm[i] = hstgrm->redHstgrm[i];
        greenHstgrm[i] = hstgrm->greenHstgrm[i];
        blueHstgrm[i] = hstgrm->blueHstgrm[i];
    }

    bwHstgrm[258] = hstgrm->bwHstgrm[258];
}



void Histogram::computeHstgrm(QImage img)
{
    if (!img.isNull())
    {
        for(int i = 0;i<img.height();i++)
        {
            for(int j = 0;j<img.width();j++)
            {
                int bwValue = qGray(img.pixel(j, i));

                int redValue = qRed(img.pixel(j, i));
                int greenValue = qGreen(img.pixel(j, i));
                int blueValue = qBlue(img.pixel(j, i));

                bwHstgrm[bwValue]++;
                redHstgrm[redValue]++;
                greenHstgrm[greenValue]++;
                blueHstgrm[blueValue]++;
            }
        }

        for(int i = 0;i<256;i++)
        {
            // maximum values
            if (bwHstgrm[256] < bwHstgrm[i])
                bwHstgrm[256] = bwHstgrm[i];

            if (redHstgrm[256] < redHstgrm[i])
                redHstgrm[256] = redHstgrm[i];

            if (greenHstgrm[256] < greenHstgrm[i])
                greenHstgrm[256] = greenHstgrm[i];

            if (blueHstgrm[256] < blueHstgrm[i])
                blueHstgrm[256] = blueHstgrm[i];

            // values of colour components
            redHstgrm[257] += i*redHstgrm[i];
            greenHstgrm[257] += i*greenHstgrm[i];
            blueHstgrm[257] += i*blueHstgrm[i];

            // values of dark and light component
            if (i <= 127)
                bwHstgrm[257] += (127-i)*bwHstgrm[i];
            else
                bwHstgrm[258] += (i-127)*bwHstgrm[i];
        }
    }
}



void Histogram::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);

    int step = 100;              // distance between histograms
    int height = 255+10;        // histograms height
    int xBase = 99;             // x coordinate of the first histogram origin
    int yBase = 30+height+1;    // y coordinate of the first histogram origin

    QPainter painter(this);
    painter.setPen(Qt::black);


    // 显示在第一行
    // bw hstgrm
    if (bwHstgrm[256] != -1)
        drawBwHstgrm(xBase, yBase, height);
    else
        painter.drawText(xBase, yBase-height/2+5, tr("Can't load the gray levels histogram."));

    // red hstgrm
    if (redHstgrm[256] != -1)
        drawRedHstgrm(xBase+step+height, yBase, height);
    else
        painter.drawText(xBase+step+height+1-height/2+5, yBase, tr("Can't load the red component histogram."));


    // 显示在第二行
    // green hstgrm
    if (greenHstgrm[256] != -1)
        drawGreenHstgrm(xBase, yBase+step+height+1, height);
    else
        painter.drawText(xBase, yBase+(step+height+1), tr("Can't load the green component histogram."));
    // blue hstgrm
    if (blueHstgrm[256] != -1)
        drawBlueHstgrm(xBase+step+height, yBase+step+height+1, height);
    else
        painter.drawText(xBase+step+height, yBase+step+height+1, tr("Can't load the blue component histogram."));

}



void Histogram::drawBwHstgrm(int xBase, int yBase, int height)
{
    QPainter painter(this);

    painter.setPen(Qt::darkGray);

    float max = bwHstgrm[256];

    if (max < redHstgrm[256])
        max = redHstgrm[256];

    if (max < greenHstgrm[256])
        max = greenHstgrm[256];

    if (max < blueHstgrm[256])
        max = blueHstgrm[256];

    // drawing the histogram
    for(int i = 0;i<256;i++)
    {
        painter.drawLine(xBase+1+i, yBase, xBase+1+i,
            yBase-(float)(256./max)*(float)bwHstgrm[i]);
    }

    painter.drawText(xBase, yBase+25, tr("black"));
    painter.drawText(xBase+220, yBase+25, tr("white"));

    painter.setPen(Qt::black);

    painter.drawText(xBase+40, yBase-height-10, tr("GRAY LEVELS HISTOGRAM"));

    painter.drawText(xBase+100, yBase+15, tr("Intensity"));
    painter.drawText(xBase-84, yBase-height/2+5, tr("Pixels count"));

    // abscissa
    painter.drawLine(xBase, yBase, xBase+256+1, yBase);
    painter.drawLine(xBase, yBase+1, xBase+256+1, yBase+1);

    // left ordinate
    painter.drawLine(xBase, yBase, xBase, yBase-height);
    painter.drawLine(xBase-1, yBase, xBase-1, yBase-height);

    // right ordinate
    painter.drawLine(xBase+256+1, yBase, xBase+256+1, yBase-height);
    painter.drawLine(xBase+256+2, yBase, xBase+256+2, yBase-height);

    // left ordinate arrow
    painter.drawLine(xBase, yBase-height, xBase+4, yBase-height+7);
    painter.drawLine(xBase-1, yBase-height, xBase-1-4, yBase-height+7);

    // right ordinate arrow
    painter.drawLine(xBase+256+1, yBase-height, xBase+256+1-4, yBase-height+7);
    painter.drawLine(xBase+256+2, yBase-height, xBase+256+2+4, yBase-height+7);
}



void Histogram::drawRedHstgrm(int xBase, int yBase, int height)
{
    QPainter painter(this);

    painter.setPen(Qt::darkRed);

    float max = bwHstgrm[256];

    if (max < redHstgrm[256])
        max = redHstgrm[256];

    if (max < greenHstgrm[256])
        max = greenHstgrm[256];

    if (max < blueHstgrm[256])
        max = blueHstgrm[256];

    // drawing the histogram
    for(int i = 0;i<256;i++)
    {
        painter.drawLine(xBase+1+i, yBase, xBase+1+i,
            yBase-(float)(256./max)*(float)redHstgrm[i]);
    }

    painter.drawText(xBase, yBase+25, tr("dark"));
    painter.drawText(xBase+225, yBase+25, tr("light"));

    painter.setPen(Qt::black);

    painter.drawText(xBase+25, yBase-height-10, tr("RED COMPONENT HISTOGRAM"));

    painter.drawText(xBase+100, yBase+15, tr("Intensity"));
    painter.drawText(xBase-84, yBase-height/2+5, tr("Pixels count"));

    // abscissa
    painter.drawLine(xBase, yBase, xBase+256+1, yBase);
    painter.drawLine(xBase, yBase+1, xBase+256+1, yBase+1);

    // left ordinate
    painter.drawLine(xBase, yBase, xBase, yBase-height);
    painter.drawLine(xBase-1, yBase, xBase-1, yBase-height);

    // right ordinate
    painter.drawLine(xBase+256+1, yBase, xBase+256+1, yBase-height);
    painter.drawLine(xBase+256+2, yBase, xBase+256+2, yBase-height);

    // left ordinate arrow
    painter.drawLine(xBase, yBase-height, xBase+4, yBase-height+7);
    painter.drawLine(xBase-1, yBase-height, xBase-1-4, yBase-height+7);

    // right ordinate arrow
    painter.drawLine(xBase+256+1, yBase-height, xBase+256+1-4, yBase-height+7);
    painter.drawLine(xBase+256+2, yBase-height, xBase+256+2+4, yBase-height+7);
}



void Histogram::drawGreenHstgrm(int xBase, int yBase, int height)
{
    QPainter painter(this);

    painter.setPen(Qt::darkGreen);

    float max = bwHstgrm[256];

    if (max < redHstgrm[256])
        max = redHstgrm[256];

    if (max < greenHstgrm[256])
        max = greenHstgrm[256];

    if (max < blueHstgrm[256])
        max = blueHstgrm[256];

    // drawing the histogram
    for(int i = 0;i<256;i++)
    {
        painter.drawLine(xBase+1+i, yBase, xBase+1+i,
            yBase-(float)(256./max)*(float)greenHstgrm[i]);
    }

    painter.drawText(xBase, yBase+25, tr("dark"));
    painter.drawText(xBase+225, yBase+25, tr("light"));

    painter.setPen(Qt::black);

    painter.drawText(xBase+15, yBase-height-10, tr("GREEN COMPONENT HISTOGRAM"));

    painter.drawText(xBase+100, yBase+15, tr("Intensity"));
    painter.drawText(xBase-84, yBase-height/2+5, tr("Pixels count"));

    // abscissa
    painter.drawLine(xBase, yBase, xBase+256+1, yBase);
    painter.drawLine(xBase, yBase+1, xBase+256+1, yBase+1);

    // left ordinate
    painter.drawLine(xBase, yBase, xBase, yBase-height);
    painter.drawLine(xBase-1, yBase, xBase-1, yBase-height);

    // right ordinate
    painter.drawLine(xBase+256+1, yBase, xBase+256+1, yBase-height);
    painter.drawLine(xBase+256+2, yBase, xBase+256+2, yBase-height);

    // left ordinate arrow
    painter.drawLine(xBase, yBase-height, xBase+4, yBase-height+7);
    painter.drawLine(xBase-1, yBase-height, xBase-1-4, yBase-height+7);

    // right ordinate arrow
    painter.drawLine(xBase+256+1, yBase-height, xBase+256+1-4, yBase-height+7);
    painter.drawLine(xBase+256+2, yBase-height, xBase+256+2+4, yBase-height+7);
}



void Histogram::drawBlueHstgrm(int xBase, int yBase, int height)
{
    QPainter painter(this);

    painter.setPen(Qt::darkBlue);

    float max = bwHstgrm[256];

    if (max < redHstgrm[256])
        max = redHstgrm[256];

    if (max < greenHstgrm[256])
        max = greenHstgrm[256];

    if (max < blueHstgrm[256])
        max = blueHstgrm[256];

    // drawing the histogram
    for(int i = 0;i<256;i++)
    {
        painter.drawLine(xBase+1+i, yBase, xBase+1+i,
            yBase-(float)(256./max)*(float)blueHstgrm[i]);
    }

    painter.drawText(xBase, yBase+25, tr("dark"));
    painter.drawText(xBase+225, yBase+25, tr("light"));

    painter.setPen(Qt::black);

    painter.drawText(xBase+20, yBase-height-10, tr("BLUE COMPONENT HISTOGRAM"));

    painter.drawText(xBase+100, yBase+15, tr("Intensity"));
    painter.drawText(xBase-84, yBase-height/2+5, tr("Pixels count"));

    // abscissa
    painter.drawLine(xBase, yBase, xBase+256+1, yBase);
    painter.drawLine(xBase, yBase+1, xBase+256+1, yBase+1);

    // left ordinate
    painter.drawLine(xBase, yBase, xBase, yBase-height);
    painter.drawLine(xBase-1, yBase, xBase-1, yBase-height);

    // right ordinate
    painter.drawLine(xBase+256+1, yBase, xBase+256+1, yBase-height);
    painter.drawLine(xBase+256+2, yBase, xBase+256+2, yBase-height);

    // left ordinate arrow
    painter.drawLine(xBase, yBase-height, xBase+4, yBase-height+7);
    painter.drawLine(xBase-1, yBase-height, xBase-1-4, yBase-height+7);

    // right ordinate arrow
    painter.drawLine(xBase+256+1, yBase-height, xBase+256+1-4, yBase-height+7);
    painter.drawLine(xBase+256+2, yBase-height, xBase+256+2+4, yBase-height+7);
}



int Histogram::getBwHstgrm(int index)
{
    if (index >= 0 && index <= 258)
        return bwHstgrm[index];
    else
        return -2;
}



int Histogram::getRedHstgrm(int index)
{
    if (index >= 0 && index <= 257)
        return redHstgrm[index];
    else
        return -2;
}



int Histogram::getGreenHstgrm(int index)
{
    if (index >= 0 && index <= 257)
        return greenHstgrm[index];
    else
        return -2;
}



int Histogram::getBlueHstgrm(int index)
{
    if (index >= 0 && index <= 257)
        return blueHstgrm[index];
    else
        return -2;
}


