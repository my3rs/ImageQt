#ifndef DIALOG_POWER_GREY_H
#define DIALOG_POWER_GREY_H

#include <QDialog>

namespace Ui {
class DialogPowerGrey;
}

class DialogPowerGrey : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPowerGrey(QWidget *parent = 0);
    ~DialogPowerGrey();

private:
    Ui::DialogPowerGrey *ui;

    void paintFunctionImage(double c, double r, double b);


signals:
    void sendData(double, double, double);
private slots:
    void on_buttonBox_accepted();
    void on_cDoubleSpinBox_valueChanged(double arg1);
    void on_rDoubleSpinBox_valueChanged(double arg1);
    void on_bDoubleSpinBox_valueChanged(double arg1);
};

#endif // DIALOG_POWER_GREY_H
