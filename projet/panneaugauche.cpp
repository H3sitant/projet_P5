#include "panneaugauche.h"


PanneauGauche::PanneauGauche(Burger *commande, QWidget *parent) : QWidget(parent)
{
	
	this->commande = commande;

layoutPanneauGauche = new QVBoxLayout();
this->setLayout(layoutPanneauGauche);

QLabel *pointage = new QLabel();
pointage->setText(tr("POINTS: 000"));

QWidget* vies = new QWidget();
QHBoxLayout *layoutVies = new QHBoxLayout();
QPixmap imageCoeur (":/images/Coeur.png");
int taille = 50;
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


labelImageBurger = new QLabel();
dessinerCommande();

labelTemps = new QLabel();
labelTemps->setText(tr("TEMPS RESTANT\n180"));

layoutPanneauGauche->addSpacing(5);
layoutPanneauGauche->addWidget(pointage);
layoutPanneauGauche->addWidget(vies);
layoutPanneauGauche->addSpacing(100);
layoutPanneauGauche->addWidget(labelTemps);
layoutPanneauGauche->addSpacing(10);
layoutPanneauGauche->addWidget(labelImageBurger);
layoutPanneauGauche->addStretch();

}



void PanneauGauche::dessinerCommande() {
	QPixmap imageCadre(":/images/Case_Bleue.png");
	QPixmap imageBurger = commande->getBurgerPixmap().scaled(imageCadre.width() - 160, imageCadre.height() - 160, Qt::KeepAspectRatio);
	QPainter painter(&imageCadre);
	painter.drawPixmap(imageCadre.width() / 2 - imageBurger.width() / 2, imageCadre.height() / 2 - imageBurger.height() / 2, imageBurger);
	labelImageBurger->setPixmap(imageCadre.scaledToWidth(150));
}

void PanneauGauche::diminuerTemps()
{
	labelTemps->setText(QString("TEMPS RESTANT\n")+QString::number(--temps));
	
}

void PanneauGauche::setTemps(int temps)
{
	this->temps = temps;
	labelTemps->setText(QString("TEMPS RESTANT\n") + QString(--temps));
}

int PanneauGauche::getTemps()
{
	return temps;
}

