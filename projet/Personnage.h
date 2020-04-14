#pragma once
#include "condiment.h"
#include <list>
#include <QGraphicsPixmapItem>
#include "burger.h"
using namespace std;
class Personnage: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
	int position;
	Burger* burger;
	double Hight;
	int moveSpeed=10;

public:
    Personnage(int positionX=0, int positionY=0,QGraphicsItem *parent=nullptr);
	~Personnage();
	int getPosition();
	void setPosition(int newPosition);
	Burger* getBurger();
	void viderBurger();
	void retirerTop();
	void setBurger(Burger *burger);
	void deplacer(int direction, int largeur);
    size_t getHauteurBurger();
	char toString();
	void ajouterCondiment(Condiment* c);
	//Personnage copy();
	friend ostream& operator<<(ostream& out, Personnage p);
	void setHauteur(int newH);	
	double getHight();

	void setmovementSpeed(int speed);
	
};

