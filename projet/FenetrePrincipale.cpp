#include "FenetrePrincipale.h"
#include "menu.h"
#include "fenetrejeu.h"
#include "pause.h"

FenetrePrincipale::FenetrePrincipale(QWidget * parent): QStackedWidget(parent)
{
	jeu = new FenetreJeu(this);
	menuPrincipal = new Menu(this);
	menuPause = new Pause(this);
	addWidget(jeu);
	addWidget(menuPrincipal);
	addWidget(menuPause);
	setCurrentWidget(jeu);
	setCurrentWidget(menuPrincipal);

}

void FenetrePrincipale::afficherJeu()
{
	setCurrentWidget(jeu);
}

void FenetrePrincipale::afficherMenuPause()
{
	printf("FenetrePrincipale");
	setCurrentWidget(menuPause);
}

void FenetrePrincipale::afficherMenuPrincipal()
{
}

