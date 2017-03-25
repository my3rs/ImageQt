#include "tools.h"

QImage Tools::GreyScale(QImage origin)
{
    QImage *newImage = new QImage(origin.width(), origin.height(),
                                   QImage::Format_ARGB32);
    QColor oldColor;

    for (int x=0; x<newImage->width(); x++) {
        for (int y=0; y<newImage->height(); y++) {
            oldColor = QColor(origin.pixel(x,y));
            int average = (oldColor.red()+oldColor.green()+oldColor.blue())/3;
            newImage->setPixel(x,y,qRgb(average,average,average));
        }
    }

    return *newImage;

}

QImage Tools::Warm(int delta, QImage origin)
{
    QImage *newImage = new QImage(origin.width(), origin.height(),
                                  QImage::Format_ARGB32);

    QColor oldColor;
    int r, g, b;

    for (int x=0; x<newImage->width(); x++)
    {
        for (int y=0; y<newImage->height(); y++)
        {
            oldColor = QColor(origin.pixel(x,y));

            r = oldColor.red() + delta;
            g = oldColor.green() + delta;
            b = oldColor.blue();
//            qDebug()<<r<<" "<<g<<""<<b;

            // Check if the new values are between 0 and 255
            r = qBound(0, r, 255);
            g = qBound(0, g, 255);

            newImage->setPixel(x,y, qRgb(r,g,b));
        }
    }
    return *newImage;
}
