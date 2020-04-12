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
		else if (c->getSorte() == Condiment::LAITUE) nextHeight += 8; //la laitue dois être placé plus bas
		painter.drawPixmap(0, nextHeight, c->pixmap());
		nextHeight -= 16;
	}
	return finalImage;
}
