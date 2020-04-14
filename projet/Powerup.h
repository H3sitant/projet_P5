#pragma once
#include "condiment.h"
class Powerup : public Condiment {
public:
	enum SortePowerup { STAR, RAINBOW, POTION, CORONA, last }; //Last doit rester en dernier
	Powerup(SortePowerup sorte, Point position);
	Powerup(SortePowerup sorte);
	Powerup();
	string toString() const;
	SortePowerup getSortePow();
	void setSortePow(SortePowerup sorte);

private:
	SortePowerup sortePow;
};

