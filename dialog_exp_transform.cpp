#include "dialog_exp_transform.h"
#include "ui_dialog_exp_transform.h"

DialogExpTransform::DialogExpTransform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogExpTransform)
{
    ui->setupUi(this);
}

DialogExpTransform::~DialogExpTransform()
{
    delete ui;
}
