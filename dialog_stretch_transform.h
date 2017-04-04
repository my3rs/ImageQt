#ifndef DIALOG_STRETCH_TRANSFORM_H
#define DIALOG_STRETCH_TRANSFORM_H

#include <QDialog>

namespace Ui {
class DialogStretchTransform;
}

class DialogStretchTransform : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStretchTransform(QWidget *parent = 0);
    ~DialogStretchTransform();

    void calK();

private slots:
    void on_x1_valueChanged(int arg1);

    void on_y1_valueChanged(int arg1);

    void on_x2_valueChanged(int arg1);

    void on_y2_valueChanged(int arg1);

private:
    Ui::DialogStretchTransform *ui;
    void paintFunctionImage();

    double k1, k2, k3;
};

#endif // DIALOG_STRETCH_TRANSFORM_H
