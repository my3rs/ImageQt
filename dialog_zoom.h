#ifndef ZOOMDIALOG_H
#define ZOOMDIALOG_H

#include <QDialog>

namespace Ui {
class ZoomDialog;
}

class ZoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZoomDialog(QWidget *parent = 0);
    ~ZoomDialog();

private:
    Ui::ZoomDialog *ui;

signals:
    void sendData(int);

private slots:
    void on_buttonBox_accepted();
};

#endif // ZOOMDIALOG_H
