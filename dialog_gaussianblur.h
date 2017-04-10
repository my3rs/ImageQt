#ifndef GAUSSIANBLURDIALOG_H
#define GAUSSIANBLURDIALOG_H

#include <QDialog>

namespace Ui {
class GaussianBlurDialog;
}

class GaussianBlurDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GaussianBlurDialog(QWidget *parent = 0);
    ~GaussianBlurDialog();

private:
    Ui::GaussianBlurDialog *ui;

signals:
    void sendData(int, double);

private slots:
    void on_buttonBox_accepted();
};

#endif // GAUSSIANBLURDIALOG_H
