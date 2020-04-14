#ifndef FENETREJEU_H
#define FENETREJEU_H

#include <QMainWindow>
#include <QtWidgets>
#include "burger.h"
#include "panneaucentral.h"
#include "panneaugauche.h"
#include "PanneauDroite.h"
#include <QKeyEvent>

class FenetreJeu : public QWidget
{
    Q_OBJECT

public:
	FenetreJeu(QWidget * parent=nullptr);
	~FenetreJeu();

	
	void demarrerNouvellePartie();
	
	void genererCommande(int nbrItem=5);
	void resume();

public slots:
     void pause();
	 void finPowerup();
	 void finPartie(bool victoire);
	 void slotTimer();
	 void activationPowerup(Condiment * powerup);


signals:
	void pauseSignal();
	void finPartieSignal(bool victoire);

private:
    QHBoxLayout *mainLayout;
    PanneauGauche *panneauGauche;
	PanneauDroite *panneauDroite;
    PanneauCentral *panneauCentral;
    QTimer *timer;
	Burger *commande;

	bool isPaused;

	
};
#endif // FENETREJEU_H
