#ifndef DIALOG_HISTOGRAM_H
#define DIALOG_HISTOGRAM_H

#include <QDialog>

namespace Ui {
class HistogramDialog;
}

class HistogramDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistogramDialog(QWidget *parent = 0);
    ~HistogramDialog();

private:
    Ui::HistogramDialog *ui;
};

#endif // DIALOG_HISTOGRAM_H
