#pragma once
#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QStackedWidget>
#include "MenuFinPartie.h"
#include "fenetrejeu.h"

/*Fenêtre principale de l'application
* C'est elle qui contient tous les widget
* Et s'occupe de la transition entre ceux-ci*/
class FenetrePrincipale : public QStackedWidget
{
	Q_OBJECT
public:
	FenetrePrincipale(QWidget *parent=nullptr);

	void afficherJeu();
	void afficherMenuPrincipal();
	void retour();
	
	void afficherInstructions();

	void demarrerNouvellePartie();
	
	void afficherFinPartie(bool victoire);

public slots:
	void slotAfficherMenuPrincipal();
	void slotAfficherMenuPause();
	void slotProchainNiveau();
	void slotRejouer();
	void slotFinPartie(bool victoire);

private:
	FenetreJeu *jeu;
	QWidget* menuPrincipal;
	QWidget* menuPause;
	QWidget* instructions;
	MenuFinPartie* finPartie;
	int lastWidgetId=0;

};
#endif // FENETREPRINCIPALE_H
