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
	QWidget *instructionsJeu = new QWidget();
	instructionsJeu->setLayout(grid);
	QPalette pal = QPalette();
	pal.setColor(QPalette::Background, QColor(0, 0, 0, 100));
	instructionsJeu->setAutoFillBackground(true);
	instructionsJeu->setPalette(pal);

	directives = new QLabel("Attrapez les ingredients pour creer des burgers!");
	directives->setAlignment(Qt::AlignCenter);
	commandes = new QLabel("Controles");
	commandes->setAlignment(Qt::AlignCenter);
	gauche = new QLabel("Gauche");
	droite = new QLabel("Droite");
	pause = new QLabel("Pause");
	powerups = new QLabel("Objets speciaux");
	powerups->setAlignment(Qt::AlignCenter);
	arc = new QLabel("Tous les ingredients deviennent ceux dont vous avez\nbesoin pendant un certain temps");
	potion = new QLabel("Retire le dernier element du burger");
	etoile = new QLabel("Deplacement plus rapide pour un temps limite");
	corona = new QLabel("Fait le bordel et melange le burger!");
	quitterI = new QPushButton("Retour");
	quitterI->setStyleSheet("QPushButton{background-color: rgba(0,0,0,80)} QPushButton:hover{background-color: rgba(0,0,0,100)}");
	
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
	imageBurger->setPixmap(pixmap.scaled(100,100,Qt::KeepAspectRatio));
	pixmap.load(":/images/Fleche_Gauche.png");
	imageGauche->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));
	pixmap.load(":/images/Fleche_Droite.png");
	imageDroite->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));
	pixmap.load(":/images/Bouton_Pause.png");
	imagePause->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));
	pixmap.load(":/images/Rainbow.png");
	imageArc->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));
	pixmap.load(":/images/Potion.png");
	imagePotion->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));
	pixmap.load(":/images/etoile.png");
	imageEtoile->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));
	pixmap.load(":/images/Covid.png");
	imageCorona->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));

	this->setLayout(mainLayout);

	mainLayout->addWidget(directives);
	mainLayout->addWidget(imageBurger);
	
	mainLayout->addStretch();
	mainLayout->addWidget(commandes);
	mainLayout->addSpacing(10);
	mainLayout->addLayout(gridcommande);
	gridcommande->addWidget(gauche, 1, 0, Qt::AlignCenter);
	gridcommande->addWidget(droite, 1, 1, Qt::AlignCenter);
	gridcommande->addWidget(pause, 1, 2, Qt::AlignCenter);
	gridcommande->addWidget(imageGauche, 0, 0, Qt::AlignCenter);
	gridcommande->addWidget(imageDroite, 0, 1, Qt::AlignCenter);
	gridcommande->addWidget(imagePause, 0, 2, Qt::AlignCenter);

	mainLayout->addStretch();
	mainLayout->addSpacing(20);
	mainLayout->addWidget(powerups);
	mainLayout->addSpacing(10);
	mainLayout->addWidget(instructionsJeu);
	
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
	mainLayout->addSpacing(20);
	createMenu();
}

void Instructions::retour() {
	printf("Retour");
	parent->retour();
}


void Instructions::createMenu() {
	connect(quitterI, &QPushButton::clicked, this, &Instructions::retour);
}