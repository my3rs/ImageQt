#ifndef DIALOG_LINEAR_GRAY_H
#define DIALOG_LINEAR_GRAY_H

#include <QDialog>
#include <QPixmap>
#include <QVector>

namespace Ui {
class LinearGrayDialog;
}

class LinearGrayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LinearGrayDialog(QWidget *parent = 0);
    ~LinearGrayDialog();

private:
    Ui::LinearGrayDialog *ui;

    void paintFunctionImage(double _a, double _b);

signals:
    void sendData(double a, double b);
private slots:
    void on_buttonBox_accepted();
    void on_aDoubleSpinBox_valueChanged(double arg1);
    void on_bDoubleSpinBox_valueChanged(double arg1);
};

#endif // DIALOG_LINEAR_GRAY_H
