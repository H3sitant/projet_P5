/*
*   Ce programme teste l'interface
*	Coralie Grégoire
*/

#include "instructions.h"

Instructions::Instructions(FenetrePrincipale *parent)
	: QWidget(parent)
{
	this->parent = parent;
	QVBoxLayout *mainLayout = new QVBoxLayout;
	QGridLayout *gridcommande = new QGridLayout;
	QGridLayout *grid = new QGridLayout;

	directives = new QLabel("Attrapez les ingredients pour creer des burgers!");
	directives->setAlignment(Qt::AlignCenter);
	commandes = new QLabel("Touches de commande");
	commandes->setAlignment(Qt::AlignCenter);
	gauche = new QLabel("Deplacement a gauche");
	droite = new QLabel("Deplacement a droite");
	pause = new QLabel("Mettre le jeu en pause");
	powerups = new QLabel("Objets speciaux");
	powerups->setAlignment(Qt::AlignCenter);
	arc = new QLabel("Tous les ingredients deviennent ceux dont vous avez besoin pendant un certain temps");
	potion = new QLabel("Permet de retirer le dernier element du burger");
	etoile = new QLabel("Deplacement plus rapide");
	corona = new QLabel("Deplacement plus lent");
	quitterI = new QPushButton("Quitter");
	
	QLabel *imageBurger = new QLabel();
	imageBurger->setAlignment(Qt::AlignCenter);
	QLabel *imageGauche = new QLabel();
	QLabel *imageDroite = new QLabel();
	QLabel *imagePause = new QLabel();
	QLabel *imageArc = new QLabel();
	QLabel *imagePotion = new QLabel();
	QLabel *imageEtoile = new QLabel();
	QLabel *imageCorona = new QLabel();


	QPixmap pixmap(":/images/Burger_Complet.png");
	//hamburger.fill();
	imageBurger->setPixmap(pixmap.scaled(100,100,Qt::KeepAspectRatio));
	pixmap.load(":/images/Fleche_Gauche.png");
	imageGauche->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));
	imageDroite->setPixmap(pixmap);
	imagePause->setPixmap(pixmap);
	imageArc->setPixmap(pixmap);
	imagePotion->setPixmap(pixmap);
	imageEtoile->setPixmap(pixmap);
	imageCorona->setPixmap(pixmap);

	this->setLayout(mainLayout);

	mainLayout->addWidget(directives);
	mainLayout->addWidget(imageBurger);
	
	mainLayout->addStretch();
	mainLayout->addWidget(commandes);
	mainLayout->addLayout(gridcommande);
	gridcommande->addWidget(gauche, 0, 0, Qt::AlignCenter);
	gridcommande->addWidget(droite, 0, 1, Qt::AlignCenter);
	gridcommande->addWidget(pause, 0, 2, Qt::AlignCenter);
	gridcommande->addWidget(imageGauche, 1, 0, Qt::AlignCenter);
	gridcommande->addWidget(imageDroite, 1, 1, Qt::AlignCenter);
	gridcommande->addWidget(imagePause, 1, 2, Qt::AlignCenter);

	mainLayout->addStretch();
	mainLayout->addWidget(powerups);
	mainLayout->addLayout(grid);
	grid->addWidget(imageArc, 0, 0, Qt::AlignCenter);
	grid->addWidget(arc, 0, 1);
	grid->addWidget(imagePotion, 1, 0, Qt::AlignCenter);
	grid->addWidget(potion, 1, 1);
	grid->addWidget(imageEtoile, 2, 0, Qt::AlignCenter);
	grid->addWidget(etoile, 2, 1);
	grid->addWidget(imageCorona, 3, 0, Qt::AlignCenter);
	grid->addWidget(corona, 3, 1);
	mainLayout->addStretch();
	mainLayout->addWidget(quitterI);
	createMenu();
}

void Instructions::quitter() {
	printf("quitter");
	parent->afficherMenuPrincipal();
}


void Instructions::createMenu() {
	connect(quitterI, &QPushButton::clicked, this, &Instructions::quitter);
}