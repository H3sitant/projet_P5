#pragma once
#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QStackedWidget>


class FenetrePrincipale : public QStackedWidget
{
	Q_OBJECT
public:
	FenetrePrincipale(QWidget *parent=nullptr);

	void afficherJeu();
	void afficherMenuPrincipal();
	void afficherMenuPause();
	void afficherInstructions();
	void demarrerNouvellePartie();

private:
	QWidget *jeu;
	QWidget* menuPrincipal;
	QWidget* menuPause;

};
#endif // FENETREPRINCIPALE_H
