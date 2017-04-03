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
};

#endif // DIALOG_POWER_GREY_H
