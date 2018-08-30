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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *get_der;
    QPushButton *get_inter;
    QPushButton *get_zero;
    QLabel *label_3;
    QTextBrowser *textBrowser;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *get_dif_value;
    QLabel *label_4;
    QPushButton *get_zero_3;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *dif_value;
    QLineEdit *range1;
    QLineEdit *range2;
    QLabel *label_7;

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
        label_2 = new QLabel(poly_guiClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 150, 81, 21));
        spinBox = new QSpinBox(poly_guiClass);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(110, 150, 46, 22));
        get_der = new QPushButton(poly_guiClass);
        get_der->setObjectName(QStringLiteral("get_der"));
        get_der->setGeometry(QRect(100, 640, 101, 31));
        get_inter = new QPushButton(poly_guiClass);
        get_inter->setObjectName(QStringLiteral("get_inter"));
        get_inter->setGeometry(QRect(230, 640, 101, 31));
        get_zero = new QPushButton(poly_guiClass);
        get_zero->setObjectName(QStringLiteral("get_zero"));
        get_zero->setGeometry(QRect(350, 640, 201, 31));
        label_3 = new QLabel(poly_guiClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 190, 72, 31));
        label_3->setFont(font);
        textBrowser = new QTextBrowser(poly_guiClass);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(90, 690, 461, 192));
        horizontalLayoutWidget = new QWidget(poly_guiClass);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(100, 190, 801, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        get_dif_value = new QPushButton(poly_guiClass);
        get_dif_value->setObjectName(QStringLiteral("get_dif_value"));
        get_dif_value->setGeometry(QRect(570, 640, 121, 31));
        label_4 = new QLabel(poly_guiClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(580, 690, 72, 15));
        get_zero_3 = new QPushButton(poly_guiClass);
        get_zero_3->setObjectName(QStringLiteral("get_zero_3"));
        get_zero_3->setGeometry(QRect(730, 640, 111, 31));
        label_5 = new QLabel(poly_guiClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(720, 690, 41, 16));
        label_6 = new QLabel(poly_guiClass);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(830, 690, 21, 16));
        dif_value = new QLineEdit(poly_guiClass);
        dif_value->setObjectName(QStringLiteral("dif_value"));
        dif_value->setGeometry(QRect(630, 680, 61, 31));
        range1 = new QLineEdit(poly_guiClass);
        range1->setObjectName(QStringLiteral("range1"));
        range1->setGeometry(QRect(760, 680, 61, 31));
        range2 = new QLineEdit(poly_guiClass);
        range2->setObjectName(QStringLiteral("range2"));
        range2->setGeometry(QRect(850, 680, 61, 31));
        label_7 = new QLabel(poly_guiClass);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(170, 150, 381, 16));

        retranslateUi(poly_guiClass);
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), poly_guiClass, SLOT(change_time()));
        QObject::connect(get_der, SIGNAL(clicked()), poly_guiClass, SLOT(get_der()));
        QObject::connect(get_inter, SIGNAL(clicked()), poly_guiClass, SLOT(get_inter()));
        QObject::connect(get_zero, SIGNAL(clicked()), poly_guiClass, SLOT(get_zero()));
        QObject::connect(pushButton, SIGNAL(clicked()), poly_guiClass, SLOT(get_help()));
        QObject::connect(get_dif_value, SIGNAL(clicked()), poly_guiClass, SLOT(get_diff_value()));
        QObject::connect(get_zero_3, SIGNAL(clicked()), poly_guiClass, SLOT(get_inter_value()));

        QMetaObject::connectSlotsByName(poly_guiClass);
    } // setupUi

    void retranslateUi(QWidget *poly_guiClass)
    {
        poly_guiClass->setWindowTitle(QApplication::translate("poly_guiClass", "poly_gui", nullptr));
        pushButton->setText(QApplication::translate("poly_guiClass", "\345\270\256\345\212\251", nullptr));
        label->setText(QApplication::translate("poly_guiClass", "\345\244\232\351\241\271\345\274\217\347\233\270\345\205\263", nullptr));
        label_2->setText(QApplication::translate("poly_guiClass", "\346\234\200\351\253\230\347\263\273\346\225\260", nullptr));
        get_der->setText(QApplication::translate("poly_guiClass", "\346\261\202\345\257\274\346\225\260\350\247\243\346\236\220\345\274\217", nullptr));
        get_inter->setText(QApplication::translate("poly_guiClass", "\346\261\202\347\247\257\345\210\206\350\247\243\346\236\220\345\274\217", nullptr));
        get_zero->setText(QApplication::translate("poly_guiClass", "\346\261\202\346\211\200\346\234\211\347\232\204\351\233\266\347\202\271\357\274\210\345\256\236\346\225\260\350\214\203\345\233\264\345\206\205\357\274\211", nullptr));
        label_3->setText(QApplication::translate("poly_guiClass", "F(x) = ", nullptr));
        get_dif_value->setText(QApplication::translate("poly_guiClass", "\346\261\202\345\257\274\346\225\260\347\232\204\345\200\274", nullptr));
        label_4->setText(QApplication::translate("poly_guiClass", "\345\217\226 x = ", nullptr));
        get_zero_3->setText(QApplication::translate("poly_guiClass", "\346\261\202\345\256\232\347\247\257\345\210\206", nullptr));
        label_5->setText(QApplication::translate("poly_guiClass", "\350\214\203\345\233\264", nullptr));
        label_6->setText(QApplication::translate("poly_guiClass", "\345\210\260", nullptr));
        label_7->setText(QApplication::translate("poly_guiClass", "\350\257\267\350\276\223\345\205\245\346\225\260\345\255\227\346\210\226\350\241\250\350\276\276\345\274\217\357\274\214\346\263\250\346\204\217\350\241\250\350\276\276\345\274\217\344\271\213\351\227\264\347\232\204\347\254\246\345\217\267\344\270\215\350\203\275\347\234\201\347\225\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class poly_guiClass: public Ui_poly_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLY_GUI_H
