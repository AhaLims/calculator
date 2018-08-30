/********************************************************************************
** Form generated from reading UI file 'Point24_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINT24_GUI_H
#define UI_POINT24_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Point24_guiClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *num1;
    QLineEdit *num2;
    QLineEdit *num3;
    QLineEdit *lineEdit_4;
    QPushButton *calculate;
    QPushButton *clear;
    QTextBrowser *textBrowser;
    QLabel *label_3;

    void setupUi(QWidget *Point24_guiClass)
    {
        if (Point24_guiClass->objectName().isEmpty())
            Point24_guiClass->setObjectName(QStringLiteral("Point24_guiClass"));
        Point24_guiClass->resize(945, 916);
        label = new QLabel(Point24_guiClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(390, 30, 141, 51));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label_2 = new QLabel(Point24_guiClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(350, 80, 251, 51));
        QFont font1;
        font1.setPointSize(10);
        label_2->setFont(font1);
        num1 = new QLineEdit(Point24_guiClass);
        num1->setObjectName(QStringLiteral("num1"));
        num1->setGeometry(QRect(120, 150, 113, 41));
        num2 = new QLineEdit(Point24_guiClass);
        num2->setObjectName(QStringLiteral("num2"));
        num2->setGeometry(QRect(260, 150, 113, 41));
        num3 = new QLineEdit(Point24_guiClass);
        num3->setObjectName(QStringLiteral("num3"));
        num3->setGeometry(QRect(400, 150, 113, 41));
        lineEdit_4 = new QLineEdit(Point24_guiClass);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(540, 150, 113, 41));
        calculate = new QPushButton(Point24_guiClass);
        calculate->setObjectName(QStringLiteral("calculate"));
        calculate->setGeometry(QRect(680, 150, 91, 41));
        clear = new QPushButton(Point24_guiClass);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(790, 150, 91, 41));
        textBrowser = new QTextBrowser(Point24_guiClass);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(120, 250, 761, 331));
        label_3 = new QLabel(Point24_guiClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 200, 141, 51));
        label_3->setFont(font1);

        retranslateUi(Point24_guiClass);
        QObject::connect(calculate, SIGNAL(clicked()), Point24_guiClass, SLOT(caculate_button()));
        QObject::connect(clear, SIGNAL(clicked()), Point24_guiClass, SLOT(clear()));

        QMetaObject::connectSlotsByName(Point24_guiClass);
    } // setupUi

    void retranslateUi(QWidget *Point24_guiClass)
    {
        Point24_guiClass->setWindowTitle(QApplication::translate("Point24_guiClass", "Point24_gui", nullptr));
        label->setText(QApplication::translate("Point24_guiClass", "<html><head/><body><p><span style=\" font-weight:600;\">24\347\202\271\350\256\241\347\256\227\345\231\250</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("Point24_guiClass", "\350\257\267\350\276\223\345\205\2454\344\270\252\346\255\243\346\225\264\346\225\260\357\274\210\350\214\203\345\233\264 1-13\357\274\211", nullptr));
        calculate->setText(QApplication::translate("Point24_guiClass", "\350\256\241\347\256\227", nullptr));
        clear->setText(QApplication::translate("Point24_guiClass", "\346\270\205\351\231\244", nullptr));
        label_3->setText(QApplication::translate("Point24_guiClass", "\347\273\223\346\236\234\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Point24_guiClass: public Ui_Point24_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINT24_GUI_H
