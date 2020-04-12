#pragma once
#include <ostream>
#include <QObject>
#include <QGraphicsPixmapItem>
#define bas 3
#define DROITE 1
#define GAUCHE 0
using namespace std;

struct Point {
    double x;
    double y;
};
class Condiment : public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
public:
	enum SorteCondiment { PAIN_H, PAIN_B, LAITUE, TOMATE, OIGNON, BOULETTE, FROMAGE, POWERUP }; //IMPORTANT: Powerup doit demeurer à la fin de l'enum
	enum SortePowerup { STAR, RAINBOW, POTION, CORONA, last }; //Last doit rester en dernier

	string setSortePow(SortePowerup sorte);
	SortePowerup getSortePow();
	Condiment(bool Isfalling, QGraphicsItem*parent=0);
	Condiment(Point p = { 0,0 });
	Condiment(SorteCondiment sorte, Point position);

	void setSorte(SorteCondiment sorte);
	SorteCondiment getSorte();

	void setFalling(bool isFalling);
	bool getFalling();
	void setPosition(double x, double y);
	
	double getPositionX();
	double getPositionY();

	void setPositionX(double x);
	void setPositionY(double y);

    bool operator==(const Condiment& c) const;
    Condiment& operator=(const Condiment& c);
private:
    SorteCondiment sorte;
	bool falling;
	Point position;
	SortePowerup sortePow;
};



