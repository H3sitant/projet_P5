#ifndef MENU_H
#define MENU_H


#include <QtWidgets>
#include "FenetrePrincipale.h"
/*
Menu principal de l'application
*/
class Menu : public QWidget {
	Q_OBJECT

public:
	Menu(FenetrePrincipale * parent =nullptr);

private slots:
	void actionJouer();
	void actionInstructions();
	void actionQuitter();
	
private:
	void createMenu();
	QWidget *widget;
	QPlainTextEdit *fenetreTexte;
	FenetrePrincipale*parent;
	QPushButton *jouer;
	QPushButton *instructions;
	QPushButton *quitter;
};

#endif // MENU_H