#ifndef PANNEAUDROITE_H
#define PANNEAUDROITE_H
#include <QtWidgets>
#include "Powerup.h"
#include "fenetrejeu.h"

class PanneauDroite : public QWidget

{
    Q_OBJECT
public:
    PanneauDroite(FenetreJeu * parent=nullptr);
	void dessinerPowerup(const Powerup & powerup);

public slots:

    void endPowerup();



private:
    QTimer *timer;
    QVBoxLayout *layoutPanneauDroite;
    QPushButton *boutonMenu;
    QLabel *labelPowerup;
    QLabel *labelImagePowerup;
    QLabel *labelTempsPowerup;
	FenetreJeu *parent;
};

#endif // PANNEAUDROITE_H
