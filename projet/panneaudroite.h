#ifndef PANNEAUDROITE_H
#define PANNEAUDROITE_H
#include <QtWidgets>
#include "Powerup.h"

//Panneau droite de la fenêtre de jeu
//Contient les informations quant au powerup actif
//Ainsi qu'un bouton pause
class PanneauDroite : public QWidget

{
    Q_OBJECT
public:
    PanneauDroite(QWidget * parent=nullptr);

	int getTempsPowerup();

	void setPowerupActif(Condiment * powerup);
	void diminuerTempsPowerup();
	void viderCase();
	void reset();

public slots: 
	void slotBoutonMenu();

signals:
	void boutonMenuClicked();
	void finPowerupSignal();


private:
    QTimer *timer;
    QVBoxLayout *layoutPanneauDroite;
    QPushButton *boutonMenu;
    QLabel *labelPowerup;
    QLabel *labelImagePowerup;
    QLabel *labelTempsPowerup;
	QProgressBar* progressBar;

	void setTempsPowerup(int temps);
	void dessinerPowerup(Condiment * powerup);
	void ecrirePowerup(string sorte);
	void finPowerup();
	int temps;
};

#endif // PANNEAUDROITE_H


