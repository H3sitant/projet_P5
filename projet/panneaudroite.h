#ifndef PANNEAUDROITE_H
#define PANNEAUDROITE_H
#include <QtWidgets>
#include "Powerup.h"

class PanneauDroite : public QWidget

{
    Q_OBJECT
public:
    PanneauDroite();
	void dessinerPowerup(const Powerup & powerup);

public slots:
    void slotBoutonMenu();
    void endPowerup();



private:
    QTimer *timer;
    QVBoxLayout *layoutPanneauDroite;
    QPushButton *boutonMenu;
    QLabel *labelPowerup;
    QLabel *labelImagePowerup;
    QLabel *labelTempsPowerup;
};

#endif // PANNEAUDROITE_H
