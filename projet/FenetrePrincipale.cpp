#include "FenetrePrincipale.h"
#include "menu.h"
#include "fenetrejeu.h"
#include "pause.h"
#include "instructions.h"
#include "MenuFinPartie.h"

FenetrePrincipale::FenetrePrincipale(QWidget * parent): QStackedWidget(parent)
{
	jeu = new FenetreJeu(this);
	menuPrincipal = new Menu(this);
	menuPause = new Pause(this);
	instructions = new Instructions(this);
	finPartie = new  MenuFinPartie(this);
	connect(finPartie, &MenuFinPartie::boutonMenuClicked, this, &FenetrePrincipale::slotAfficherMenuPrincipal);
	connect(finPartie, &MenuFinPartie::boutonRejouerClicked, this, &FenetrePrincipale::slotRejouer);
	setFixedSize(1600, 900);
	addWidget(jeu);
	addWidget(menuPrincipal);
	addWidget(menuPause);
	addWidget(instructions);
	addWidget(finPartie);
	finPartie->setStyleSheet("background-color: rgba(0,0,0,0) ");
	setCurrentWidget(menuPrincipal);

}

void FenetrePrincipale::afficherJeu()
{
	int memCurrentIndex = currentIndex();
	setCurrentWidget(jeu);
	lastWidgetId = memCurrentIndex;
}

void FenetrePrincipale::afficherMenuPause()
{
	int memCurrentIndex = currentIndex();
	printf("FenetrePrincipale");
	setCurrentWidget(menuPause);
	lastWidgetId = memCurrentIndex;
}

void FenetrePrincipale::afficherInstructions()
{
	int memCurrentIndex = currentIndex();
	printf("FenetrePrincipale::afficherInstructions");
	setCurrentWidget(instructions);
	lastWidgetId = memCurrentIndex;
}

void FenetrePrincipale::demarrerNouvellePartie()
{
	int memCurrentIndex = currentIndex();
	lastWidgetId = memCurrentIndex;
}

void FenetrePrincipale::afficherFinPartie(bool victoire)
{
	int memCurrentIndex = currentIndex();
	finPartie->setVictoire(victoire);
	setCurrentWidget(finPartie);
}

void FenetrePrincipale::slotProchainNiveau()
{

}

void FenetrePrincipale::slotRejouer()
{
	demarrerNouvellePartie();
}

void FenetrePrincipale::slotAfficherMenuPrincipal() {
	afficherMenuPrincipal();
}

void FenetrePrincipale::afficherMenuPrincipal()
{
	int memCurrentIndex = currentIndex();
	setCurrentWidget(menuPrincipal);
	lastWidgetId = memCurrentIndex;
}

void FenetrePrincipale::retour() {
	int memCurrentIndex = currentIndex();
	setCurrentIndex(lastWidgetId);
	lastWidgetId = memCurrentIndex;
}

