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

public slots:
    void updateTemps(int temps);



private:
    QTimer *timer;
    QVBoxLayout *layoutPanneauGauche;
	QLabel* labelImageBurger;
	Burger*commande;
	

	

};

#endif // PANNEAUGAUCHE_H
