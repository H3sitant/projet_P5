#ifndef PANNEAUGAUCHE_H
#define PANNEAUGAUCHE_H
#include <QtWidgets>
#include "burger.h"

/*
Panneau gauche de la fen�tre de jeu
Afficher les informations quant � l'�volution de la partie
(Points, vie, commande et temps restant)
*/

class PanneauGauche : public QWidget
{
    Q_OBJECT
public:
	PanneauGauche(Burger *commande, QWidget * parent=nullptr);
    void setPointage(int pointage);
    void setNbrVies(int nbr);
	void dessinerCommande();
	void diminuerTemps();
	void setTemps(int temps);
	int getTemps();




private:
    QTimer *timer;
    QVBoxLayout *layoutPanneauGauche;
	QLabel* labelImageBurger;
	Burger*commande;
	int temps=180;
	QLabel *labelTemps;

	

};

#endif // PANNEAUGAUCHE_H
