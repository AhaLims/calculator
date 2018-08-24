/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_windowClass
{
public:
    QWidget *centralWidget;
    QPushButton *function_caculator_button;
    QPushButton *help_function;
    QPushButton *exit_button;
    QPushButton *scientic_caculator_button;
    QPushButton *matrix_caculator_button;
    QPushButton *linear_fucntion;

    void setupUi(QMainWindow *main_windowClass)
    {
        if (main_windowClass->objectName().isEmpty())
            main_windowClass->setObjectName(QStringLiteral("main_windowClass"));
        main_windowClass->resize(1000, 800);
        main_windowClass->setStyleSheet(QStringLiteral("background-image: url(:/caculator_gui/picture/background.jpg)"));
        centralWidget = new QWidget(main_windowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        function_caculator_button = new QPushButton(centralWidget);
        function_caculator_button->setObjectName(QStringLiteral("function_caculator_button"));
        function_caculator_button->setEnabled(true);
        function_caculator_button->setGeometry(QRect(390, 310, 170, 80));
        function_caculator_button->setStyleSheet(QStringLiteral("background-image: url(:/caculator_gui/picture/white.png)"));
        help_function = new QPushButton(centralWidget);
        help_function->setObjectName(QStringLiteral("help_function"));
        help_function->setEnabled(true);
        help_function->setGeometry(QRect(390, 510, 170, 80));
        help_function->setStyleSheet(QStringLiteral("background-image: url(:/caculator_gui/picture/white.png)"));
        exit_button = new QPushButton(centralWidget);
        exit_button->setObjectName(QStringLiteral("exit_button"));
        exit_button->setEnabled(true);
        exit_button->setGeometry(QRect(390, 610, 170, 80));
        exit_button->setStyleSheet(QStringLiteral("background-image: url(:/caculator_gui/picture/white.png)"));
        scientic_caculator_button = new QPushButton(centralWidget);
        scientic_caculator_button->setObjectName(QStringLiteral("scientic_caculator_button"));
        scientic_caculator_button->setEnabled(true);
        scientic_caculator_button->setGeometry(QRect(390, 210, 170, 80));
        scientic_caculator_button->setStyleSheet(QStringLiteral("background-image: url(:/caculator_gui/picture/white.png)"));
        matrix_caculator_button = new QPushButton(centralWidget);
        matrix_caculator_button->setObjectName(QStringLiteral("matrix_caculator_button"));
        matrix_caculator_button->setEnabled(true);
        matrix_caculator_button->setGeometry(QRect(390, 110, 170, 80));
        matrix_caculator_button->setStyleSheet(QStringLiteral("background-image: url(:/caculator_gui/picture/white.png)"));
        linear_fucntion = new QPushButton(centralWidget);
        linear_fucntion->setObjectName(QStringLiteral("linear_fucntion"));
        linear_fucntion->setEnabled(true);
        linear_fucntion->setGeometry(QRect(390, 410, 170, 80));
        linear_fucntion->setStyleSheet(QStringLiteral("background-image: url(:/caculator_gui/picture/white.png)"));
        main_windowClass->setCentralWidget(centralWidget);

        retranslateUi(main_windowClass);
        QObject::connect(exit_button, SIGNAL(clicked()), main_windowClass, SLOT(close()));
        QObject::connect(matrix_caculator_button, SIGNAL(clicked()), main_windowClass, SLOT(push_matrix_caculator_button()));
        QObject::connect(scientic_caculator_button, SIGNAL(clicked()), main_windowClass, SLOT(push_scientic_caculator_button()));
        QObject::connect(function_caculator_button, SIGNAL(clicked()), main_windowClass, SLOT(push_function_caculator_button()));
        QObject::connect(help_function, SIGNAL(clicked()), main_windowClass, SLOT(push_help_button()));
        QObject::connect(linear_fucntion, SIGNAL(clicked()), main_windowClass, SLOT(push_linear_equation_button()));

        QMetaObject::connectSlotsByName(main_windowClass);
    } // setupUi

    void retranslateUi(QMainWindow *main_windowClass)
    {
        main_windowClass->setWindowTitle(QApplication::translate("main_windowClass", "main_window", nullptr));
        function_caculator_button->setText(QApplication::translate("main_windowClass", "\345\207\275\346\225\260\350\256\241\347\256\227\345\231\250", nullptr));
        help_function->setText(QApplication::translate("main_windowClass", "\345\205\263\344\272\216", nullptr));
        exit_button->setText(QApplication::translate("main_windowClass", "\351\200\200\345\207\272", nullptr));
        scientic_caculator_button->setText(QApplication::translate("main_windowClass", "\347\247\221\345\255\246\350\256\241\347\256\227\345\231\250", nullptr));
        matrix_caculator_button->setText(QApplication::translate("main_windowClass", "\347\237\251\351\230\265\350\256\241\347\256\227\345\231\250", nullptr));
        linear_fucntion->setText(QApplication::translate("main_windowClass", "\350\247\243\347\272\277\346\200\247\346\226\271\347\250\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_windowClass: public Ui_main_windowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
