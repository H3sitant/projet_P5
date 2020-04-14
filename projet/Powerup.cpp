#include "Powerup.h"
#include <iostream>


Powerup::Powerup(SortePowerup sorte, Point position) : Condiment(SorteCondiment::POWERUP, position) {
	setSortePow(sorte);
	setPosition(position.x, position.y);
}
Powerup::Powerup() : Condiment(SorteCondiment::POWERUP, { 0,0 }) {
	setSortePow(static_cast <SortePowerup>(rand() % last));
}
Powerup::Powerup(SortePowerup sorte) : Condiment(SorteCondiment::POWERUP) {
	setSortePow(sorte);
}
Powerup::SortePowerup Powerup::getSortePow() {
	return sortePow;
}
void Powerup::setSortePow(SortePowerup sorte) {
	sortePow = sorte;
	string imagePath = ":/images/";
	switch (sorte) {
	case RAINBOW:
		imagePath += "Rainbow.png";
		break;
	case CORONA:
		imagePath += "Covid.png";
		break;
	case POTION:
		imagePath += "Potion.png";
	case STAR:
	default:
		imagePath += "Erreur.png";
		break;

	}
	setPixmap(QPixmap(imagePath.c_str()));
}

string Powerup::toString() const
{
	switch (sortePow) {
	case STAR:
		return "STAR";
		break;
	case RAINBOW:
		return "RAINBOW";
		break;
	case POTION:
		return "POTION"; //Comme dans magique
		break;
	case CORONA:
		return "COVID-19";
		break;
	default:
		return "erreur";
		break;
	}
}
