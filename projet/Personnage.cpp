
#include "Personnage.h"
using namespace std;
#include <iostream>
#include <QDebug>

Personnage::Personnage(int positionX,int positionY, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPos(positionX,positionY);
	Hight = 130;
	burger = new Burger();
}
Personnage::~Personnage()
{

}
int Personnage::getPosition()
{
	return position;
}
void Personnage::setPosition(int newPosition)
{
	position = newPosition;
	setPos(newPosition,y());
}
Burger* Personnage::getBurger()
{
	return burger;
}

void Personnage::viderBurger()
{
	burger->viderBurger();
}

void Personnage::retirerTop() {
	burger->retirerTop();
	Hight -= 20;
}

void Personnage::setBurger(Burger * burger)
{
	this->burger = burger;
}


void Personnage::deplacer(int direction, int largeur)
{
   int largeurPersonnage = pixmap().width();

    if (direction == GAUCHE)
	{
        if (x()<= 0)
		{
            setX( largeur - largeurPersonnage);
		}
		else
		{
            setX(x()-moveSpeed);
		}
	}
	else
	{
        if (x() >= largeur - largeurPersonnage)
		{
            setX(0);
		}
		else
		{
            setX(x()+ moveSpeed);
		}
	}
	
	for(Condiment* c : burger->getCondiments()) {
		c->setPositionX(x());
	}
}


std::ostream& operator<<(ostream& out, Personnage p) {
	out << p.toString();
	return out;
}

char Personnage::toString() {
	return '#';
}
void Personnage::ajouterCondiment(Condiment* c) {
	burger->ajouterCondiment(c);
	if (c->getSorte() == Condiment::PAIN_H)Hight += 20;
	Hight += 20;
}
/*Personnage Personnage::copy()
{
	Personnage copy;
	copy.setPosition(this->position);
	list<Condiment*> c(condiments);
	copy.setCondiments(c);
	return copy;
}*/


double Personnage::getHight()
{
	return Hight;
}

void Personnage::setmovementSpeed(int speed)
{
	moveSpeed = speed;
}