#ifndef PANNEAUCENTRAL_H
#define PANNEAUCENTRAL_H
#include <QGraphicsView>
#include "Personnage.h"
#include "Condiment.h"


#define Grosseur_liste 20
#define Speed 10
#define DelayFall 20 // 1=50 milliseconde

//modifier la taille de la liste avec le score ->  score + 2 < 10 ? liste_longeur = (score + 2):liste_longeur=(9);

class PanneauCentral : public QGraphicsView
{
	Q_OBJECT
public:
    PanneauCentral();
	void SetRecette(int taille);
    const int LARGEUR = 500;
    const int HAUTEUR = 500;

public slots:
     void droite();
     void gauche();
     void timeTick();
	 void CheckPosition();
	 void FC();

private:
    QGraphicsScene* scene;
    //void resizeEvent(QResizeEvent *event);
    Personnage *player;
    void keyPressEvent(QKeyEvent *event);
	Condiment recette[Grosseur_liste];
	list<Condiment*> FallingCondiments;
	int delayFalling;
	bool finduJeux;
};

#endif // PANNEAUCENTRAL_H
