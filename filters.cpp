#include "filters.h"

/******************************************************************************
 *                          Add metal texture
 * ***************************************************************************/
QImage Filters::Metal(QImage origin)
{
    QImage *baseImage = new QImage(":/img/src/metal.png");
    QImage darkImage = Tools::Brightness(-100, origin);
    QImage greyImage = Tools::GreyScale(darkImage);
    QPainter painter;

    QImage newImage = baseImage->scaled(QSize(origin.width(),origin.height()));

    painter.begin(&newImage);
    painter.setOpacity(0.5);
    painter.drawImage(0, 0, greyImage);
    painter.end();

    return newImage;
}
