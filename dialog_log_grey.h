#ifndef DIALOG_LOG_GREY_H
#define DIALOG_LOG_GREY_H

#include <QDialog>
#include <QtMath>

namespace Ui {
class DialogLogGrey;
}

class DialogLogGrey : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogGrey(QWidget *parent = 0);
    ~DialogLogGrey();

private:
    Ui::DialogLogGrey *ui;

    void paintFunctionImage(double __a, double __b);

signals:
    void sendData(double a, double b);
private slots:
    void on_buttonBox_accepted();
    void on_aDoubleSpinBox_valueChanged(double arg1);
    void on_bDoubleSpinBox_valueChanged(double arg1);
};

#endif // DIALOG_LOG_GREY_H
