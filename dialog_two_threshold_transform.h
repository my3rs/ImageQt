#ifndef DIALOG_THRESHOLD_TRANSFORM_H
#define DIALOG_THRESHOLD_TRANSFORM_H

#include <QDialog>

namespace Ui {
class DialogThresholdTransform;
}

class DialogThresholdTransform : public QDialog
{
    Q_OBJECT

public:
    explicit DialogThresholdTransform(QWidget *parent = 0);
    ~DialogThresholdTransform();

private:
    Ui::DialogThresholdTransform *ui;
};

#endif // DIALOG_THRESHOLD_TRANSFORM_H
