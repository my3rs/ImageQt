#include "dialog_brightness.h"
#include "ui_dialog_brightness.h"

BrightnessDialog::BrightnessDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrightnessDialog)
{
    ui->setupUi(this);
}

BrightnessDialog::~BrightnessDialog()
{
    delete ui;
}

void BrightnessDialog::on_buttonBox_accepted()
{
    emit sendData(ui->spinBox->value());
}
