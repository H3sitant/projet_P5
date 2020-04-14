#include "fenetrejeu.h"
#include <QtWidgets>
#include "panneaugauche.h"
#include "panneaudroite.h"
#include "panneaucentral.h"

#include <iostream>

FenetreJeu::FenetreJeu(QWidget * parent) : QWidget(parent)
{
	isPaused = true;
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
	connect(panneauDroite, &PanneauDroite::finPowerupSignal, this, &FenetreJeu::finPowerup);
	connect(panneauDroite, &PanneauDroite::boutonMenuClicked, this, &FenetreJeu::pause);
	connect(panneauCentral, &PanneauCentral::pauseSignal, this, &FenetreJeu::pause);
	connect(panneauCentral, &PanneauCentral::finPartie, this, &FenetreJeu::finPartie);
	connect(panneauCentral, &PanneauCentral::powerupActive, this, &FenetreJeu::activationPowerup);
	timer = new QTimer;
	connect(timer, &QTimer::timeout, this, &FenetreJeu::slotTimer);
	
}

FenetreJeu::~FenetreJeu()
{

}


void FenetreJeu::pause(){
	isPaused = true;
	printf("FenetreJeu::pause");
	timer->stop();
	panneauCentral->pause();
	emit  pauseSignal();
}

void FenetreJeu::resume() {
	isPaused = false;
	timer->start(1000);
	panneauCentral->resume();
}

void FenetreJeu::finPowerup()
{
	panneauCentral->finPowerups();
}

void FenetreJeu::finPartie(bool victoire) {
	timer->stop();
	emit finPartieSignal(victoire);
}

void FenetreJeu::slotTimer()
{
	panneauGauche->diminuerTemps();
	if (panneauGauche->getTemps()<=0) {
		panneauCentral->pause();
		finPartie(false);
	}
	panneauDroite->diminuerTempsPowerup();
}

void FenetreJeu::activationPowerup( Condiment * powerup)
{
	panneauDroite->setPowerupActif(powerup);
}

void FenetreJeu::demarrerNouvellePartie()
{
	genererCommande();
	panneauGauche->setTemps(180);
	panneauGauche->dessinerCommande();
	panneauCentral->demarrerNouvellePartie();
	panneauDroite->reset();
	timer->start(1000); //timer a la seconde
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

void FenetreJeu::keyPressEvent(QKeyEvent* event) {
		if (event->key() == Qt::Key_P) {
			pause();
	}
}
