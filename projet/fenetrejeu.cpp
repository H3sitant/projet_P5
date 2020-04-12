#include "fenetrejeu.h"
#include <QtWidgets>
#include "panneaugauche.h"
#include "panneaudroite.h"
#include "panneaucentral.h"
#include <iostream>

FenetreJeu::FenetreJeu(const char * appName)
{

	int id =QFontDatabase::addApplicationFont(":police/Teletactile.ttf");
	

    this->setWindowTitle(appName);
    QPixmap bkgnd(":/images/Fond_Menu.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(0,0,0,0);

    panneauCentral = new PanneauCentral();
    panneauCentral->setStyleSheet("background-color: rgba(0,0,0,0) ");

    panneauGauche = new PanneauGauche();
    panneauDroite = new PanneauDroite();


    mainLayout->addWidget(panneauGauche);
    mainLayout->addWidget(panneauCentral);
    mainLayout->addWidget(panneauDroite);



    QPalette pal = QPalette();
    pal.setColor(QPalette::Background, QColor(0,0,0,100));
    panneauGauche->setAutoFillBackground(true);
    panneauGauche->setPalette(pal);
    panneauDroite->setAutoFillBackground(true);
    panneauDroite->setPalette(pal);
    /*panneauCentral->setAutoFillBackground(true);
    panneauCentral->setPalette(pal);*/
    //panneauGauche->setStyleSheet("background-color: rgba(0,0,0,40%) ");


    QWidget *fenetre = new QWidget();
    fenetre->setLayout(mainLayout);

    this->setCentralWidget(fenetre);
    this->setStyleSheet("color: white; font-size: 20px; font-style: bold; qproperty-alignment: AlignCenter;font-family: Teletactile;");
}

FenetreJeu::~FenetreJeu()
{

}


void FenetreJeu::pause(){

}
