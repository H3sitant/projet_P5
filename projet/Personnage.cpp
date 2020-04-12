
#include "Personnage.h"
using namespace std;
#include <iostream>
#include <QDebug>

Personnage::Personnage(int positionX,int positionY, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPos(positionX,positionY);
	Hight = 130;
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
list<Condiment*> Personnage::getCondiments()
{
	return condiments;
}

void Personnage::retirerTop() {
	list<Condiment*> cpyFalling2(condiments);
	for (Condiment* c2 : cpyFalling2)
	{
		if (c2 == condiments.back())
		{
			condiments.remove(c2);
			delete c2;
		}
	}
	Hight -= 20;
}
void Personnage::mixBurger()
{
	list<Condiment*> newcondiments;
	double newHight= 150;
	newcondiments.push_back(condiments.front());
	condiments.remove(condiments.front());
	int itration = condiments.size();
	for (int i = 0; i < itration; i++)
	{
		int from = rand() % condiments.size();
		int j=0;
		list<Condiment*> cpyFalling(condiments);
		for (Condiment* c : cpyFalling)
		{
			if (j == from)
			{
				newcondiments.push_back(c);
				c->setPositionY(500 - newHight);
				newHight += 20;
				condiments.remove(c);
			}
			j++;
		}
	}
	condiments.clear();
	for (Condiment* c : newcondiments)
	{
		condiments.push_back(c);
	}

}
void Personnage::setCondiments(list<Condiment*> newCondiments)
{
	condiments = newCondiments;
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
	
	for(Condiment* c : condiments) {
		c->setPositionX(x());
	}
}
size_t Personnage::getHauteurBurger()
{
	return condiments.size()+1;
}

std::ostream& operator<<(ostream& out, Personnage p) {
	out << p.toString();
	return out;
}

char Personnage::toString() {
	return '#';
}
void Personnage::ajouterCondiment(Condiment* c) {
	condiments.push_back(c);
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
void Personnage::setHauteur(int newH)
{
	list<Condiment*> newcondiments;
	condiments.clear();
	cout << condiments.size() << endl;
	condiments = newcondiments;
}

double Personnage::getHight()
{
	return Hight;
}

void Personnage::setmovementSpeed(int speed)
{
	moveSpeed = speed;
}