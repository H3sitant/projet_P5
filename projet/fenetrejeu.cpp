#include "fenetrejeu.h"
#include <QtWidgets>
#include "panneaugauche.h"
#include "panneaudroite.h"
#include "panneaucentral.h"

#include <iostream>

FenetreJeu::FenetreJeu(FenetrePrincipale * parent) : QWidget(parent)
{
	this->parent = parent;
    mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(0,0,0,0);

    panneauCentral = new PanneauCentral();
    panneauCentral->setStyleSheet("background-color: rgba(0,0,0,0) ");

    panneauGauche = new PanneauGauche();
    panneauDroite = new PanneauDroite(this);


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


    this->setLayout(mainLayout);


    
}

FenetreJeu::~FenetreJeu()
{

}


void FenetreJeu::pause(){
	printf("FenetreJeu::pause");
	parent->afficherMenuPause();
}
