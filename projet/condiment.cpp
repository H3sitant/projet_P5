#include "condiment.h"
#include <math.h>
#include <ctime>
#include <iostream>
#include <QTimer>
#include "Personnage.h"



Condiment::Condiment(bool isFalling, QGraphicsItem*parent):QObject(), QGraphicsPixmapItem()
{
	setSorte(static_cast<SorteCondiment>(rand() % POWERUP));
	falling = isFalling;
	if (falling)
	{
		QTimer * timer = new QTimer();
		connect(timer, SIGNAL(timeout()), this, SLOT(dropCondiments()));
		timer->start(50);
	}
}
Condiment::Condiment(Point p) {
	setPositionY(p.y);
	setPositionX(p.x);
	setSorte(static_cast<SorteCondiment>(rand() % POWERUP));
}

Condiment::Condiment(SorteCondiment sorte, Point position) {
	setSorte(sorte);
	setPositionY(position.y);
	setPositionX(position.x);
}


enum Condiment::SorteCondiment Condiment::getSorte()
{
    return sorte;
}

void Condiment::setSorte(SorteCondiment sorte)
{
    this->sorte = sorte;
	string imagePath = ":/images/";
	switch (sorte)
	{
	case Condiment::PAIN_H:
		imagePath += "Pain_Haut.png";
		break;
	case Condiment::PAIN_B:
		imagePath += "Pain_Bas.png";
		break;
	case Condiment::LAITUE:
		imagePath += "Laitue.png";
		break;
	case Condiment::TOMATE:
		imagePath += "Tomate.png";
		break;
	case Condiment::OIGNON:
		imagePath += "Oignon.png";
		break;
	case Condiment::BOULETTE:
		imagePath += "Viande.png";
		break;
	case Condiment::FROMAGE:
		imagePath += "Fromage.png";
		break;
	case Condiment::POWERUP:
		// image est définis dans Powerup.cpp
		break;
	default:
		imagePath += "Erreur.png";
		break;
		
	}
	if(sorte!= Condiment::POWERUP) setPixmap(QPixmap(imagePath.c_str()));

}

bool Condiment::operator==(const Condiment& c) const
{
    return (this->sorte == c.sorte);
}

Condiment& Condiment::operator=(const Condiment& c) {
    sorte = c.sorte;
    return *this;
}

void Condiment::setFalling(bool isFalling)
{
	falling = isFalling;
}
void Condiment::setPosition(int x, int y)
{
	setPos(x, y);
}
void Condiment::setPositionX(int x)
{
	setPos(x, y());
}
void Condiment::setPositionY(int y)
{
	setPos(x(), y);
}

int Condiment::getPositionX()
{
	return x();
}
int Condiment::getPositionY()
{
	return y();
	
}

void Condiment::dropCondiments()
{
	setPos(x(),y() + 10);
	if (y() > 500)
	{
		delete this;
	}
}
