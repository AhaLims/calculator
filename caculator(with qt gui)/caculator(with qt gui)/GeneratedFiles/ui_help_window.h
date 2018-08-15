/********************************************************************************
** Form generated from reading UI file 'help_window.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_WINDOW_H
#define UI_HELP_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_help_windowClass
{
public:
    QPushButton *help_button;
    QPushButton *about_button;
    QLabel *help_label;
    QLabel *about_label;

    void setupUi(QWidget *help_windowClass)
    {
        if (help_windowClass->objectName().isEmpty())
            help_windowClass->setObjectName(QStringLiteral("help_windowClass"));
        help_windowClass->resize(951, 857);
        help_windowClass->setStyleSheet(QStringLiteral("#help_window-help_window{background-image: url(:/caculator_gui/picture/background.jpg);}"));
        help_button = new QPushButton(help_windowClass);
        help_button->setObjectName(QStringLiteral("help_button"));
        help_button->setGeometry(QRect(80, 70, 101, 61));
        about_button = new QPushButton(help_windowClass);
        about_button->setObjectName(QStringLiteral("about_button"));
        about_button->setGeometry(QRect(80, 160, 101, 61));
        help_label = new QLabel(help_windowClass);
        help_label->setObjectName(QStringLiteral("help_label"));
        help_label->setGeometry(QRect(280, 90, 72, 15));
        about_label = new QLabel(help_windowClass);
        about_label->setObjectName(QStringLiteral("about_label"));
        about_label->setGeometry(QRect(240, 150, 401, 91));

        retranslateUi(help_windowClass);

        QMetaObject::connectSlotsByName(help_windowClass);
    } // setupUi

    void retranslateUi(QWidget *help_windowClass)
    {
        help_windowClass->setWindowTitle(QApplication::translate("help_windowClass", "help_window", nullptr));
        help_button->setText(QApplication::translate("help_windowClass", "\345\270\256\345\212\251", nullptr));
        about_button->setText(QApplication::translate("help_windowClass", "\345\205\263\344\272\216", nullptr));
        help_label->setText(QApplication::translate("help_windowClass", "<html><head/><body><p>\345\270\256\345\212\251</p></body></html>", nullptr));
        about_label->setText(QApplication::translate("help_windowClass", "<html><head/><body><p>\344\275\234\350\200\205\357\274\232AhaLims</p><p>\346\272\220\344\273\243\347\240\201\345\234\260\345\235\200\357\274\232<a href=\"https://gitee.com/AhaLims/caculator\"><span style=\" text-decoration: underline; color:#0000ff;\">https://gitee.com/AhaLims/caculator</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class help_windowClass: public Ui_help_windowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_WINDOW_H
