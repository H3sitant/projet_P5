#ifndef PANNEAUGAUCHE_H
#define PANNEAUGAUCHE_H
#include <QtWidgets>
#include "burger.h"

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
