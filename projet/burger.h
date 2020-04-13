#ifndef BURGER_H
#define BURGER_H

#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <vector>
#include "Condiment.h"

class Burger 
{
    
public:
    Burger();
	void ajouterCondiment(Condiment * condiment);
	vector<Condiment*> getCondiments();
	void mixBurger();
	void retirerTop();
	QPixmap getBurgerPixmap();
	void viderBurger();
	
private:
	vector<Condiment*> condiments;
};

#endif // BURGER_H
