#pragma once
#include <qgraphicsview.h>
#include <QWidget>
#include <QLabel>
#include <qpushbutton.h>


class MenuFinPartie :
	public QGraphicsView
{
public:
	MenuFinPartie(QWidget * parent, bool victoire=true);

	QPixmap setImage(QString chemin, int width, int height);

	void setPoint(int point);

	void setVictoire(bool victoire);


private:
	QLabel* labelPoints;
	QGraphicsScene* scene;
	QGraphicsPixmapItem * imageFin;
	QPixmap imageVictoire;
	QPixmap imageDefaite;
	int xPos;
	int yPos;
};

