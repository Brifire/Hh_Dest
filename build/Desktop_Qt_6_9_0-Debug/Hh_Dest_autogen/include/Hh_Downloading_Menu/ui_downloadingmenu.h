/********************************************************************************
** Form generated from reading UI file 'downloadingmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADINGMENU_H
#define UI_DOWNLOADINGMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownloadingMenu
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QSpinBox *spinBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *DownloadingMenu)
    {
        if (DownloadingMenu->objectName().isEmpty())
            DownloadingMenu->setObjectName("DownloadingMenu");
        DownloadingMenu->setWindowModality(Qt::WindowModality::ApplicationModal);
        DownloadingMenu->resize(839, 336);
        DownloadingMenu->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        DownloadingMenu->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(DownloadingMenu);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(DownloadingMenu);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("   height: 32px;\n"
"font: 800 12pt \"Ubuntu Sans\";\n"
"    background: #f8f9fa;\n"
"    font-size: 14px;\n"
"    color: #333;"));

        verticalLayout_2->addWidget(label);

        lcdNumber = new QLCDNumber(DownloadingMenu);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setDigitCount(5);
        lcdNumber->setProperty("value", QVariant(20.000000000000000));

        verticalLayout_2->addWidget(lcdNumber);

        spinBox = new QSpinBox(DownloadingMenu);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimum(20);
        spinBox->setMaximum(2000);
        spinBox->setSingleStep(20);
        spinBox->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        spinBox->setValue(20);
        spinBox->setDisplayIntegerBase(10);

        verticalLayout_2->addWidget(spinBox);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit = new QLineEdit(DownloadingMenu);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setFocusPolicy(Qt::FocusPolicy::WheelFocus);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 10px;\n"
"    padding-left: 30px; /* \320\277\321\200\320\276\321\201\321\202\321\200\320\260\320\275\321\201\321\202\320\262\320\276 \320\277\320\276\320\264 \320\270\320\272\320\276\320\275\320\272\321\203 */\n"
"    height: 32px;\n"
"    background: #f8f9fa;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #a0a0a0;\n"
"}"));

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(DownloadingMenu);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"   height: 32px;\n"
"    background: #f8f9fa;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(DownloadingMenu);

        QMetaObject::connectSlotsByName(DownloadingMenu);
    } // setupUi

    void retranslateUi(QWidget *DownloadingMenu)
    {
        DownloadingMenu->setWindowTitle(QCoreApplication::translate("DownloadingMenu", "Form", nullptr));
        label->setText(QCoreApplication::translate("DownloadingMenu", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\320\260\320\272\320\260\320\275\321\201\320\270\320\271 \320\277\320\276\320\270\321\201\320\272\320\260", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("DownloadingMenu", "\320\237\321\200\320\276\321\204\320\265\321\201\321\201\320\270\321\217 (\320\232 \320\277\321\200\320\270\320\274\320\265\321\200\321\203, \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270\321\201\321\202 \320\241++)", nullptr));
        pushButton->setText(QCoreApplication::translate("DownloadingMenu", "\320\237\320\276\320\270\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DownloadingMenu: public Ui_DownloadingMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADINGMENU_H
