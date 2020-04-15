#include "MenuFinPartie.h"
#include <QGraphicsPixmapItem>
#include "FenetrePrincipale.h"

MenuFinPartie::MenuFinPartie(QWidget * parent, bool victoire):QGraphicsView(parent)
{
	// Configuration de l'ecran
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(1280, 720);

	// Configuration et affichage de la scene
	scene = new QGraphicsScene;
	//scene->setBackgroundBrush(QBrush(setImage("./Images/Fond_Fin.png", 1600, 900)));
	scene->setSceneRect(0, 0, 1280, 720);
	setScene(scene);
	// Donnée qui va provenir du jeu
	int points = 150;
	xPos = this->width() / 2;
	yPos = this->height() / 2;
	QLabel * labelPoints = new QLabel("Points : " + QString::number(points));
	labelPoints->setStyleSheet("background-color: rgba(0,0,0,0%)");
	labelPoints->setGeometry((xPos / 2 + 30) - (labelPoints->width() / 2), yPos - 130, labelPoints->width(), 50);
	scene->addWidget(labelPoints);

	QPushButton * boutonRejouer = new QPushButton("REJOUER");
	boutonRejouer->setGeometry((xPos / 2 + 30) - 130, yPos, 260, 50);
	connect(boutonRejouer, &QPushButton::clicked, this, &MenuFinPartie::slotBoutonRejouer);
	scene->addWidget(boutonRejouer);

	QPushButton * boutonRetour = new QPushButton("MENU PRINCIPAL");
	boutonRetour->setGeometry((xPos / 2 + 30) - 250, yPos + 75, 500, 50);
	connect(boutonRetour, &QPushButton::clicked, this, &MenuFinPartie::slotBoutonMenu);
	scene->addWidget(boutonRetour);

	imageFin = new QGraphicsPixmapItem;
	imageVictoire = setImage(":/images/Grosse_Licorne.png", 600, 636);
	imageDefaite = setImage(":/images/Grosse_Licorne_Triste.png", 600, 442);
	scene->addItem(imageFin);
	setVictoire(victoire);
}

QPixmap MenuFinPartie::setImage(QString chemin, int width, int height)
{
	QPixmap image(chemin);
	image = image.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	return image;
}

void MenuFinPartie::setPoint(int point) {
	
}

void MenuFinPartie::setVictoire(bool victoire) {
	if (victoire) {
		imageFin->setPixmap(imageVictoire);
		imageFin->setPos(xPos - 50, this->height() - imageFin->boundingRect().height());
	}
	else {
		imageFin->setPixmap(imageDefaite);
		imageFin->setPos(xPos - 50, imageFin->boundingRect().height() / 2 - 60);
	}
}

void MenuFinPartie::slotBoutonRejouer()
{
	emit boutonRejouerClicked();
}

void MenuFinPartie::slotBoutonMenu()
{
	emit boutonMenuClicked();
}
