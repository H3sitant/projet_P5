
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
	for (auto c : condiments) {
		if (c->getPositionY() == condiments.size()) {
			condiments.remove(c);
			break;
		}
	}
}
void Personnage::mixBurger()
{
	for (int i = 0; i < condiments.size(); i++) {
		int from = (rand() % condiments.size()) + 1; //Génère un nombre entre 1 et la hauteur de la liste.. ce qui représente une coordonnée y
		int to = (rand() % condiments.size()) + 1;
		if (from != to) {
			Condiment* first =nullptr;
			Condiment* second=nullptr;
			for (auto c : condiments)
			{
				if (c->getPositionY() == from) {
					first = c;
				}
				else if ((c->getPositionY() == to)) {
					second = c;
				}
			}
			//On échange la hauteur des deux
			if (first != nullptr && second != nullptr) {
				first->setPositionY(to);
				second->setPositionY(from);
			}
		}
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
            setX(x()-10);
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
            setX(x()+10);
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
