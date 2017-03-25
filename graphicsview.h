#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QtMath>

class GraphicsView : public QGraphicsView
{
private:
    int factor;

public:
    GraphicsView(QWidget* parent = 0);
    ~GraphicsView();

    int getFactor();
    void setFactor(int _factor);

protected:
    virtual void wheelEvent(QWheelEvent *e);
};

#endif // GRAPHICSVIEW_H
