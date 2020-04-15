#include "FenetrePrincipale.h"
#include "menu.h"
#include "fenetrejeu.h"
#include "pause.h"
#include "instructions.h"
#include "MenuFinPartie.h"

FenetrePrincipale::FenetrePrincipale(QWidget * parent): QStackedWidget(parent)
{
	jeu = new FenetreJeu(this);
	connect(jeu, &FenetreJeu::finPartieSignal, this, &FenetrePrincipale::slotFinPartie);
	connect(jeu, &FenetreJeu::pauseSignal, this, &FenetrePrincipale::slotAfficherMenuPause);
	menuPrincipal = new Menu(this);
	menuPause = new Pause(this);
	instructions = new Instructions(this);
	finPartie = new  MenuFinPartie(this);
	connect(finPartie, &MenuFinPartie::boutonMenuClicked, this, &FenetrePrincipale::slotAfficherMenuPrincipal);
	connect(finPartie, &MenuFinPartie::boutonRejouerClicked, this, &FenetrePrincipale::slotRejouer);
	setFixedSize(1280, 720);
	addWidget(jeu);
	addWidget(menuPrincipal);
	addWidget(menuPause);
	addWidget(instructions);
	addWidget(finPartie);
	setCurrentWidget(menuPrincipal);

	finPartie->setStyleSheet("background-color: rgba(0,0,0,0) ");

	//Image de fond du menu principal
	QPixmap bkgnd(":/images/Fond_Menu_Titre.png");
	bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	menuPrincipal->setAutoFillBackground(true);
	menuPrincipal->setPalette(palette);
}

void FenetrePrincipale::afficherJeu()
{
	int memCurrentIndex = currentIndex();
	setCurrentWidget(jeu);
	jeu->resume();
	lastWidgetId = memCurrentIndex;
}

void FenetrePrincipale::slotAfficherMenuPause()
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
	
	jeu->demarrerNouvellePartie();
	afficherJeu();
}

void FenetrePrincipale::afficherFinPartie(bool victoire)
{
	int memCurrentIndex = currentIndex();
	finPartie->setVictoire(victoire);
	setCurrentWidget(finPartie);
	lastWidgetId = memCurrentIndex;
}

void FenetrePrincipale::slotProchainNiveau()
{

}

void FenetrePrincipale::slotRejouer()
{
	demarrerNouvellePartie();
}

void FenetrePrincipale::slotFinPartie(bool victoire)
{

	afficherFinPartie(victoire);
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

