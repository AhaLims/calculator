/********************************************************************************
** Form generated from reading UI file 'choose.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSE_H
#define UI_CHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chooseClass
{
public:
    QPushButton *paint_button;
    QPushButton *poly_button;

    void setupUi(QWidget *chooseClass)
    {
        if (chooseClass->objectName().isEmpty())
            chooseClass->setObjectName(QStringLiteral("chooseClass"));
        chooseClass->resize(291, 388);
        chooseClass->setMinimumSize(QSize(291, 388));
        chooseClass->setMaximumSize(QSize(291, 388));
        paint_button = new QPushButton(chooseClass);
        paint_button->setObjectName(QStringLiteral("paint_button"));
        paint_button->setGeometry(QRect(90, 90, 121, 61));
        paint_button->setMinimumSize(QSize(121, 61));
        paint_button->setMaximumSize(QSize(121, 16777215));
        poly_button = new QPushButton(chooseClass);
        poly_button->setObjectName(QStringLiteral("poly_button"));
        poly_button->setGeometry(QRect(90, 180, 121, 61));

        retranslateUi(chooseClass);
        QObject::connect(paint_button, SIGNAL(clicked()), chooseClass, SLOT(push_2D_painter()));
        QObject::connect(poly_button, SIGNAL(clicked()), chooseClass, SLOT(push_poly()));

        QMetaObject::connectSlotsByName(chooseClass);
    } // setupUi

    void retranslateUi(QWidget *chooseClass)
    {
        chooseClass->setWindowTitle(QApplication::translate("chooseClass", "choose", nullptr));
        paint_button->setText(QApplication::translate("chooseClass", "2D\345\207\275\346\225\260\347\224\273\345\233\276\345\231\250", nullptr));
        poly_button->setText(QApplication::translate("chooseClass", "\345\244\232\351\241\271\345\274\217\350\247\243\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chooseClass: public Ui_chooseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSE_H
