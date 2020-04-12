#include "FenetrePrincipale.h"
#include "menu.h"
#include "fenetrejeu.h"

FenetrePrincipale::FenetrePrincipale(QWidget * parent): QStackedWidget(parent)
{
	jeu = new FenetreJeu(this);
	menuPrincipal = new Menu(this);
	addWidget(jeu);
	addWidget(menuPrincipal);
	setCurrentWidget(jeu);
	setCurrentWidget(menuPrincipal);

}

void FenetrePrincipale::afficherJeu()
{
	setCurrentWidget(jeu);
}

void FenetrePrincipale::afficherMenuPause()
{
}

void FenetrePrincipale::afficherMenuPrincipal()
{
}

