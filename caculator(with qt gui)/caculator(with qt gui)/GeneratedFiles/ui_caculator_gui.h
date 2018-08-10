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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_caculator_guiClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *clearA;
    QPushButton *randomA;
    QSpacerItem *verticalSpacer;
    QTextEdit *MatrixA;
    QVBoxLayout *verticalLayout;
    QPushButton *add;
    QPushButton *sub;
    QPushButton *multiply;
    QSpacerItem *verticalSpacer_4;
    QPushButton *exchange;
    QSpacerItem *verticalSpacer_3;
    QTextEdit *MatrixB;
    QVBoxLayout *verticalLayout_3;
    QPushButton *clearB;
    QPushButton *randomB;
    QSpacerItem *verticalSpacer_2;
    QTextBrowser *output_test_browser;
    QWidget *layoutWidget;
    QGridLayout *gridLayoutA_2;
    QPushButton *charactorValueA;
    QPushButton *charactorVectorA;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *timeA;
    QLineEdit *lineEdit_TimeA;
    QPushButton *tranA;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *mulityNumA;
    QLineEdit *lineEdit_NumA;
    QPushButton *detA;
    QPushButton *trA;
    QPushButton *simplestA;
    QPushButton *invA;
    QPushButton *pushButton_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayoutA;
    QPushButton *trB;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *timeB;
    QLineEdit *lineEdit_TimeB;
    QPushButton *tranB;
    QPushButton *invB;
    QPushButton *simplestB;
    QPushButton *charactorValueB;
    QPushButton *charactorVectorB;
    QPushButton *detB;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *mulityNumB;
    QLineEdit *lineEdit_NumB;
    QPushButton *dialogB;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *use_float;
    QLabel *label_3;
    QSpinBox *decimals_num;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *caculator_guiClass)
    {
        if (caculator_guiClass->objectName().isEmpty())
            caculator_guiClass->setObjectName(QStringLiteral("caculator_guiClass"));
        caculator_guiClass->setEnabled(true);
        caculator_guiClass->resize(1627, 912);
        centralWidget = new QWidget(caculator_guiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(270, 90, 1061, 291));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        clearA = new QPushButton(horizontalLayoutWidget);
        clearA->setObjectName(QStringLiteral("clearA"));

        verticalLayout_2->addWidget(clearA);

        randomA = new QPushButton(horizontalLayoutWidget);
        randomA->setObjectName(QStringLiteral("randomA"));

        verticalLayout_2->addWidget(randomA);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        MatrixA = new QTextEdit(horizontalLayoutWidget);
        MatrixA->setObjectName(QStringLiteral("MatrixA"));

        horizontalLayout->addWidget(MatrixA);

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

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        exchange = new QPushButton(horizontalLayoutWidget);
        exchange->setObjectName(QStringLiteral("exchange"));

        verticalLayout->addWidget(exchange);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout);

        MatrixB = new QTextEdit(horizontalLayoutWidget);
        MatrixB->setObjectName(QStringLiteral("MatrixB"));

        horizontalLayout->addWidget(MatrixB);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        clearB = new QPushButton(horizontalLayoutWidget);
        clearB->setObjectName(QStringLiteral("clearB"));

        verticalLayout_3->addWidget(clearB);

        randomB = new QPushButton(horizontalLayoutWidget);
        randomB->setObjectName(QStringLiteral("randomB"));

        verticalLayout_3->addWidget(randomB);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_3);

        output_test_browser = new QTextBrowser(centralWidget);
        output_test_browser->setObjectName(QStringLiteral("output_test_browser"));
        output_test_browser->setGeometry(QRect(340, 690, 861, 191));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(380, 430, 381, 201));
        gridLayoutA_2 = new QGridLayout(layoutWidget);
        gridLayoutA_2->setSpacing(6);
        gridLayoutA_2->setContentsMargins(11, 11, 11, 11);
        gridLayoutA_2->setObjectName(QStringLiteral("gridLayoutA_2"));
        gridLayoutA_2->setContentsMargins(0, 0, 0, 0);
        charactorValueA = new QPushButton(layoutWidget);
        charactorValueA->setObjectName(QStringLiteral("charactorValueA"));

        gridLayoutA_2->addWidget(charactorValueA, 3, 1, 1, 1);

        charactorVectorA = new QPushButton(layoutWidget);
        charactorVectorA->setObjectName(QStringLiteral("charactorVectorA"));

        gridLayoutA_2->addWidget(charactorVectorA, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        timeA = new QPushButton(layoutWidget);
        timeA->setObjectName(QStringLiteral("timeA"));

        horizontalLayout_5->addWidget(timeA);

        lineEdit_TimeA = new QLineEdit(layoutWidget);
        lineEdit_TimeA->setObjectName(QStringLiteral("lineEdit_TimeA"));

        horizontalLayout_5->addWidget(lineEdit_TimeA);


        gridLayoutA_2->addLayout(horizontalLayout_5, 4, 1, 1, 1);

        tranA = new QPushButton(layoutWidget);
        tranA->setObjectName(QStringLiteral("tranA"));

        gridLayoutA_2->addWidget(tranA, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        mulityNumA = new QPushButton(layoutWidget);
        mulityNumA->setObjectName(QStringLiteral("mulityNumA"));

        horizontalLayout_4->addWidget(mulityNumA);

        lineEdit_NumA = new QLineEdit(layoutWidget);
        lineEdit_NumA->setObjectName(QStringLiteral("lineEdit_NumA"));

        horizontalLayout_4->addWidget(lineEdit_NumA);


        gridLayoutA_2->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        detA = new QPushButton(layoutWidget);
        detA->setObjectName(QStringLiteral("detA"));

        gridLayoutA_2->addWidget(detA, 0, 0, 1, 1);

        trA = new QPushButton(layoutWidget);
        trA->setObjectName(QStringLiteral("trA"));

        gridLayoutA_2->addWidget(trA, 1, 1, 1, 1);

        simplestA = new QPushButton(layoutWidget);
        simplestA->setObjectName(QStringLiteral("simplestA"));

        gridLayoutA_2->addWidget(simplestA, 2, 1, 1, 1);

        invA = new QPushButton(layoutWidget);
        invA->setObjectName(QStringLiteral("invA"));

        gridLayoutA_2->addWidget(invA, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayoutA_2->addWidget(pushButton_2, 2, 0, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(840, 430, 381, 201));
        gridLayoutA = new QGridLayout(layoutWidget1);
        gridLayoutA->setSpacing(6);
        gridLayoutA->setContentsMargins(11, 11, 11, 11);
        gridLayoutA->setObjectName(QStringLiteral("gridLayoutA"));
        gridLayoutA->setContentsMargins(0, 0, 0, 0);
        trB = new QPushButton(layoutWidget1);
        trB->setObjectName(QStringLiteral("trB"));

        gridLayoutA->addWidget(trB, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        timeB = new QPushButton(layoutWidget1);
        timeB->setObjectName(QStringLiteral("timeB"));

        horizontalLayout_3->addWidget(timeB);

        lineEdit_TimeB = new QLineEdit(layoutWidget1);
        lineEdit_TimeB->setObjectName(QStringLiteral("lineEdit_TimeB"));

        horizontalLayout_3->addWidget(lineEdit_TimeB);


        gridLayoutA->addLayout(horizontalLayout_3, 4, 1, 1, 1);

        tranB = new QPushButton(layoutWidget1);
        tranB->setObjectName(QStringLiteral("tranB"));

        gridLayoutA->addWidget(tranB, 1, 0, 1, 1);

        invB = new QPushButton(layoutWidget1);
        invB->setObjectName(QStringLiteral("invB"));

        gridLayoutA->addWidget(invB, 0, 1, 1, 1);

        simplestB = new QPushButton(layoutWidget1);
        simplestB->setObjectName(QStringLiteral("simplestB"));

        gridLayoutA->addWidget(simplestB, 2, 1, 1, 1);

        charactorValueB = new QPushButton(layoutWidget1);
        charactorValueB->setObjectName(QStringLiteral("charactorValueB"));

        gridLayoutA->addWidget(charactorValueB, 3, 1, 1, 1);

        charactorVectorB = new QPushButton(layoutWidget1);
        charactorVectorB->setObjectName(QStringLiteral("charactorVectorB"));

        gridLayoutA->addWidget(charactorVectorB, 3, 0, 1, 1);

        detB = new QPushButton(layoutWidget1);
        detB->setObjectName(QStringLiteral("detB"));

        gridLayoutA->addWidget(detB, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mulityNumB = new QPushButton(layoutWidget1);
        mulityNumB->setObjectName(QStringLiteral("mulityNumB"));

        horizontalLayout_2->addWidget(mulityNumB);

        lineEdit_NumB = new QLineEdit(layoutWidget1);
        lineEdit_NumB->setObjectName(QStringLiteral("lineEdit_NumB"));

        horizontalLayout_2->addWidget(lineEdit_NumB);


        gridLayoutA->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        dialogB = new QPushButton(layoutWidget1);
        dialogB->setObjectName(QStringLiteral("dialogB"));

        gridLayoutA->addWidget(dialogB, 2, 0, 1, 1);

        horizontalLayoutWidget_4 = new QWidget(centralWidget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(340, 640, 222, 41));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        use_float = new QRadioButton(horizontalLayoutWidget_4);
        use_float->setObjectName(QStringLiteral("use_float"));

        horizontalLayout_8->addWidget(use_float);

        label_3 = new QLabel(horizontalLayoutWidget_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_8->addWidget(label_3);

        decimals_num = new QSpinBox(horizontalLayoutWidget_4);
        decimals_num->setObjectName(QStringLiteral("decimals_num"));

        horizontalLayout_8->addWidget(decimals_num);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(270, 10, 1061, 80));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label->setOpenExternalLinks(false);

        horizontalLayout_7->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_7->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        caculator_guiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(caculator_guiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        caculator_guiClass->setStatusBar(statusBar);

        retranslateUi(caculator_guiClass);
        QObject::connect(add, SIGNAL(clicked()), caculator_guiClass, SLOT(push_add_button()));
        QObject::connect(sub, SIGNAL(clicked()), caculator_guiClass, SLOT(push_subtract_button()));
        QObject::connect(multiply, SIGNAL(clicked()), caculator_guiClass, SLOT(push_multiply_button()));
        QObject::connect(exchange, SIGNAL(clicked()), caculator_guiClass, SLOT(push_swap_button()));
        QObject::connect(randomA, SIGNAL(clicked()), caculator_guiClass, SLOT(push_randomA_button()));
        QObject::connect(randomB, SIGNAL(clicked()), caculator_guiClass, SLOT(push_randomB_button()));
        QObject::connect(clearA, SIGNAL(clicked()), caculator_guiClass, SLOT(push_clearA_button()));
        QObject::connect(clearB, SIGNAL(clicked()), caculator_guiClass, SLOT(push_clearB_button()));
        QObject::connect(detA, SIGNAL(clicked()), caculator_guiClass, SLOT(push_detA_button()));
        QObject::connect(detB, SIGNAL(clicked()), caculator_guiClass, SLOT(push_detB_button()));
        QObject::connect(invA, SIGNAL(clicked()), caculator_guiClass, SLOT(push_invA_button()));
        QObject::connect(invB, SIGNAL(clicked()), caculator_guiClass, SLOT(push_invB_button()));
        QObject::connect(tranA, SIGNAL(clicked()), caculator_guiClass, SLOT(push_tranA_button()));
        QObject::connect(tranB, SIGNAL(clicked()), caculator_guiClass, SLOT(push_tranB_button()));
        QObject::connect(trA, SIGNAL(clicked()), caculator_guiClass, SLOT(push_rankA_button()));
        QObject::connect(trB, SIGNAL(clicked()), caculator_guiClass, SLOT(push_rankB_button()));
        QObject::connect(simplestA, SIGNAL(clicked()), caculator_guiClass, SLOT(push_getSimplestA_button()));
        QObject::connect(simplestB, SIGNAL(clicked()), caculator_guiClass, SLOT(push_getSimplestB_button()));
        QObject::connect(charactorVectorA, SIGNAL(clicked()), caculator_guiClass, SLOT(push_FeatureVectorA_button()));
        QObject::connect(charactorVectorB, SIGNAL(clicked()), caculator_guiClass, SLOT(push_FeatureVectorB_button()));
        QObject::connect(charactorValueA, SIGNAL(clicked()), caculator_guiClass, SLOT(push_FeatureValueA_button()));
        QObject::connect(charactorValueB, SIGNAL(clicked()), caculator_guiClass, SLOT(push_FeatureValueB_button()));
        QObject::connect(mulityNumA, SIGNAL(clicked()), caculator_guiClass, SLOT(push_NumMulA_button()));
        QObject::connect(mulityNumB, SIGNAL(clicked()), caculator_guiClass, SLOT(push_NumMulB_button()));
        QObject::connect(timeA, SIGNAL(clicked()), caculator_guiClass, SLOT(push_timeA_button()));
        QObject::connect(timeB, SIGNAL(clicked()), caculator_guiClass, SLOT(push_timeB_button()));
        QObject::connect(use_float, SIGNAL(toggled(bool)), caculator_guiClass, SLOT(change_state_use_float()));
        QObject::connect(decimals_num, SIGNAL(valueChanged(int)), caculator_guiClass, SLOT(change_float_digit()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), caculator_guiClass, SLOT(push_dialog_matrixA_button()));
        QObject::connect(dialogB, SIGNAL(clicked()), caculator_guiClass, SLOT(push_dialog_matrixB_button()));

        QMetaObject::connectSlotsByName(caculator_guiClass);
    } // setupUi

    void retranslateUi(QMainWindow *caculator_guiClass)
    {
        caculator_guiClass->setWindowTitle(QApplication::translate("caculator_guiClass", "caculator_gui", nullptr));
        clearA->setText(QApplication::translate("caculator_guiClass", "\346\270\205\351\231\244", nullptr));
        randomA->setText(QApplication::translate("caculator_guiClass", "\351\232\217\346\234\272", nullptr));
#ifndef QT_NO_TOOLTIP
        MatrixA->setToolTip(QApplication::translate("caculator_guiClass", "<html><head/><body><p>\350\276\223\345\205\245A\347\237\251\351\230\265</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        add->setText(QApplication::translate("caculator_guiClass", "A + B", nullptr));
        sub->setText(QApplication::translate("caculator_guiClass", "A - B", nullptr));
        multiply->setText(QApplication::translate("caculator_guiClass", "A * B", nullptr));
        exchange->setText(QApplication::translate("caculator_guiClass", "\342\206\222\n"
"\342\206\220", nullptr));
#ifndef QT_NO_TOOLTIP
        MatrixB->setToolTip(QApplication::translate("caculator_guiClass", "<html><head/><body><p>\350\276\223\345\205\245B\347\237\251\351\230\265</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        clearB->setText(QApplication::translate("caculator_guiClass", "\346\270\205\351\231\244", nullptr));
        randomB->setText(QApplication::translate("caculator_guiClass", "\351\232\217\346\234\272", nullptr));
        charactorValueA->setText(QApplication::translate("caculator_guiClass", "\347\211\271\345\276\201\345\200\274", nullptr));
        charactorVectorA->setText(QApplication::translate("caculator_guiClass", "\347\211\271\345\276\201\345\220\221\351\207\217", nullptr));
        timeA->setText(QApplication::translate("caculator_guiClass", "\345\271\202", nullptr));
        tranA->setText(QApplication::translate("caculator_guiClass", "\350\275\254\347\275\256\347\237\251\351\230\265", nullptr));
        mulityNumA->setText(QApplication::translate("caculator_guiClass", "\346\225\260\344\271\230", nullptr));
        detA->setText(QApplication::translate("caculator_guiClass", "\350\241\214\345\210\227\345\274\217", nullptr));
        trA->setText(QApplication::translate("caculator_guiClass", "\346\261\202\347\247\251", nullptr));
        simplestA->setText(QApplication::translate("caculator_guiClass", "\344\270\211\350\247\222\347\237\251\351\230\265", nullptr));
        invA->setText(QApplication::translate("caculator_guiClass", "\351\200\206\347\237\251\351\230\265", nullptr));
        pushButton_2->setText(QApplication::translate("caculator_guiClass", "\345\257\271\350\247\222\347\237\251\351\230\265", nullptr));
        trB->setText(QApplication::translate("caculator_guiClass", "\346\261\202\347\247\251", nullptr));
        timeB->setText(QApplication::translate("caculator_guiClass", "\345\271\202", nullptr));
        tranB->setText(QApplication::translate("caculator_guiClass", "\350\275\254\347\275\256\347\237\251\351\230\265", nullptr));
        invB->setText(QApplication::translate("caculator_guiClass", "\351\200\206\347\237\251\351\230\265", nullptr));
        simplestB->setText(QApplication::translate("caculator_guiClass", "\344\270\211\350\247\222\347\237\251\351\230\265", nullptr));
        charactorValueB->setText(QApplication::translate("caculator_guiClass", "\347\211\271\345\276\201\345\200\274", nullptr));
        charactorVectorB->setText(QApplication::translate("caculator_guiClass", "\347\211\271\345\276\201\345\220\221\351\207\217", nullptr));
        detB->setText(QApplication::translate("caculator_guiClass", "\350\241\214\345\210\227\345\274\217", nullptr));
        mulityNumB->setText(QApplication::translate("caculator_guiClass", "\346\225\260\344\271\230", nullptr));
        dialogB->setText(QApplication::translate("caculator_guiClass", "\345\257\271\350\247\222\347\237\251\351\230\265", nullptr));
        use_float->setText(QApplication::translate("caculator_guiClass", "\347\224\250\345\260\217\346\225\260\350\241\250\347\244\272", nullptr));
        label_3->setText(QApplication::translate("caculator_guiClass", "\345\260\217\346\225\260\344\275\215", nullptr));
        label->setText(QApplication::translate("caculator_guiClass", "\347\237\251\351\230\265A", nullptr));
        label_2->setText(QApplication::translate("caculator_guiClass", "\347\237\251\351\230\265B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class caculator_guiClass: public Ui_caculator_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CACULATOR_GUI_H
