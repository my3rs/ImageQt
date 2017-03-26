#ifndef TOOLS_H
#define TOOLS_H

#include <QImage>
#include <QDebug>
#include <QPainter>

namespace Tools {

QImage GreyScale(QImage origin);
QImage Warm(int delta, QImage origin);
QImage Cool(int delta, QImage origin);
QImage DrawFrame(QImage origin, QImage &frame);
QImage Brightness(int delta, QImage origin);
QImage Horizontal(const QImage &origin);
}

#endif // TOOLS_H
