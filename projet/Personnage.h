#pragma once
#include "condiment.h"
#include <list>
#include <QGraphicsPixmapItem>
using namespace std;
class Personnage: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
	int position;
	list<Condiment*> condiments;

public:
    Personnage(int positionX=0, int positionY=0,QGraphicsItem *parent=nullptr);
	~Personnage();
	int getPosition();
	void setPosition(int newPosition);
	list<Condiment*> getCondiments();
	void retirerTop();
	void mixBurger();
	void setCondiments(list<Condiment*> condiments);
	void deplacer(int direction, int largeur);
    size_t getHauteurBurger();
	char toString();
	void ajouterCondiment(Condiment* c);
	//Personnage copy();
	friend ostream& operator<<(ostream& out, Personnage p);
	void setHauteur(int newH);	
};

