#pragma once
#include <ostream>
#include <QObject>
#include <QGraphicsPixmapItem>
#define bas 3
#define DROITE 1
#define GAUCHE 0
using namespace std;

struct Point {
    int x;
    int y;
};
class Condiment : public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
public:
	enum SorteCondiment { PAIN_H, PAIN_B, LAITUE, TOMATE, OIGNON, BOULETTE, FROMAGE, POWERUP }; //IMPORTANT: Powerup doit demeurer à la fin de l'enum

	Condiment(bool Isfalling, QGraphicsItem*parent=0);
	Condiment(Point p = { 0,0 });
	Condiment(SorteCondiment sorte, Point position);

	void setSorte(SorteCondiment sorte);
	SorteCondiment getSorte();

	void setFalling(bool isFalling);
	void setPosition(int x, int y);
	
	int getPositionX();
	int getPositionY();

	void setPositionX(int x);
	void setPositionY(int y);

    bool operator==(const Condiment& c) const;
    Condiment& operator=(const Condiment& c);

public slots:
	void dropCondiments();
private:
    SorteCondiment sorte;
	bool falling;
};



