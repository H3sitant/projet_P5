#include <QtWidgets>
#include "FenetrePrincipale.h"

//Fenêtre du menu instructions
class Instructions : public QWidget {
	Q_OBJECT

public:
	Instructions(FenetrePrincipale * parent = nullptr);

private slots:
	void retour();
	
private:
	void createMenu();
	QPushButton *quitterI;
	QWidget *widget;
	QLabel *directives;
	QLabel *commandes;
	QLabel *gauche;
	QLabel *droite;
	QLabel *pause;
	QLabel *powerups;
	QLabel *arc;
	QLabel *potion;
	QLabel *etoile;
	QLabel *corona;
	FenetrePrincipale* parent;
};
