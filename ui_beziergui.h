/********************************************************************************
** Form generated from reading UI file 'beziergui.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEZIERGUI_H
#define UI_BEZIERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BezierGui
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *add;
    QPushButton *clac;
    QPushButton *clear;
    QPushButton *pushButton_4;

    void setupUi(QWidget *BezierGui)
    {
        if (BezierGui->objectName().isEmpty())
            BezierGui->setObjectName(QString::fromUtf8("BezierGui"));
        BezierGui->resize(1127, 968);
        verticalLayout_3 = new QVBoxLayout(BezierGui);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(BezierGui);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(BezierGui);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(BezierGui);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(BezierGui);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        add = new QPushButton(BezierGui);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout_2->addWidget(add);

        clac = new QPushButton(BezierGui);
        clac->setObjectName(QString::fromUtf8("clac"));

        horizontalLayout_2->addWidget(clac);

        clear = new QPushButton(BezierGui);
        clear->setObjectName(QString::fromUtf8("clear"));

        horizontalLayout_2->addWidget(clear);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_4 = new QPushButton(BezierGui);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_2->addWidget(pushButton_4);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(BezierGui);

        QMetaObject::connectSlotsByName(BezierGui);
    } // setupUi

    void retranslateUi(QWidget *BezierGui)
    {
        BezierGui->setWindowTitle(QCoreApplication::translate("BezierGui", "\350\264\235\345\241\236\345\260\224\346\233\262\347\272\277\347\274\226\350\276\221\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("BezierGui", "x\350\276\223\345\205\245", nullptr));
        label_2->setText(QCoreApplication::translate("BezierGui", "y\350\276\223\345\205\245\346\210\226\350\276\223\345\207\272", nullptr));
        add->setText(QCoreApplication::translate("BezierGui", "\346\267\273\345\212\240", nullptr));
        clac->setText(QCoreApplication::translate("BezierGui", "\350\216\267\345\217\226y\345\235\220\346\240\207", nullptr));
        clear->setText(QCoreApplication::translate("BezierGui", "\346\270\205\351\231\244\346\211\200\346\234\211\346\216\247\345\210\266\347\202\271", nullptr));
        pushButton_4->setText(QCoreApplication::translate("BezierGui", "\347\202\271\345\207\273\344\273\245\346\267\273\345\212\240\346\216\247\345\210\266\347\202\271\357\274\214\346\210\226\346\213\226\345\212\250\346\216\247\345\210\266\347\202\271\347\247\273\345\212\250\343\200\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BezierGui: public Ui_BezierGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEZIERGUI_H
