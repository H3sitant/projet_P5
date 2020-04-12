#include "panneaugauche.h"


PanneauGauche::PanneauGauche(QMainWindow *parent) : QWidget(parent)
{
layoutPanneauGauche = new QVBoxLayout();
this->setLayout(layoutPanneauGauche);

QLabel *pointage = new QLabel();
pointage->setText(tr("POINTS: 000"));

QWidget* vies = new QWidget();
QHBoxLayout *layoutVies = new QHBoxLayout();
QPixmap imageCoeur (":/images/Coeur.png");
int taille = 25;
QLabel *coeur1 = new QLabel();
coeur1->setPixmap(imageCoeur.scaled(taille,taille,Qt::KeepAspectRatio));
QLabel *coeur2 = new QLabel();
coeur2->setPixmap(imageCoeur.scaled(taille,taille,Qt::KeepAspectRatio));
QLabel *coeur3 = new QLabel();
coeur3->setPixmap(imageCoeur.scaled(taille,taille,Qt::KeepAspectRatio));
layoutVies->addStretch();
layoutVies->addWidget(coeur1);
layoutVies->addWidget(coeur2);
layoutVies->addWidget(coeur3);
vies->setLayout(layoutVies);

Burger commande;
commande.ajouterCondiment(new Condiment(Condiment::PAIN_B, { 0,0 }));
//commande.ajouterCondiment(new Condiment(Point{ 0, 0 }));
commande.ajouterCondiment(new Condiment(Condiment::FROMAGE, { 0,0 }));
commande.ajouterCondiment(new Condiment(Condiment::BOULETTE, { 0,0 }));

commande.ajouterCondiment(new Condiment(Condiment::OIGNON, { 0,0 }));
commande.ajouterCondiment(new Condiment(Condiment::LAITUE, { 0,0 }));
commande.ajouterCondiment(new Condiment(Condiment::TOMATE, { 0,0 }));
commande.ajouterCondiment(new Condiment(Condiment::PAIN_H, { 0,0 }));

labelImageBurger = new QLabel();
dessinerCommande(commande);

QLabel *temps = new QLabel();
temps->setText(tr("TEMPS: 180"));


layoutPanneauGauche->addWidget(pointage);
layoutPanneauGauche->addWidget(vies);
layoutPanneauGauche->addSpacing(75-taille);
layoutPanneauGauche->addWidget(temps);
layoutPanneauGauche->addWidget(labelImageBurger);
layoutPanneauGauche->addStretch();



dessinerCommande(commande);

}

void PanneauGauche::updateTemps(int temps){

}

void PanneauGauche::dessinerCommande(Burger commande) {
	QPixmap imageCadre(":/images/Case_Bleue.png");
	QPixmap imageBurger = commande.getBurgerPixmap().scaled(imageCadre.width() - 160, imageCadre.height() - 160, Qt::KeepAspectRatio);
	QPainter painter(&imageCadre);
	painter.drawPixmap(imageCadre.width() / 2 - imageBurger.width() / 2, imageCadre.height() / 2 - imageBurger.height() / 2, imageBurger);
	labelImageBurger->setPixmap(imageCadre.scaledToWidth(150));
}

