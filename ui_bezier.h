/********************************************************************************
** Form generated from reading UI file 'bezier.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEZIER_H
#define UI_BEZIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bezier
{
public:

    void setupUi(QWidget *Bezier)
    {
        if (Bezier->objectName().isEmpty())
            Bezier->setObjectName(QString::fromUtf8("Bezier"));
        Bezier->resize(800, 600);

        retranslateUi(Bezier);

        QMetaObject::connectSlotsByName(Bezier);
    } // setupUi

    void retranslateUi(QWidget *Bezier)
    {
        Bezier->setWindowTitle(QCoreApplication::translate("Bezier", "Bezier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bezier: public Ui_Bezier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEZIER_H
