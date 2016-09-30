/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *connectButton;
    QLineEdit *ipAddress;
    QLineEdit *port;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        connectButton = new QPushButton(Dialog);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(220, 140, 80, 21));
        ipAddress = new QLineEdit(Dialog);
        ipAddress->setObjectName(QStringLiteral("ipAddress"));
        ipAddress->setGeometry(QRect(80, 140, 91, 21));
        port = new QLineEdit(Dialog);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(180, 140, 31, 21));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        connectButton->setText(QApplication::translate("Dialog", "Connect", 0));
        ipAddress->setText(QApplication::translate("Dialog", "127.0.0.1", 0));
        port->setText(QApplication::translate("Dialog", "1234", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
