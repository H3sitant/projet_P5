#include "FenetrePrincipale.h"
#include "menu.h"
#include "fenetrejeu.h"
#include "pause.h"
#include "instructions.h"

FenetrePrincipale::FenetrePrincipale(QWidget * parent): QStackedWidget(parent)
{
	jeu = new FenetreJeu(this);
	menuPrincipal = new Menu(this);
	menuPause = new Pause(this);
	instructions = new Instructions(this);
	addWidget(jeu);
	addWidget(menuPrincipal);
	addWidget(menuPause);
	addWidget(instructions);
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

void FenetrePrincipale::afficherInstructions()
{
	printf("FenetrePrincipale::afficherInstructions");
	setCurrentWidget(instructions);
}

void FenetrePrincipale::demarrerNouvellePartie()
{
}

void FenetrePrincipale::afficherMenuPrincipal()
{
	setCurrentWidget(menuPrincipal);
}

