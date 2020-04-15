/*
*   Ce programme teste l'interface
*	Coralie Grégoire
*/

#include "instructions.h"

Instructions::Instructions(FenetrePrincipale *parent)
	: QWidget(parent)
{
	this->parent = parent;
	this->setStyleSheet("QLabel { font-size: 20px; }");

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
	directives->setStyleSheet(" font: 25px; ");
	directives->setAlignment(Qt::AlignCenter);

	commandes = new QLabel("Controles");
	commandes->setStyleSheet("font: 25px;");
	commandes->setAlignment(Qt::AlignCenter);

	gauche = new QLabel("Gauche");
	droite = new QLabel("Droite");
	pause = new QLabel("Pause");

	powerups = new QLabel("Objets speciaux");
	powerups->setStyleSheet("font: 25px;");
	powerups->setAlignment(Qt::AlignCenter);

	arc = new QLabel("Les ingredients sont ceux dont vous avez besoin pendant un certain temps");
	arc->setAlignment(Qt::AlignLeft);
	potion = new QLabel("Retire le dernier element du burger");
	etoile = new QLabel("Deplacement plus rapide pour un temps limite");
	corona = new QLabel("Fait le bordel et melange le burger!");
	quitterI = new QPushButton("Retour");
	quitterI->setStyleSheet("QPushButton{ font-size: 30px; background-color: rgba(0,0,0,80)} QPushButton:hover{background-color: rgba(0,0,0,100)} ");
	quitterI->setFixedHeight(45);
	
	QLabel *imageBurger = new QLabel();
	imageBurger->setAlignment(Qt::AlignCenter);
	QLabel *imageGauche = new QLabel();
	QLabel *imageDroite = new QLabel();
	QLabel *imagePause = new QLabel();
	QLabel *imageArc = new QLabel();
	QLabel *imagePotion = new QLabel();
	QLabel *imageEtoile = new QLabel();
	QLabel *imageCorona = new QLabel();


	QPixmap pixmap(":/images/Modele_Burger.png");
	imageBurger->setPixmap(pixmap.scaled(90,90,Qt::KeepAspectRatio));
	pixmap.load(":/images/Fleche_Gauche.png");
	imageGauche->setPixmap(pixmap.scaled(60, 60, Qt::KeepAspectRatio));
	pixmap.load(":/images/Fleche_Droite.png");
	imageDroite->setPixmap(pixmap.scaled(60, 60, Qt::KeepAspectRatio));
	pixmap.load(":/images/Bouton_Pause.png");
	imagePause->setPixmap(pixmap.scaled(60, 60, Qt::KeepAspectRatio));
	pixmap.load(":/images/Rainbow.png");
	imageArc->setPixmap(pixmap.scaled(60, 60, Qt::KeepAspectRatio));
	pixmap.load(":/images/Potion.png");
	imagePotion->setPixmap(pixmap.scaled(60, 60, Qt::KeepAspectRatio));
	pixmap.load(":/images/etoile.png");
	imageEtoile->setPixmap(pixmap.scaled(60, 60, Qt::KeepAspectRatio));
	pixmap.load(":/images/Covid.png");
	imageCorona->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));

	this->setLayout(mainLayout);

	mainLayout->addSpacing(5);
	mainLayout->addWidget(directives);
	mainLayout->addSpacing(15);
	mainLayout->addWidget(imageBurger);
	
	mainLayout->addStretch();
	mainLayout->addSpacing(15);
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
	mainLayout->addSpacing(25);
	mainLayout->addWidget(powerups);
	mainLayout->addSpacing(20);
	mainLayout->addWidget(instructionsJeu);
	
	grid->addWidget(imageArc, 0, 0, Qt::AlignCenter);
	grid->addWidget(arc, 0, 1, Qt::AlignLeft);
	grid->addWidget(imagePotion, 1, 0, Qt::AlignCenter);
	grid->addWidget(potion, 1, 1, Qt::AlignLeft);
	grid->addWidget(imageEtoile, 2, 0, Qt::AlignCenter);
	grid->addWidget(etoile, 2, 1, Qt::AlignLeft);
	grid->addWidget(imageCorona, 3, 0, Qt::AlignCenter);
	grid->addWidget(corona, 3, 1, Qt::AlignLeft);
	mainLayout->addStretch();
	
	mainLayout->addWidget(quitterI);
	createMenu();
}

void Instructions::retour() {
	printf("Retour");
	parent->retour();
}


void Instructions::createMenu() {
	connect(quitterI, &QPushButton::clicked, this, &Instructions::retour);
}