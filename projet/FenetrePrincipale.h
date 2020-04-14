#pragma once
#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QStackedWidget>
#include "MenuFinPartie.h"


class FenetrePrincipale : public QStackedWidget
{
	Q_OBJECT
public:
	FenetrePrincipale(QWidget *parent=nullptr);

	void afficherJeu();
	void afficherMenuPrincipal();
	void retour();
	void afficherMenuPause();
	void afficherInstructions();
	void demarrerNouvellePartie();
	void afficherFinPartie(bool victoire);

public slots:
	void slotAfficherMenuPrincipal();
	void slotProchainNiveau();
	void slotRejouer();

private:
	QWidget *jeu;
	QWidget* menuPrincipal;
	QWidget* menuPause;
	QWidget* instructions;
	MenuFinPartie* finPartie;
	int lastWidgetId=0;

};
#endif // FENETREPRINCIPALE_H
