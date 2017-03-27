#ifndef DIALOG_BRIGHTNESS_H
#define DIALOG_BRIGHTNESS_H

#include <QDialog>

namespace Ui {
class BrightnessDialog;
}

class BrightnessDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BrightnessDialog(QWidget *parent = 0);
    ~BrightnessDialog();

private:
    Ui::BrightnessDialog *ui;
};

#endif // DIALOG_BRIGHTNESS_H
