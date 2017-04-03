#include "dialog_threshold_transform.h"
#include "ui_dialog_threshold_transform.h"

DialogThresholdTransform::DialogThresholdTransform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogThresholdTransform)
{
    ui->setupUi(this);
}

DialogThresholdTransform::~DialogThresholdTransform()
{
    delete ui;
}
