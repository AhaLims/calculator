/********************************************************************************
** Form generated from reading UI file 'poly_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLY_GUI_H
#define UI_POLY_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_poly_guiClass
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_3;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *poly_guiClass)
    {
        if (poly_guiClass->objectName().isEmpty())
            poly_guiClass->setObjectName(QStringLiteral("poly_guiClass"));
        poly_guiClass->resize(1076, 910);
        pushButton = new QPushButton(poly_guiClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 90, 93, 28));
        label = new QLabel(poly_guiClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(430, 40, 141, 31));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        pushButton_2 = new QPushButton(poly_guiClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 190, 941, 441));
        label_2 = new QLabel(poly_guiClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 150, 81, 21));
        spinBox = new QSpinBox(poly_guiClass);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(110, 150, 46, 22));
        pushButton_3 = new QPushButton(poly_guiClass);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(100, 640, 101, 31));
        pushButton_4 = new QPushButton(poly_guiClass);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(230, 640, 101, 31));
        pushButton_5 = new QPushButton(poly_guiClass);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(350, 640, 201, 31));
        label_3 = new QLabel(poly_guiClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 190, 72, 31));
        label_3->setFont(font);
        textBrowser = new QTextBrowser(poly_guiClass);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(90, 690, 491, 192));

        retranslateUi(poly_guiClass);

        QMetaObject::connectSlotsByName(poly_guiClass);
    } // setupUi

    void retranslateUi(QWidget *poly_guiClass)
    {
        poly_guiClass->setWindowTitle(QApplication::translate("poly_guiClass", "poly_gui", nullptr));
        pushButton->setText(QApplication::translate("poly_guiClass", "\345\270\256\345\212\251", nullptr));
        label->setText(QApplication::translate("poly_guiClass", "\345\244\232\351\241\271\345\274\217\347\233\270\345\205\263", nullptr));
        pushButton_2->setText(QApplication::translate("poly_guiClass", "\344\275\215\347\275\256\357\274\232\357\274\21080\357\274\214140\357\274\211\345\256\275\345\272\246\357\274\232941 \351\225\277\345\272\246\357\274\210441\357\274\211\345\217\257\344\273\245\351\200\211\346\213\2515\344\270\252\344\270\200\350\241\214", nullptr));
        label_2->setText(QApplication::translate("poly_guiClass", "\346\234\200\351\253\230\347\263\273\346\225\260", nullptr));
        pushButton_3->setText(QApplication::translate("poly_guiClass", "\346\261\202\345\257\274\346\225\260\350\247\243\346\236\220\345\274\217", nullptr));
        pushButton_4->setText(QApplication::translate("poly_guiClass", "\346\261\202\347\247\257\345\210\206\350\247\243\346\236\220\345\274\217", nullptr));
        pushButton_5->setText(QApplication::translate("poly_guiClass", "\346\261\202\346\211\200\346\234\211\347\232\204\351\233\266\347\202\271\357\274\210\345\256\236\346\225\260\350\214\203\345\233\264\345\206\205\357\274\211", nullptr));
        label_3->setText(QApplication::translate("poly_guiClass", "F(x) = ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class poly_guiClass: public Ui_poly_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLY_GUI_H
