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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QPushButton *ln;
    QPushButton *num8;
    QPushButton *num6;
    QPushButton *sqrt;
    QPushButton *cos;
    QPushButton *double_zero;
    QPushButton *tan;
    QPushButton *num5;
    QPushButton *num4;
    QPushButton *sin;
    QPushButton *num1;
    QPushButton *right_bracket;
    QPushButton *num3;
    QPushButton *zero;
    QPushButton *clear;
    QPushButton *e;
    QPushButton *point;
    QPushButton *pi;
    QPushButton *num9;
    QPushButton *num7;
    QPushButton *log;
    QPushButton *num2;
    QPushButton *left_bracket;
    QPushButton *arctan;
    QPushButton *arccos;
    QPushButton *arcsin;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(1104, 911);
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
        gridLayoutWidget->setGeometry(QRect(450, 150, 141, 205));
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
        gridLayoutWidget_2->setGeometry(QRect(60, 150, 371, 345));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        save = new QPushButton(gridLayoutWidget_2);
        save->setObjectName(QStringLiteral("save"));

        gridLayout_2->addWidget(save, 9, 1, 1, 1);

        read = new QPushButton(gridLayoutWidget_2);
        read->setObjectName(QStringLiteral("read"));

        gridLayout_2->addWidget(read, 9, 2, 1, 1);

        ln = new QPushButton(gridLayoutWidget_2);
        ln->setObjectName(QStringLiteral("ln"));

        gridLayout_2->addWidget(ln, 7, 1, 1, 1);

        num8 = new QPushButton(gridLayoutWidget_2);
        num8->setObjectName(QStringLiteral("num8"));

        gridLayout_2->addWidget(num8, 2, 1, 1, 1);

        num6 = new QPushButton(gridLayoutWidget_2);
        num6->setObjectName(QStringLiteral("num6"));

        gridLayout_2->addWidget(num6, 1, 2, 1, 1);

        sqrt = new QPushButton(gridLayoutWidget_2);
        sqrt->setObjectName(QStringLiteral("sqrt"));

        gridLayout_2->addWidget(sqrt, 7, 2, 1, 1);

        cos = new QPushButton(gridLayoutWidget_2);
        cos->setObjectName(QStringLiteral("cos"));

        gridLayout_2->addWidget(cos, 5, 1, 1, 1);

        double_zero = new QPushButton(gridLayoutWidget_2);
        double_zero->setObjectName(QStringLiteral("double_zero"));

        gridLayout_2->addWidget(double_zero, 3, 1, 1, 1);

        tan = new QPushButton(gridLayoutWidget_2);
        tan->setObjectName(QStringLiteral("tan"));

        gridLayout_2->addWidget(tan, 5, 0, 1, 1);

        num5 = new QPushButton(gridLayoutWidget_2);
        num5->setObjectName(QStringLiteral("num5"));

        gridLayout_2->addWidget(num5, 1, 1, 1, 1);

        num4 = new QPushButton(gridLayoutWidget_2);
        num4->setObjectName(QStringLiteral("num4"));

        gridLayout_2->addWidget(num4, 1, 0, 1, 1);

        sin = new QPushButton(gridLayoutWidget_2);
        sin->setObjectName(QStringLiteral("sin"));

        gridLayout_2->addWidget(sin, 5, 2, 1, 1);

        num1 = new QPushButton(gridLayoutWidget_2);
        num1->setObjectName(QStringLiteral("num1"));

        gridLayout_2->addWidget(num1, 0, 0, 1, 1);

        right_bracket = new QPushButton(gridLayoutWidget_2);
        right_bracket->setObjectName(QStringLiteral("right_bracket"));

        gridLayout_2->addWidget(right_bracket, 4, 1, 1, 1);

        num3 = new QPushButton(gridLayoutWidget_2);
        num3->setObjectName(QStringLiteral("num3"));

        gridLayout_2->addWidget(num3, 0, 2, 1, 1);

        zero = new QPushButton(gridLayoutWidget_2);
        zero->setObjectName(QStringLiteral("zero"));

        gridLayout_2->addWidget(zero, 3, 0, 1, 1);

        clear = new QPushButton(gridLayoutWidget_2);
        clear->setObjectName(QStringLiteral("clear"));

        gridLayout_2->addWidget(clear, 9, 0, 1, 1);

        e = new QPushButton(gridLayoutWidget_2);
        e->setObjectName(QStringLiteral("e"));

        gridLayout_2->addWidget(e, 8, 0, 1, 1);

        point = new QPushButton(gridLayoutWidget_2);
        point->setObjectName(QStringLiteral("point"));

        gridLayout_2->addWidget(point, 3, 2, 1, 1);

        pi = new QPushButton(gridLayoutWidget_2);
        pi->setObjectName(QStringLiteral("pi"));

        gridLayout_2->addWidget(pi, 8, 1, 1, 1);

        num9 = new QPushButton(gridLayoutWidget_2);
        num9->setObjectName(QStringLiteral("num9"));

        gridLayout_2->addWidget(num9, 2, 2, 1, 1);

        num7 = new QPushButton(gridLayoutWidget_2);
        num7->setObjectName(QStringLiteral("num7"));

        gridLayout_2->addWidget(num7, 2, 0, 1, 1);

        log = new QPushButton(gridLayoutWidget_2);
        log->setObjectName(QStringLiteral("log"));

        gridLayout_2->addWidget(log, 7, 0, 1, 1);

        num2 = new QPushButton(gridLayoutWidget_2);
        num2->setObjectName(QStringLiteral("num2"));

        gridLayout_2->addWidget(num2, 0, 1, 1, 1);

        left_bracket = new QPushButton(gridLayoutWidget_2);
        left_bracket->setObjectName(QStringLiteral("left_bracket"));

        gridLayout_2->addWidget(left_bracket, 4, 0, 1, 1);

        arctan = new QPushButton(gridLayoutWidget_2);
        arctan->setObjectName(QStringLiteral("arctan"));

        gridLayout_2->addWidget(arctan, 6, 0, 1, 1);

        arccos = new QPushButton(gridLayoutWidget_2);
        arccos->setObjectName(QStringLiteral("arccos"));

        gridLayout_2->addWidget(arccos, 6, 1, 1, 1);

        arcsin = new QPushButton(gridLayoutWidget_2);
        arcsin->setObjectName(QStringLiteral("arcsin"));

        gridLayout_2->addWidget(arcsin, 6, 2, 1, 1);

        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(630, 180, 251, 91));
        spinBox = new QSpinBox(Form);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(670, 150, 46, 22));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(610, 150, 61, 21));

        retranslateUi(Form);
        QObject::connect(num1, SIGNAL(clicked()), Form, SLOT(click_num1()));
        QObject::connect(num2, SIGNAL(clicked()), Form, SLOT(click_num2()));
        QObject::connect(num3, SIGNAL(clicked()), Form, SLOT(click_num3()));
        QObject::connect(num4, SIGNAL(clicked()), Form, SLOT(click_num4()));
        QObject::connect(num5, SIGNAL(clicked()), Form, SLOT(click_num5()));
        QObject::connect(num6, SIGNAL(clicked()), Form, SLOT(click_num6()));
        QObject::connect(num7, SIGNAL(clicked()), Form, SLOT(click_num7()));
        QObject::connect(num8, SIGNAL(clicked()), Form, SLOT(click_num8()));
        QObject::connect(num9, SIGNAL(clicked()), Form, SLOT(click_num9()));
        QObject::connect(zero, SIGNAL(clicked()), Form, SLOT(click_num0()));
        QObject::connect(double_zero, SIGNAL(clicked()), Form, SLOT(click_num00()));
        QObject::connect(point, SIGNAL(clicked()), Form, SLOT(click_point()));
        QObject::connect(left_bracket, SIGNAL(clicked()), Form, SLOT(click_left_bracket()));
        QObject::connect(right_bracket, SIGNAL(clicked()), Form, SLOT(click_right_bracket()));
        QObject::connect(tan, SIGNAL(clicked()), Form, SLOT(click_tan()));
        QObject::connect(cos, SIGNAL(clicked()), Form, SLOT(click_cos()));
        QObject::connect(sin, SIGNAL(clicked()), Form, SLOT(click_sin()));
        QObject::connect(log, SIGNAL(clicked()), Form, SLOT(click_log()));
        QObject::connect(ln, SIGNAL(clicked()), Form, SLOT(click_ln()));
        QObject::connect(sqrt, SIGNAL(clicked()), Form, SLOT(click_sqrt()));
        QObject::connect(e, SIGNAL(clicked()), Form, SLOT(click_e()));
        QObject::connect(pi, SIGNAL(clicked()), Form, SLOT(click_pi()));
        QObject::connect(clear, SIGNAL(clicked()), Form, SLOT(click_clear()));
        QObject::connect(save, SIGNAL(clicked()), Form, SLOT(click_save()));
        QObject::connect(read, SIGNAL(clicked()), Form, SLOT(click_read()));
        QObject::connect(add, SIGNAL(clicked()), Form, SLOT(click_add()));
        QObject::connect(multy, SIGNAL(clicked()), Form, SLOT(click_multy()));
        QObject::connect(divide, SIGNAL(clicked()), Form, SLOT(click_divide()));
        QObject::connect(sub, SIGNAL(clicked()), Form, SLOT(click_sub()));
        QObject::connect(power, SIGNAL(clicked()), Form, SLOT(click_power()));
        QObject::connect(histrory, SIGNAL(clicked()), Form, SLOT(click_history()));
        QObject::connect(arctan, SIGNAL(clicked()), Form, SLOT(click_arctan()));
        QObject::connect(arccos, SIGNAL(clicked()), Form, SLOT(click_arccos()));
        QObject::connect(arcsin, SIGNAL(clicked()), Form, SLOT(click_arcsin()));
        QObject::connect(equalto, SIGNAL(clicked()), Form, SLOT(click_ans()));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), Form, SLOT(change_digits()));

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
        ln->setText(QApplication::translate("Form", "ln(", nullptr));
        num8->setText(QApplication::translate("Form", "8", nullptr));
        num6->setText(QApplication::translate("Form", "6", nullptr));
        sqrt->setText(QApplication::translate("Form", "sqrt(", nullptr));
        cos->setText(QApplication::translate("Form", "cos(", nullptr));
        double_zero->setText(QApplication::translate("Form", "00", nullptr));
        tan->setText(QApplication::translate("Form", "tan(", nullptr));
        num5->setText(QApplication::translate("Form", "5", nullptr));
        num4->setText(QApplication::translate("Form", "4", nullptr));
        sin->setText(QApplication::translate("Form", "sin(", nullptr));
        num1->setText(QApplication::translate("Form", "1", nullptr));
        right_bracket->setText(QApplication::translate("Form", ")", nullptr));
        num3->setText(QApplication::translate("Form", "3", nullptr));
        zero->setText(QApplication::translate("Form", "0", nullptr));
        clear->setText(QApplication::translate("Form", "clear", nullptr));
        e->setText(QApplication::translate("Form", "e", nullptr));
        point->setText(QApplication::translate("Form", ".", nullptr));
        pi->setText(QApplication::translate("Form", "pi", nullptr));
        num9->setText(QApplication::translate("Form", "9", nullptr));
        num7->setText(QApplication::translate("Form", "7", nullptr));
        log->setText(QApplication::translate("Form", "log(", nullptr));
        num2->setText(QApplication::translate("Form", "2", nullptr));
        left_bracket->setText(QApplication::translate("Form", "(", nullptr));
        arctan->setText(QApplication::translate("Form", "arctan(", nullptr));
        arccos->setText(QApplication::translate("Form", "arccos(", nullptr));
        arcsin->setText(QApplication::translate("Form", "arcsin(", nullptr));
        label->setText(QApplication::translate("Form", "<html><head/><body><p>tips:</p><p>\346\213\254\345\217\267\345\277\205\351\241\273\344\270\272<span style=\" text-decoration: underline; color:#ff0000;\">\350\213\261\346\226\207\350\276\223\345\205\245\346\263\225</span>\344\270\213\347\232\204\346\213\254\345\217\267</p><p>\344\270\215\350\203\275\347\234\201\347\225\245\347\254\246\345\217\267<br/></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("Form", "\345\260\217\346\225\260\344\275\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SICENTICCACULATOR_GUI_H
