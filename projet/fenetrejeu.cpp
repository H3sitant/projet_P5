#include "fenetrejeu.h"
#include <QtWidgets>
#include "panneaugauche.h"
#include "panneaudroite.h"
#include "panneaucentral.h"

#include <iostream>

FenetreJeu::FenetreJeu(FenetrePrincipale * parent) : QWidget(parent)
{
	this->parent = parent;
	commande = new Burger();
	genererCommande();
    mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(0,0,0,0);

    panneauCentral = new PanneauCentral(commande,this);
    panneauCentral->setStyleSheet("background-color: rgba(0,0,0,0) ");

    panneauGauche = new PanneauGauche(commande, this);
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

void FenetreJeu::finPartie(bool victoire) {
	parent->afficherFinPartie(victoire);
}

void FenetreJeu::genererCommande(int nbrItem) {
	if (nbrItem>= 2){
		commande->viderBurger();
		commande->ajouterCondiment(new Condiment(Condiment::PAIN_B, { 0,0 }));
		for (int i = 0; i < nbrItem - 2; i++) {
			Condiment * nextCondiment ;
			do {
				nextCondiment = new Condiment;
			} while (nextCondiment->getSorte() == Condiment::PAIN_B || nextCondiment->getSorte() == Condiment::PAIN_H || nextCondiment->getSorte() == Condiment::POWERUP); // à optimiser, peut prendre du temps
			commande->ajouterCondiment(nextCondiment);
		}
		commande->ajouterCondiment(new Condiment(Condiment::PAIN_H, { 0,0 }));
	}
}