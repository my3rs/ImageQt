#ifndef DIALOG_LINEAR_GRAY_H
#define DIALOG_LINEAR_GRAY_H

#include <QDialog>
#include <QPixmap>

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

signals:
    void sendData(double a, double b);
private slots:
    void on_buttonBox_accepted();
};

#endif // DIALOG_LINEAR_GRAY_H
