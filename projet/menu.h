#ifndef MENU_H
#define MENU_H


#include <QtWidgets>
#include "FenetrePrincipale.h"

class Menu : public QWidget {
	Q_OBJECT

public:
	Menu(FenetrePrincipale * parent =nullptr);

private slots:
	void actionJouer();
	void actionInstruction();
	void actionReglages();
	
private:
	void createMenu();
	QWidget *widget;
	QPlainTextEdit *fenetreTexte;
	FenetrePrincipale*parent;
	QPushButton *jouer;

	QPushButton *instructions ;
	QPushButton *reglages ;
};

#endif // MENU_H