#include <QtWidgets>
#include "FenetrePrincipale.h"


//Fenetre du menu de pause
//Contient plusieurs boutons pour naviguer au menu désiré
class Pause : public QWidget {
	Q_OBJECT

public:
	Pause(FenetrePrincipale *parent=nullptr);

private slots:
	void reprendre();
	void instructions();
	void rejouer();
	void quitter();
	
private:
	void createMenu();
	QPushButton *reprendreP;
	QPushButton *instructionsP;
	QPushButton *rejouerP;
	QPushButton *quitterP;
	QPlainTextEdit *fenetreTexte;
	FenetrePrincipale* parent;
};
