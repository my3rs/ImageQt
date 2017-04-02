#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    factor = 0;
}

GraphicsView::~GraphicsView()
{
    // to do
}

int GraphicsView::getFactor()
{
    return factor;
}

void GraphicsView::setFactor(int _factor)
{
    if (_factor = 0)
    {
        factor = 0;
    }
    else
    {
        factor += _factor;
    }
}

void GraphicsView::wheelEvent(QWheelEvent *e)
{
    // Calculate wheel movement
    int distance = e->delta()/15/8;
    qreal val;

    if (distance != 0)
    {
        val = pow(1.2, distance);
        this->scale(val, val);
        if (distance > 0)
        {
            factor ++;
        }
        else
        {
            factor --;
        }
    }
}
