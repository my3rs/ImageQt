#ifndef DIALOG_EXP_TRANSFORM_H
#define DIALOG_EXP_TRANSFORM_H

#include <QDialog>

namespace Ui {
class DialogExpTransform;
}

class DialogExpTransform : public QDialog
{
    Q_OBJECT

public:
    explicit DialogExpTransform(QWidget *parent = 0);
    ~DialogExpTransform();

private:
    Ui::DialogExpTransform *ui;

    void paintFunctionImage(double b, double c, double a);

signals:
    void sendData(double, double, double);

private slots:
    void on_buttonBox_accepted();
    void on_bDoubleSpinBox_valueChanged(double arg1);
    void on_cDoubleSpinBox_valueChanged(double arg1);
    void on_aDoubleSpinBox_valueChanged(double arg1);
};

#endif // DIALOG_EXP_TRANSFORM_H
