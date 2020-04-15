#ifndef PANNEAUCENTRAL_H
#define PANNEAUCENTRAL_H
#include <QGraphicsView>
#include "Personnage.h"
#include "Powerup.h"
#include "Condiment.h"
#include <QTimer>
#include "burger.h"


#define Grosseur_liste 20
#define Speed 10
#define DelayFall 20 // 1=50 milliseconde

//modifier la taille de la liste avec le score ->  score + 2 < 10 ? liste_longeur = (score + 2):liste_longeur=(9);

class PanneauCentral : public QGraphicsView
{
	Q_OBJECT
public:
    PanneauCentral(Burger *commande, QWidget*parent = nullptr);
    const int LARGEUR = 500;
    const int HAUTEUR = 720;
	void finPowerups();
	void verifierPowerups();
	void activerRainbow();
	void activerPower(Condiment *powerup);
	void demarrerNouvellePartie();
	void pause();

	void resume();

public slots:
	 void CheckPosition();
	 
	 void FC();

signals:
	void pauseSignal();
	void finPartie(bool victoire);
	void powerupActive( Condiment *powerup);

private:
	QWidget *parent;
	Burger* commande;
    QGraphicsScene* scene;
    //void resizeEvent(QResizeEvent *event);
    Personnage *player;
    void keyPressEvent(QKeyEvent *event);
	list<Condiment*> FallingCondiments;
	int delayFalling;
	bool finduJeux;
	QTimer * timer;
	char powerUpActif = NULL;
	static const int TEMPS_MAX_POWERUP = 10;
	static const int PROBPOWERUP = 2;
	static const int PROB_CORONA = 5;
	int largeurCapter = 10;
	int tailleRecette;
	bool victoire;
};

#endif // PANNEAUCENTRAL_H
