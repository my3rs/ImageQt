/****************************************************************************
 *                              Basic tools:
 * greyscale, brightness, flip, wand or cool ...
 * *************************************************************************/

#ifndef TOOLS_H
#define TOOLS_H

#include <QImage>
#include <QDebug>
#include <QPainter>
#include <QtMath>

namespace Tools {

QImage GreyScale(QImage origin);
QImage Warm(int delta, QImage origin);
QImage Cool(int delta, QImage origin);
QImage DrawFrame(QImage origin, QImage &frame);
QImage Brightness(int delta, QImage origin);
QImage Horizontal(const QImage &origin);
QImage Vertical(const QImage &origin);
QImage LinearLevelTransformation(const QImage &origin, double a, double b);
QImage LogGreyLevelTransformation(const QImage &origin, double a, double b);
QImage PowerGreyLevelTransformation(const QImage &origin, double c, double r, double b);
QImage ExpTransform(const QImage &origin, double b, double c, double a);
QImage TwoThreshold(const QImage &orogin, double t1, double t2, int option);
QImage StretchTransform(const QImage &origin,
                                        int x1, int x2,
                                        double k1, double k2, double k3,
                                        double b2, double b3);
QImage SimpleSmooth(const QImage &origin);
QImage MeidaFilter(const QImage &origin, int radius);

}




#endif // TOOLS_H
