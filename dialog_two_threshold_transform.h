#ifndef DIALOG_THRESHOLD_TRANSFORM_H
#define DIALOG_THRESHOLD_TRANSFORM_H

#include <QDialog>

namespace Ui {
class DialogThresholdTransform;
}

class DialogThresholdTransform : public QDialog
{
    Q_OBJECT

public:
    explicit DialogThresholdTransform(QWidget *parent = 0);
    ~DialogThresholdTransform();

private:
    Ui::DialogThresholdTransform *ui;

    void paintFunctionImage(int t1, int t2, int option);

signals:
    void sendData(int t1, int t2, int opt);

private slots:
    void on_buttonBox_accepted();
    void on_T1SpinBox_valueChanged(int arg1);
    void on_T2SpinBox_valueChanged(int arg1);
    void on_comboBox_currentIndexChanged(int index);
};

#endif // DIALOG_THRESHOLD_TRANSFORM_H
