/********************************************************************************
** Form generated from reading UI file 'SicenticCaculator_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SICENTICCACULATOR_GUI_H
#define UI_SICENTICCACULATOR_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTextEdit *textEdit;
    QTextBrowser *ans;
    QPushButton *equalto;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *sub;
    QPushButton *multy;
    QPushButton *add;
    QPushButton *divide;
    QPushButton *power;
    QPushButton *histrory;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *save;
    QPushButton *read;
    QPushButton *pi;
    QPushButton *ln;
    QPushButton *sqrt;
    QPushButton *e;
    QPushButton *num1;
    QPushButton *num2;
    QPushButton *num3;
    QPushButton *num5;
    QPushButton *num4;
    QPushButton *num6;
    QPushButton *num7;
    QPushButton *num9;
    QPushButton *num8;
    QPushButton *sin;
    QPushButton *cos;
    QPushButton *tan;
    QPushButton *double_zero;
    QPushButton *zero;
    QPushButton *log;
    QPushButton *point;
    QPushButton *clear;
    QPushButton *left_bracket;
    QPushButton *right_bracket;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(1119, 911);
        textEdit = new QTextEdit(Form);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 20, 641, 81));
        ans = new QTextBrowser(Form);
        ans->setObjectName(QStringLiteral("ans"));
        ans->setGeometry(QRect(770, 20, 181, 81));
        equalto = new QPushButton(Form);
        equalto->setObjectName(QStringLiteral("equalto"));
        equalto->setGeometry(QRect(690, 60, 71, 41));
        gridLayoutWidget = new QWidget(Form);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(450, 160, 141, 205));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        sub = new QPushButton(gridLayoutWidget);
        sub->setObjectName(QStringLiteral("sub"));

        gridLayout->addWidget(sub, 3, 0, 1, 1);

        multy = new QPushButton(gridLayoutWidget);
        multy->setObjectName(QStringLiteral("multy"));

        gridLayout->addWidget(multy, 1, 0, 1, 1);

        add = new QPushButton(gridLayoutWidget);
        add->setObjectName(QStringLiteral("add"));

        gridLayout->addWidget(add, 0, 0, 1, 1);

        divide = new QPushButton(gridLayoutWidget);
        divide->setObjectName(QStringLiteral("divide"));

        gridLayout->addWidget(divide, 2, 0, 1, 1);

        power = new QPushButton(gridLayoutWidget);
        power->setObjectName(QStringLiteral("power"));

        gridLayout->addWidget(power, 4, 0, 1, 1);

        histrory = new QPushButton(gridLayoutWidget);
        histrory->setObjectName(QStringLiteral("histrory"));

        gridLayout->addWidget(histrory, 5, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(Form);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(60, 150, 371, 310));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        save = new QPushButton(gridLayoutWidget_2);
        save->setObjectName(QStringLiteral("save"));

        gridLayout_2->addWidget(save, 8, 1, 1, 1);

        read = new QPushButton(gridLayoutWidget_2);
        read->setObjectName(QStringLiteral("read"));

        gridLayout_2->addWidget(read, 8, 2, 1, 1);

        pi = new QPushButton(gridLayoutWidget_2);
        pi->setObjectName(QStringLiteral("pi"));

        gridLayout_2->addWidget(pi, 7, 1, 1, 1);

        ln = new QPushButton(gridLayoutWidget_2);
        ln->setObjectName(QStringLiteral("ln"));

        gridLayout_2->addWidget(ln, 6, 1, 1, 1);

        sqrt = new QPushButton(gridLayoutWidget_2);
        sqrt->setObjectName(QStringLiteral("sqrt"));

        gridLayout_2->addWidget(sqrt, 6, 2, 1, 1);

        e = new QPushButton(gridLayoutWidget_2);
        e->setObjectName(QStringLiteral("e"));

        gridLayout_2->addWidget(e, 7, 0, 1, 1);

        num1 = new QPushButton(gridLayoutWidget_2);
        num1->setObjectName(QStringLiteral("num1"));

        gridLayout_2->addWidget(num1, 0, 0, 1, 1);

        num2 = new QPushButton(gridLayoutWidget_2);
        num2->setObjectName(QStringLiteral("num2"));

        gridLayout_2->addWidget(num2, 0, 1, 1, 1);

        num3 = new QPushButton(gridLayoutWidget_2);
        num3->setObjectName(QStringLiteral("num3"));

        gridLayout_2->addWidget(num3, 0, 2, 1, 1);

        num5 = new QPushButton(gridLayoutWidget_2);
        num5->setObjectName(QStringLiteral("num5"));

        gridLayout_2->addWidget(num5, 1, 1, 1, 1);

        num4 = new QPushButton(gridLayoutWidget_2);
        num4->setObjectName(QStringLiteral("num4"));

        gridLayout_2->addWidget(num4, 1, 0, 1, 1);

        num6 = new QPushButton(gridLayoutWidget_2);
        num6->setObjectName(QStringLiteral("num6"));

        gridLayout_2->addWidget(num6, 1, 2, 1, 1);

        num7 = new QPushButton(gridLayoutWidget_2);
        num7->setObjectName(QStringLiteral("num7"));

        gridLayout_2->addWidget(num7, 2, 0, 1, 1);

        num9 = new QPushButton(gridLayoutWidget_2);
        num9->setObjectName(QStringLiteral("num9"));

        gridLayout_2->addWidget(num9, 2, 2, 1, 1);

        num8 = new QPushButton(gridLayoutWidget_2);
        num8->setObjectName(QStringLiteral("num8"));

        gridLayout_2->addWidget(num8, 2, 1, 1, 1);

        sin = new QPushButton(gridLayoutWidget_2);
        sin->setObjectName(QStringLiteral("sin"));

        gridLayout_2->addWidget(sin, 5, 2, 1, 1);

        cos = new QPushButton(gridLayoutWidget_2);
        cos->setObjectName(QStringLiteral("cos"));

        gridLayout_2->addWidget(cos, 5, 1, 1, 1);

        tan = new QPushButton(gridLayoutWidget_2);
        tan->setObjectName(QStringLiteral("tan"));

        gridLayout_2->addWidget(tan, 5, 0, 1, 1);

        double_zero = new QPushButton(gridLayoutWidget_2);
        double_zero->setObjectName(QStringLiteral("double_zero"));

        gridLayout_2->addWidget(double_zero, 3, 1, 1, 1);

        zero = new QPushButton(gridLayoutWidget_2);
        zero->setObjectName(QStringLiteral("zero"));

        gridLayout_2->addWidget(zero, 3, 0, 1, 1);

        log = new QPushButton(gridLayoutWidget_2);
        log->setObjectName(QStringLiteral("log"));

        gridLayout_2->addWidget(log, 6, 0, 1, 1);

        point = new QPushButton(gridLayoutWidget_2);
        point->setObjectName(QStringLiteral("point"));

        gridLayout_2->addWidget(point, 3, 2, 1, 1);

        clear = new QPushButton(gridLayoutWidget_2);
        clear->setObjectName(QStringLiteral("clear"));

        gridLayout_2->addWidget(clear, 8, 0, 1, 1);

        left_bracket = new QPushButton(gridLayoutWidget_2);
        left_bracket->setObjectName(QStringLiteral("left_bracket"));

        gridLayout_2->addWidget(left_bracket, 4, 0, 1, 1);

        right_bracket = new QPushButton(gridLayoutWidget_2);
        right_bracket->setObjectName(QStringLiteral("right_bracket"));

        gridLayout_2->addWidget(right_bracket, 4, 1, 1, 1);


        retranslateUi(Form);
        QObject::connect(num1, SIGNAL(clicked()), Form, SLOT(click_num1()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        equalto->setText(QApplication::translate("Form", "=", nullptr));
        sub->setText(QApplication::translate("Form", "-", nullptr));
        multy->setText(QApplication::translate("Form", "*", nullptr));
        add->setText(QApplication::translate("Form", "+", nullptr));
        divide->setText(QApplication::translate("Form", "/", nullptr));
        power->setText(QApplication::translate("Form", "^", nullptr));
        histrory->setText(QApplication::translate("Form", "\345\216\206\345\217\262\347\272\252\345\275\225", nullptr));
        save->setText(QApplication::translate("Form", "save", nullptr));
        read->setText(QApplication::translate("Form", "read", nullptr));
        pi->setText(QApplication::translate("Form", "pi", nullptr));
        ln->setText(QApplication::translate("Form", "ln(", nullptr));
        sqrt->setText(QApplication::translate("Form", "sqrt(", nullptr));
        e->setText(QApplication::translate("Form", "e", nullptr));
        num1->setText(QApplication::translate("Form", "1", nullptr));
        num2->setText(QApplication::translate("Form", "2", nullptr));
        num3->setText(QApplication::translate("Form", "3", nullptr));
        num5->setText(QApplication::translate("Form", "5", nullptr));
        num4->setText(QApplication::translate("Form", "4", nullptr));
        num6->setText(QApplication::translate("Form", "6", nullptr));
        num7->setText(QApplication::translate("Form", "7", nullptr));
        num9->setText(QApplication::translate("Form", "9", nullptr));
        num8->setText(QApplication::translate("Form", "8", nullptr));
        sin->setText(QApplication::translate("Form", "sin(", nullptr));
        cos->setText(QApplication::translate("Form", "cos(", nullptr));
        tan->setText(QApplication::translate("Form", "tan(", nullptr));
        double_zero->setText(QApplication::translate("Form", "00", nullptr));
        zero->setText(QApplication::translate("Form", "0", nullptr));
        log->setText(QApplication::translate("Form", "log(", nullptr));
        point->setText(QApplication::translate("Form", ".", nullptr));
        clear->setText(QApplication::translate("Form", "clear", nullptr));
        left_bracket->setText(QApplication::translate("Form", "(", nullptr));
        right_bracket->setText(QApplication::translate("Form", ")", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SICENTICCACULATOR_GUI_H
