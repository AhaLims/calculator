/********************************************************************************
** Form generated from reading UI file 'LinearEquation_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEAREQUATION_GUI_H
#define UI_LINEAREQUATION_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LinearEquation_guiClass
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *HL;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *get_answer;
    QTextBrowser *answer_show;

    void setupUi(QWidget *LinearEquation_guiClass)
    {
        if (LinearEquation_guiClass->objectName().isEmpty())
            LinearEquation_guiClass->setObjectName(QStringLiteral("LinearEquation_guiClass"));
        LinearEquation_guiClass->resize(1161, 967);
        label = new QLabel(LinearEquation_guiClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 321, 61));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        verticalLayoutWidget = new QWidget(LinearEquation_guiClass);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 140, 731, 731));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget = new QWidget(LinearEquation_guiClass);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 60, 350, 80));
        HL = new QHBoxLayout(horizontalLayoutWidget);
        HL->setSpacing(6);
        HL->setContentsMargins(11, 11, 11, 11);
        HL->setObjectName(QStringLiteral("HL"));
        HL->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        HL->addWidget(label_2);

        spinBox = new QSpinBox(horizontalLayoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setFont(font);

        HL->addWidget(spinBox);

        get_answer = new QPushButton(LinearEquation_guiClass);
        get_answer->setObjectName(QStringLiteral("get_answer"));
        get_answer->setGeometry(QRect(400, 80, 93, 28));
        answer_show = new QTextBrowser(LinearEquation_guiClass);
        answer_show->setObjectName(QStringLiteral("answer_show"));
        answer_show->setGeometry(QRect(850, 140, 256, 731));

        retranslateUi(LinearEquation_guiClass);
        QObject::connect(get_answer, SIGNAL(clicked()), LinearEquation_guiClass, SLOT(push_get_answer_button()));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), LinearEquation_guiClass, SLOT(change_equation()));

        QMetaObject::connectSlotsByName(LinearEquation_guiClass);
    } // setupUi

    void retranslateUi(QWidget *LinearEquation_guiClass)
    {
        LinearEquation_guiClass->setWindowTitle(QApplication::translate("LinearEquation_guiClass", "LinearEquation_gui", nullptr));
        label->setText(QApplication::translate("LinearEquation_guiClass", "\345\234\250\346\234\254\347\225\214\351\235\242,\344\275\240\345\217\257\344\273\245\346\261\202\350\247\243\347\272\277\346\200\247\346\226\271\347\250\213\347\273\204", nullptr));
        label_2->setText(QApplication::translate("LinearEquation_guiClass", "\346\234\252\347\237\245\346\225\260\357\274\210\344\270\273\345\205\203\357\274\211\344\270\252\346\225\260\357\274\2102-9\357\274\211", nullptr));
        get_answer->setText(QApplication::translate("LinearEquation_guiClass", "\346\261\202\350\247\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LinearEquation_guiClass: public Ui_LinearEquation_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEAREQUATION_GUI_H
