#pragma once
#include <qgraphicsview.h>
#include <QWidget>
#include <QLabel>
#include <qpushbutton.h>


//Fenetre de fin de partie
//Modulable selon la victoir/défaite du joueur
class MenuFinPartie :
	public QGraphicsView

{
	Q_OBJECT

public:
	MenuFinPartie(QWidget * parent, bool victoire=true);

	QPixmap setImage(QString chemin, int width, int height);

	void setPoint(int point);

	void setVictoire(bool victoire);

 signals:
	void boutonMenuClicked();
	void boutonRejouerClicked();

private slots:
	void slotBoutonMenu();
	void slotBoutonRejouer();



private:
	QLabel* labelPoints;
	QGraphicsScene* scene;
	QGraphicsPixmapItem * imageFin;
	QPixmap imageVictoire;
	QPixmap imageDefaite;
	int xPos;
	int yPos;
};

