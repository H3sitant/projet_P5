#ifndef PANNEAUGAUCHE_H
#define PANNEAUGAUCHE_H
#include <QtWidgets>
#include "burger.h"

class PanneauGauche : public QWidget
{
    Q_OBJECT
public:
	PanneauGauche(QMainWindow * parent=nullptr);
    void setPointage(int pointage);
    void setNbrVies(int nbr);
	void dessinerCommande(Burger commande);

public slots:
    void updateTemps(int temps);



private:
    QTimer *timer;
    QVBoxLayout *layoutPanneauGauche;
	QLabel* labelImageBurger;
	
	

};

#endif // PANNEAUGAUCHE_H
