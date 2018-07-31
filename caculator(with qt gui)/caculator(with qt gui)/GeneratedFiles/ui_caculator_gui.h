/********************************************************************************
** Form generated from reading UI file 'caculator_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CACULATOR_GUI_H
#define UI_CACULATOR_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_caculator_guiClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *MatrixB;
    QVBoxLayout *verticalLayout;
    QPushButton *add;
    QPushButton *sub;
    QPushButton *multiply;
    QPushButton *exchange;
    QTextEdit *MatrixA;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayoutA;
    QPushButton *invA;
    QPushButton *detA;
    QPushButton *charactorVectorA;
    QPushButton *simplestA;
    QPushButton *tranA;
    QPushButton *trA;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *timeA;
    QLineEdit *lineEdit_TimeA;
    QPushButton *charactorValueA;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *mulityNumA;
    QLineEdit *lineEdit_NumA;
    QPushButton *randomA;
    QPushButton *clearA;
    QGridLayout *gridLayoutA_2;
    QPushButton *detB;
    QPushButton *invB;
    QPushButton *clearB;
    QPushButton *charactorValueB;
    QPushButton *tranB;
    QPushButton *trB;
    QPushButton *simplestB;
    QPushButton *charactorVectorB;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *timeB;
    QLineEdit *lineEdit_TimeB;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *mulityNumB;
    QLineEdit *lineEdit_NumB;
    QPushButton *randomB;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QLineEdit *expression;
    QPushButton *expression_equal;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *caculator_guiClass)
    {
        if (caculator_guiClass->objectName().isEmpty())
            caculator_guiClass->setObjectName(QStringLiteral("caculator_guiClass"));
        caculator_guiClass->resize(1266, 943);
        centralWidget = new QWidget(caculator_guiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(280, 60, 951, 371));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        MatrixB = new QTextEdit(horizontalLayoutWidget);
        MatrixB->setObjectName(QStringLiteral("MatrixB"));

        horizontalLayout->addWidget(MatrixB);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        add = new QPushButton(horizontalLayoutWidget);
        add->setObjectName(QStringLiteral("add"));

        verticalLayout->addWidget(add);

        sub = new QPushButton(horizontalLayoutWidget);
        sub->setObjectName(QStringLiteral("sub"));

        verticalLayout->addWidget(sub);

        multiply = new QPushButton(horizontalLayoutWidget);
        multiply->setObjectName(QStringLiteral("multiply"));

        verticalLayout->addWidget(multiply);

        exchange = new QPushButton(horizontalLayoutWidget);
        exchange->setObjectName(QStringLiteral("exchange"));

        verticalLayout->addWidget(exchange);


        horizontalLayout->addLayout(verticalLayout);

        MatrixA = new QTextEdit(horizontalLayoutWidget);
        MatrixA->setObjectName(QStringLiteral("MatrixA"));

        horizontalLayout->addWidget(MatrixA);

        horizontalLayoutWidget_6 = new QWidget(centralWidget);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(270, 480, 961, 209));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayoutA = new QGridLayout();
        gridLayoutA->setSpacing(6);
        gridLayoutA->setObjectName(QStringLiteral("gridLayoutA"));
        invA = new QPushButton(horizontalLayoutWidget_6);
        invA->setObjectName(QStringLiteral("invA"));

        gridLayoutA->addWidget(invA, 1, 1, 1, 1);

        detA = new QPushButton(horizontalLayoutWidget_6);
        detA->setObjectName(QStringLiteral("detA"));

        gridLayoutA->addWidget(detA, 1, 0, 1, 1);

        charactorVectorA = new QPushButton(horizontalLayoutWidget_6);
        charactorVectorA->setObjectName(QStringLiteral("charactorVectorA"));

        gridLayoutA->addWidget(charactorVectorA, 4, 0, 1, 1);

        simplestA = new QPushButton(horizontalLayoutWidget_6);
        simplestA->setObjectName(QStringLiteral("simplestA"));

        gridLayoutA->addWidget(simplestA, 3, 1, 1, 1);

        tranA = new QPushButton(horizontalLayoutWidget_6);
        tranA->setObjectName(QStringLiteral("tranA"));

        gridLayoutA->addWidget(tranA, 2, 0, 1, 1);

        trA = new QPushButton(horizontalLayoutWidget_6);
        trA->setObjectName(QStringLiteral("trA"));

        gridLayoutA->addWidget(trA, 2, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        timeA = new QPushButton(horizontalLayoutWidget_6);
        timeA->setObjectName(QStringLiteral("timeA"));

        horizontalLayout_3->addWidget(timeA);

        lineEdit_TimeA = new QLineEdit(horizontalLayoutWidget_6);
        lineEdit_TimeA->setObjectName(QStringLiteral("lineEdit_TimeA"));

        horizontalLayout_3->addWidget(lineEdit_TimeA);


        gridLayoutA->addLayout(horizontalLayout_3, 5, 1, 1, 1);

        charactorValueA = new QPushButton(horizontalLayoutWidget_6);
        charactorValueA->setObjectName(QStringLiteral("charactorValueA"));

        gridLayoutA->addWidget(charactorValueA, 4, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mulityNumA = new QPushButton(horizontalLayoutWidget_6);
        mulityNumA->setObjectName(QStringLiteral("mulityNumA"));

        horizontalLayout_2->addWidget(mulityNumA);

        lineEdit_NumA = new QLineEdit(horizontalLayoutWidget_6);
        lineEdit_NumA->setObjectName(QStringLiteral("lineEdit_NumA"));

        horizontalLayout_2->addWidget(lineEdit_NumA);


        gridLayoutA->addLayout(horizontalLayout_2, 5, 0, 1, 1);

        randomA = new QPushButton(horizontalLayoutWidget_6);
        randomA->setObjectName(QStringLiteral("randomA"));

        gridLayoutA->addWidget(randomA, 0, 0, 1, 1);

        clearA = new QPushButton(horizontalLayoutWidget_6);
        clearA->setObjectName(QStringLiteral("clearA"));

        gridLayoutA->addWidget(clearA, 0, 1, 1, 1);


        horizontalLayout_6->addLayout(gridLayoutA);

        gridLayoutA_2 = new QGridLayout();
        gridLayoutA_2->setSpacing(6);
        gridLayoutA_2->setObjectName(QStringLiteral("gridLayoutA_2"));
        detB = new QPushButton(horizontalLayoutWidget_6);
        detB->setObjectName(QStringLiteral("detB"));

        gridLayoutA_2->addWidget(detB, 1, 0, 1, 1);

        invB = new QPushButton(horizontalLayoutWidget_6);
        invB->setObjectName(QStringLiteral("invB"));

        gridLayoutA_2->addWidget(invB, 1, 1, 1, 1);

        clearB = new QPushButton(horizontalLayoutWidget_6);
        clearB->setObjectName(QStringLiteral("clearB"));

        gridLayoutA_2->addWidget(clearB, 0, 1, 1, 1);

        charactorValueB = new QPushButton(horizontalLayoutWidget_6);
        charactorValueB->setObjectName(QStringLiteral("charactorValueB"));

        gridLayoutA_2->addWidget(charactorValueB, 4, 1, 1, 1);

        tranB = new QPushButton(horizontalLayoutWidget_6);
        tranB->setObjectName(QStringLiteral("tranB"));

        gridLayoutA_2->addWidget(tranB, 2, 0, 1, 1);

        trB = new QPushButton(horizontalLayoutWidget_6);
        trB->setObjectName(QStringLiteral("trB"));

        gridLayoutA_2->addWidget(trB, 2, 1, 1, 1);

        simplestB = new QPushButton(horizontalLayoutWidget_6);
        simplestB->setObjectName(QStringLiteral("simplestB"));

        gridLayoutA_2->addWidget(simplestB, 3, 1, 1, 1);

        charactorVectorB = new QPushButton(horizontalLayoutWidget_6);
        charactorVectorB->setObjectName(QStringLiteral("charactorVectorB"));

        gridLayoutA_2->addWidget(charactorVectorB, 4, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        timeB = new QPushButton(horizontalLayoutWidget_6);
        timeB->setObjectName(QStringLiteral("timeB"));

        horizontalLayout_5->addWidget(timeB);

        lineEdit_TimeB = new QLineEdit(horizontalLayoutWidget_6);
        lineEdit_TimeB->setObjectName(QStringLiteral("lineEdit_TimeB"));

        horizontalLayout_5->addWidget(lineEdit_TimeB);


        gridLayoutA_2->addLayout(horizontalLayout_5, 5, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        mulityNumB = new QPushButton(horizontalLayoutWidget_6);
        mulityNumB->setObjectName(QStringLiteral("mulityNumB"));

        horizontalLayout_4->addWidget(mulityNumB);

        lineEdit_NumB = new QLineEdit(horizontalLayoutWidget_6);
        lineEdit_NumB->setObjectName(QStringLiteral("lineEdit_NumB"));

        horizontalLayout_4->addWidget(lineEdit_NumB);


        gridLayoutA_2->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        randomB = new QPushButton(horizontalLayoutWidget_6);
        randomB->setObjectName(QStringLiteral("randomB"));

        gridLayoutA_2->addWidget(randomB, 0, 0, 1, 1);


        horizontalLayout_6->addLayout(gridLayoutA_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(430, 0, 91, 51));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(990, 0, 91, 51));
        label_2->setFont(font);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(270, 690, 961, 191));
        expression = new QLineEdit(centralWidget);
        expression->setObjectName(QStringLiteral("expression"));
        expression->setGeometry(QRect(660, 440, 191, 31));
        expression_equal = new QPushButton(centralWidget);
        expression_equal->setObjectName(QStringLiteral("expression_equal"));
        expression_equal->setGeometry(QRect(860, 440, 93, 28));
        caculator_guiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(caculator_guiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1266, 26));
        caculator_guiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(caculator_guiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        caculator_guiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(caculator_guiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        caculator_guiClass->setStatusBar(statusBar);

        retranslateUi(caculator_guiClass);

        QMetaObject::connectSlotsByName(caculator_guiClass);
    } // setupUi

    void retranslateUi(QMainWindow *caculator_guiClass)
    {
        caculator_guiClass->setWindowTitle(QApplication::translate("caculator_guiClass", "caculator_gui", nullptr));
        add->setText(QApplication::translate("caculator_guiClass", "A + B", nullptr));
        sub->setText(QApplication::translate("caculator_guiClass", "A - B", nullptr));
        multiply->setText(QApplication::translate("caculator_guiClass", "A * B", nullptr));
        exchange->setText(QApplication::translate("caculator_guiClass", "\342\206\222\n"
"\342\206\220", nullptr));
        invA->setText(QApplication::translate("caculator_guiClass", "\351\200\206\347\237\251\351\230\265", nullptr));
        detA->setText(QApplication::translate("caculator_guiClass", "\350\241\214\345\210\227\345\274\217", nullptr));
        charactorVectorA->setText(QApplication::translate("caculator_guiClass", "\347\211\271\345\276\201\345\220\221\351\207\217", nullptr));
        simplestA->setText(QApplication::translate("caculator_guiClass", "\344\270\211\350\247\222\347\237\251\351\230\265", nullptr));
        tranA->setText(QApplication::translate("caculator_guiClass", "\350\275\254\347\275\256\347\237\251\351\230\265", nullptr));
        trA->setText(QApplication::translate("caculator_guiClass", "\346\261\202\347\247\251", nullptr));
        timeA->setText(QApplication::translate("caculator_guiClass", "\345\271\202", nullptr));
        charactorValueA->setText(QApplication::translate("caculator_guiClass", "\347\211\271\345\276\201\345\200\274", nullptr));
        mulityNumA->setText(QApplication::translate("caculator_guiClass", "\346\225\260\344\271\230", nullptr));
        randomA->setText(QApplication::translate("caculator_guiClass", "\351\232\217\346\234\272", nullptr));
        clearA->setText(QApplication::translate("caculator_guiClass", "\346\270\205\351\231\244", nullptr));
        detB->setText(QApplication::translate("caculator_guiClass", "\350\241\214\345\210\227\345\274\217", nullptr));
        invB->setText(QApplication::translate("caculator_guiClass", "\351\200\206\347\237\251\351\230\265", nullptr));
        clearB->setText(QApplication::translate("caculator_guiClass", "\346\270\205\351\231\244", nullptr));
        charactorValueB->setText(QApplication::translate("caculator_guiClass", "\347\211\271\345\276\201\345\200\274", nullptr));
        tranB->setText(QApplication::translate("caculator_guiClass", "\350\275\254\347\275\256\347\237\251\351\230\265", nullptr));
        trB->setText(QApplication::translate("caculator_guiClass", "\346\261\202\347\247\251", nullptr));
        simplestB->setText(QApplication::translate("caculator_guiClass", "\344\270\211\350\247\222\347\237\251\351\230\265", nullptr));
        charactorVectorB->setText(QApplication::translate("caculator_guiClass", "\347\211\271\345\276\201\345\220\221\351\207\217", nullptr));
        timeB->setText(QApplication::translate("caculator_guiClass", "\345\271\202", nullptr));
        mulityNumB->setText(QApplication::translate("caculator_guiClass", "\346\225\260\344\271\230", nullptr));
        randomB->setText(QApplication::translate("caculator_guiClass", "\351\232\217\346\234\272", nullptr));
        label->setText(QApplication::translate("caculator_guiClass", "\347\237\251\351\230\265A", nullptr));
        label_2->setText(QApplication::translate("caculator_guiClass", "\347\237\251\351\230\265B", nullptr));
        expression->setText(QApplication::translate("caculator_guiClass", "1*A+2*B  ", nullptr));
        expression_equal->setText(QApplication::translate("caculator_guiClass", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class caculator_guiClass: public Ui_caculator_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CACULATOR_GUI_H
