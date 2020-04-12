#ifndef BURGER_H
#define BURGER_H

#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <list>
#include "Condiment.h"

class Burger 
{
    
public:
    Burger();
	void ajouterCondiment(Condiment * condiment);
	QPixmap getBurgerPixmap();
private:
	list<Condiment*> condiments;
};

#endif // BURGER_H
