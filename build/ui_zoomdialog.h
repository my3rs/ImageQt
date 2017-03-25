/********************************************************************************
** Form generated from reading UI file 'zoomdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZOOMDIALOG_H
#define UI_ZOOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZoomDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *zoomFactorSpinBox;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ZoomDialog)
    {
        if (ZoomDialog->objectName().isEmpty())
            ZoomDialog->setObjectName(QStringLiteral("ZoomDialog"));
        ZoomDialog->resize(337, 123);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ZoomDialog->sizePolicy().hasHeightForWidth());
        ZoomDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/src/edit-find.png"), QSize(), QIcon::Normal, QIcon::Off);
        ZoomDialog->setWindowIcon(icon);
        layoutWidget = new QWidget(ZoomDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 20, 264, 80));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        zoomFactorSpinBox = new QSpinBox(layoutWidget);
        zoomFactorSpinBox->setObjectName(QStringLiteral("zoomFactorSpinBox"));
        zoomFactorSpinBox->setMinimum(-500);
        zoomFactorSpinBox->setMaximum(500);
        zoomFactorSpinBox->setSingleStep(10);
        zoomFactorSpinBox->setValue(100);

        verticalLayout->addWidget(zoomFactorSpinBox);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(ZoomDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ZoomDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ZoomDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ZoomDialog);
    } // setupUi

    void retranslateUi(QDialog *ZoomDialog)
    {
        ZoomDialog->setWindowTitle(QApplication::translate("ZoomDialog", "\345\233\276\345\203\217\347\274\251\346\224\276 - ImageQt", Q_NULLPTR));
        label->setText(QApplication::translate("ZoomDialog", "\350\257\267\350\276\223\345\205\245\347\274\251\346\224\276\345\200\215\347\216\207(%)\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ZoomDialog: public Ui_ZoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZOOMDIALOG_H
