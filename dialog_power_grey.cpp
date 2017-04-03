#include "dialog_power_grey.h"
#include "ui_dialog_power_grey.h"

DialogPowerGrey::DialogPowerGrey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPowerGrey)
{
    ui->setupUi(this);
}

DialogPowerGrey::~DialogPowerGrey()
{
    delete ui;
}
