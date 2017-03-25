#ifndef TOOLS_H
#define TOOLS_H

#include <QImage>


namespace Tools {
QImage GreyScale(QImage origin);
QImage Warm(int delta, QImage origin);
}

#endif // TOOLS_H
