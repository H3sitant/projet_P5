/********************************************************************************
** Form generated from reading UI file 'fenetrejeu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETREJEU_H
#define UI_FENETREJEU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenetreJeu
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FenetreJeu)
    {
        if (FenetreJeu->objectName().isEmpty())
            FenetreJeu->setObjectName(QString::fromUtf8("FenetreJeu"));
        FenetreJeu->resize(800, 600);
        centralwidget = new QWidget(FenetreJeu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FenetreJeu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FenetreJeu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        FenetreJeu->setMenuBar(menubar);
        statusbar = new QStatusBar(FenetreJeu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FenetreJeu->setStatusBar(statusbar);

        retranslateUi(FenetreJeu);

        QMetaObject::connectSlotsByName(FenetreJeu);
    } // setupUi

    void retranslateUi(QMainWindow *FenetreJeu)
    {
        FenetreJeu->setWindowTitle(QCoreApplication::translate("FenetreJeu", "FenetreJeu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenetreJeu: public Ui_FenetreJeu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETREJEU_H
