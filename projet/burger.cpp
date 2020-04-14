#include "burger.h"

Burger::Burger()
{

}

void Burger::ajouterCondiment(Condiment* condiment) {
	condiments.push_back(condiment);
}

QPixmap Burger::getBurgerPixmap()
{
	int finalHeight = 48 + 24 * (condiments.size()-1) - 8 * (condiments.size() - 1); //Pain du haut = 48 pixel de haut et les autres 24 pix - superposition de 8 pixels
	int finalWidth = 120;
	QPixmap finalImage(finalWidth, finalHeight);
	finalImage.fill(Qt::transparent);
	QPainter painter(&finalImage);
	int nextHeight = finalHeight-24;
	for (Condiment* c : condiments) {
		if (c->getSorte() == Condiment::PAIN_H)  nextHeight -= 40 - 16;
		//else if (c->getSorte() == Condiment::LAITUE) nextHeight += 8; //la laitue dois être placé plus bas
		painter.drawPixmap(0, nextHeight, c->pixmap());
		nextHeight -= 16;
	}
	return finalImage;
}

void Burger::viderBurger() {
	condiments.clear();
}

void Burger::retirerTop() {
	condiments.erase(condiments.end()-1);
}

vector<Condiment*> Burger::getCondiments() {
	return condiments;
}


//Mélange le burger aléatoirement, mais épargne le premier condiment
void Burger::mixBurger()
{
	
	
	//condiments.remove(condiments.front());
	for (int i = 0; i < condiments.size(); i++) {
		int from = (rand() % (condiments.size()-1))+1;
		int to = (rand() % (condiments.size()-1))+1;
		Condiment* temp = condiments[from];
		condiments[from] = condiments[to];
		condiments[to] = temp;
		int ytemp = condiments[from]->y();
		condiments[from]->setY(condiments[to]->y());
		condiments[to]->setY(ytemp);
	
	}
	

}

 bool Burger::operator==( Burger other) {
	if (this->getCondiments().size() == other.getCondiments().size()) {
		for (int i = 0; i < this->getCondiments().size(); i++) {
			if(this->getCondiments()[i]->getSorte() != other.getCondiments()[i]->getSorte()) return false;
		}
		return true;
	}
	return false;
}
