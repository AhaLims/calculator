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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QT_OpenGLClass
{
public:
    QPushButton *pushOK;
    QLineEdit *get_function;
    QLabel *label;
    QLabel *label_2;
    QPushButton *heLp;
    QPushButton *example;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *enlarge;
    QPushButton *lessen;
    QPushButton *left;
    QPushButton *right;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *QT_OpenGLClass)
    {
        if (QT_OpenGLClass->objectName().isEmpty())
            QT_OpenGLClass->setObjectName(QStringLiteral("QT_OpenGLClass"));
        QT_OpenGLClass->resize(1189, 954);
        pushOK = new QPushButton(QT_OpenGLClass);
        pushOK->setObjectName(QStringLiteral("pushOK"));
        pushOK->setGeometry(QRect(900, 160, 101, 41));
        get_function = new QLineEdit(QT_OpenGLClass);
        get_function->setObjectName(QStringLiteral("get_function"));
        get_function->setGeometry(QRect(260, 160, 611, 41));
        QFont font;
        font.setPointSize(12);
        get_function->setFont(font);
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
        heLp = new QPushButton(QT_OpenGLClass);
        heLp->setObjectName(QStringLiteral("heLp"));
        heLp->setGeometry(QRect(370, 100, 93, 28));
        example = new QPushButton(QT_OpenGLClass);
        example->setObjectName(QStringLiteral("example"));
        example->setGeometry(QRect(610, 100, 93, 28));
        verticalLayoutWidget = new QWidget(QT_OpenGLClass);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(900, 250, 95, 411));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        enlarge = new QPushButton(verticalLayoutWidget);
        enlarge->setObjectName(QStringLiteral("enlarge"));

        verticalLayout->addWidget(enlarge);

        lessen = new QPushButton(verticalLayoutWidget);
        lessen->setObjectName(QStringLiteral("lessen"));

        verticalLayout->addWidget(lessen);

        left = new QPushButton(verticalLayoutWidget);
        left->setObjectName(QStringLiteral("left"));

        verticalLayout->addWidget(left);

        right = new QPushButton(verticalLayoutWidget);
        right->setObjectName(QStringLiteral("right"));

        verticalLayout->addWidget(right);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);


        retranslateUi(QT_OpenGLClass);

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
        enlarge->setText(QApplication::translate("QT_OpenGLClass", "\346\224\276\345\244\247", nullptr));
        lessen->setText(QApplication::translate("QT_OpenGLClass", "\347\274\251\345\260\217", nullptr));
        left->setText(QApplication::translate("QT_OpenGLClass", "\345\267\246\347\247\273", nullptr));
        right->setText(QApplication::translate("QT_OpenGLClass", "\345\217\263\347\247\273", nullptr));
        pushButton_4->setText(QApplication::translate("QT_OpenGLClass", "\344\270\212\347\247\273", nullptr));
        pushButton_5->setText(QApplication::translate("QT_OpenGLClass", "\344\270\213\347\247\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QT_OpenGLClass: public Ui_QT_OpenGLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_OPENGL_H
