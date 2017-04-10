#include "dialog_gaussianblur.h"
#include "ui_gaussianblurdialog.h"

GaussianBlurDialog::GaussianBlurDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GaussianBlurDialog)
{
    ui->setupUi(this);
}

GaussianBlurDialog::~GaussianBlurDialog()
{
    delete ui;
}

void GaussianBlurDialog::on_buttonBox_accepted()
{
    emit sendData(ui->radiusSpinBox->value(), ui->sigmaSpinBox->value());
}

