#include "condiment.h"
#include <math.h>
#include <ctime>
#include <iostream>
#include <QTimer>
#include "Personnage.h"



Condiment::Condiment(bool isFalling, QGraphicsItem*parent):QObject(), QGraphicsPixmapItem()
{
	setSorte(static_cast<SorteCondiment>(rand() % (POWERUP+1)));
	//setSorte(Condiment::POWERUP);
	falling = isFalling;
}
Condiment::Condiment(Point p) {
	setPositionY(p.y);
	setPositionX(p.x);
	setSorte(static_cast<SorteCondiment>(rand() % (POWERUP)));
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
		// image est définis dans setSortePow
		setSortePow(static_cast<SortePowerup>(rand() % last));
		//imagePath += setSortePow(SortePowerup::RAINBOW);
		break;
	default:
		imagePath += "Erreur.png";
		break;
		
	}
	if (sorte != Condiment::POWERUP) setPixmap(QPixmap(imagePath.c_str()));
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

bool Condiment::getFalling()
{
	return falling;
}
void Condiment::setPosition(double x, double y)
{
	setPos(x, y);
	position = { x,y };
}
void Condiment::setPositionX(double x)
{
	setPos(x, y());
	position.x = x;
}
void Condiment::setPositionY(double y)
{
	setPos(x(), y);
	position.y = y;
}

double Condiment::getPositionX()
{
	return x();
}
double Condiment::getPositionY()
{
	return y();	
}

string Condiment::toString() const
{
	switch (sorte) {
	case Condiment::PAIN_H:
		return "Pain_Haut";
		break;
	case Condiment::PAIN_B:
		return "Pain_Bas";
		break;
	case Condiment::LAITUE:
		return "Laitue";
		break;
	case Condiment::TOMATE:
		return "Tomate";
		break;
	case Condiment::OIGNON:
		return "Oignon";
		break;
	case Condiment::BOULETTE:
		return "Viande";
		break;
	case Condiment::FROMAGE:
		return "Fromage";
		break;
	case Condiment::POWERUP:
	
		switch (sortePow) {
		case STAR:
			return "STAR";
			break;
		case RAINBOW:
			return "RAINBOW";
			break;
		case POTION:
			return "POTION"; 
			break;
		case CORONA:
			return "COVID-19";
			break;
		default:
			return "erreur";
			break;
	}
	}
}


//================================================================
//power up
//================================================================

void Condiment::setSortePow(SortePowerup sorte) {
	sortePow = sorte;
	string imagePath = ":/images/";
	switch (sorte) {
	case RAINBOW:
		imagePath += "Petit_Rainbow.png";
		break;
	case CORONA:
		imagePath += "Petit_Covid.png";
		break;
	case POTION:
		imagePath += "Petite_Potion.png";
		break;
	case STAR:
		imagePath += "Petite_etoile.png";
		break;
	default:
		imagePath += "Erreur.png";
		break;
		
	}
	setPixmap(QPixmap(imagePath.c_str()).scaled(50,50,Qt::KeepAspectRatio));

}
enum Condiment::SortePowerup Condiment::getSortePow() {
	return sortePow;
}
