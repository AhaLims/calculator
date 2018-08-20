/********************************************************************************
** Form generated from reading UI file 'QT_OpenGL.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_OPENGL_H
#define UI_QT_OPENGL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QT_OpenGLClass
{
public:
    QPushButton *pushOK;
    QLineEdit *function_edit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *heLp;
    QPushButton *example;
    QLabel *label_3;
    QLineEdit *variabl_name;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_5;
    QPushButton *left;
    QPushButton *right;
    QPushButton *pushButton_4;
    QPushButton *lesson_2;
    QPushButton *lesson;
    QPushButton *reset;

    void setupUi(QWidget *QT_OpenGLClass)
    {
        if (QT_OpenGLClass->objectName().isEmpty())
            QT_OpenGLClass->setObjectName(QStringLiteral("QT_OpenGLClass"));
        QT_OpenGLClass->resize(1060, 900);
        pushOK = new QPushButton(QT_OpenGLClass);
        pushOK->setObjectName(QStringLiteral("pushOK"));
        pushOK->setGeometry(QRect(890, 160, 101, 41));
        function_edit = new QLineEdit(QT_OpenGLClass);
        function_edit->setObjectName(QStringLiteral("function_edit"));
        function_edit->setGeometry(QRect(260, 160, 611, 41));
        QFont font;
        font.setPointSize(12);
        function_edit->setFont(font);
        label = new QLabel(QT_OpenGLClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 160, 41, 31));
        label->setFont(font);
        label_2 = new QLabel(QT_OpenGLClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(470, 40, 291, 51));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("background-image: url(:/caculator_gui/picture/white.png)"));
        heLp = new QPushButton(QT_OpenGLClass);
        heLp->setObjectName(QStringLiteral("heLp"));
        heLp->setGeometry(QRect(370, 100, 93, 28));
        example = new QPushButton(QT_OpenGLClass);
        example->setObjectName(QStringLiteral("example"));
        example->setGeometry(QRect(610, 100, 93, 28));
        label_3 = new QLabel(QT_OpenGLClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 160, 72, 31));
        label_3->setFont(font);
        variabl_name = new QLineEdit(QT_OpenGLClass);
        variabl_name->setObjectName(QStringLiteral("variabl_name"));
        variabl_name->setGeometry(QRect(110, 160, 71, 41));
        variabl_name->setFont(font);
        gridLayoutWidget = new QWidget(QT_OpenGLClass);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(640, 220, 391, 211));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        left = new QPushButton(gridLayoutWidget);
        left->setObjectName(QStringLiteral("left"));

        gridLayout->addWidget(left, 0, 0, 1, 1);

        right = new QPushButton(gridLayoutWidget);
        right->setObjectName(QStringLiteral("right"));

        gridLayout->addWidget(right, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        lesson_2 = new QPushButton(gridLayoutWidget);
        lesson_2->setObjectName(QStringLiteral("lesson_2"));

        gridLayout->addWidget(lesson_2, 2, 0, 1, 1);

        lesson = new QPushButton(gridLayoutWidget);
        lesson->setObjectName(QStringLiteral("lesson"));

        gridLayout->addWidget(lesson, 2, 1, 1, 1);

        reset = new QPushButton(gridLayoutWidget);
        reset->setObjectName(QStringLiteral("reset"));

        gridLayout->addWidget(reset, 3, 0, 1, 1);


        retranslateUi(QT_OpenGLClass);
        QObject::connect(heLp, SIGNAL(clicked()), QT_OpenGLClass, SLOT(push_help()));
        QObject::connect(example, SIGNAL(clicked()), QT_OpenGLClass, SLOT(push_example()));
        QObject::connect(pushOK, SIGNAL(clicked()), QT_OpenGLClass, SLOT(push_OK()));
        QObject::connect(left, SIGNAL(clicked()), QT_OpenGLClass, SLOT(push_left()));
        QObject::connect(right, SIGNAL(clicked()), QT_OpenGLClass, SLOT(push_right()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), QT_OpenGLClass, SLOT(push_up()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), QT_OpenGLClass, SLOT(push_down()));
        QObject::connect(lesson, SIGNAL(clicked()), QT_OpenGLClass, SLOT(push_lessen()));
        QObject::connect(lesson_2, SIGNAL(clicked()), QT_OpenGLClass, SLOT(push_enlarge()));
        QObject::connect(reset, SIGNAL(clicked()), QT_OpenGLClass, SLOT(push_reset()));

        QMetaObject::connectSlotsByName(QT_OpenGLClass);
    } // setupUi

    void retranslateUi(QWidget *QT_OpenGLClass)
    {
        QT_OpenGLClass->setWindowTitle(QApplication::translate("QT_OpenGLClass", "QT_OpenGL", nullptr));
        pushOK->setText(QApplication::translate("QT_OpenGLClass", "OK", nullptr));
        label->setText(QApplication::translate("QT_OpenGLClass", "y = ", nullptr));
        label_2->setText(QApplication::translate("QT_OpenGLClass", "\344\272\214\347\273\264\345\207\275\346\225\260\350\256\241\347\256\227\345\231\250", nullptr));
        heLp->setText(QApplication::translate("QT_OpenGLClass", "\345\270\256\345\212\251", nullptr));
        example->setText(QApplication::translate("QT_OpenGLClass", "\347\244\272\344\276\213", nullptr));
        label_3->setText(QApplication::translate("QT_OpenGLClass", "\345\217\230\351\207\217\345\220\215", nullptr));
        pushButton_5->setText(QApplication::translate("QT_OpenGLClass", "\344\270\213\347\247\273", nullptr));
        left->setText(QApplication::translate("QT_OpenGLClass", "\345\267\246\347\247\273", nullptr));
        right->setText(QApplication::translate("QT_OpenGLClass", "\345\217\263\347\247\273", nullptr));
        pushButton_4->setText(QApplication::translate("QT_OpenGLClass", "\344\270\212\347\247\273", nullptr));
        lesson_2->setText(QApplication::translate("QT_OpenGLClass", "\346\224\276\345\244\247", nullptr));
        lesson->setText(QApplication::translate("QT_OpenGLClass", "\347\274\251\345\260\217", nullptr));
        reset->setText(QApplication::translate("QT_OpenGLClass", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QT_OpenGLClass: public Ui_QT_OpenGLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_OPENGL_H
