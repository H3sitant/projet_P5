#include "panneaucentral.h"
#include "Personnage.h"
#include <iostream>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>

using namespace std;


PanneauCentral::PanneauCentral()
{
	delayFalling = 0;
	//FallingCondiments = new list<Condiment*>;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,LARGEUR,HAUTEUR);
    this->setScene(scene);
    this->setFixedSize(LARGEUR,HAUTEUR);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    player = new Personnage();
    //Chargement de l'image
    QPixmap pix(":/images/Licorne.png");
    //Redimension
    pix = pix.scaledToWidth(LARGEUR/5,Qt::SmoothTransformation);
    player->setPixmap(pix);
    //Positionnement
    player->setPos(LARGEUR/2, HAUTEUR-pix.height()); 


    // focusable = recoit les events
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    /*QPalette pal = QPalette();
    pal.setColor(QPalette::Background, QColor(0,0,0,0));
    scene->setPalette(pal);*/
	SetRecette(Grosseur_liste);

	QTimer * timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(CheckPosition()));
	timer->start(5);
}

void PanneauCentral::SetRecette(int taille) {
	for (int i = 0; i < taille; i++)
	{
		//Permet de s'assurer qu'aucun pain n'est g�n�r�.. pourrait �tre am�lior� car peut prendre du temps
		do {
			recette[i] = Condiment(Point());
		} while (recette[i].getSorte() == Condiment::PAIN_H );
	}
	//Le dernier ingr�dient est un pain
	recette[taille - 1] = Condiment(Condiment::PAIN_H, Point());
}

void PanneauCentral::FC()
{

	Condiment *newFallingC = new Condiment(true);
	newFallingC->setPos(rand() % LARGEUR, -HAUTEUR);
	//newFallingC->setPos(player->getPosition(), -HAUTEUR);
	FallingCondiments.push_back(newFallingC);
	scene->addItem(newFallingC);
}

void PanneauCentral::CheckPosition()
{
	delayFalling++;
	if (delayFalling == DelayFall)
	{
		FC();
		delayFalling = 0;
	}
	bool finjeu = false;
	if (!FallingCondiments.empty()) {
		//verifierPowerups();
		list<Condiment*> cpyFalling(FallingCondiments);
		for (Condiment* c : cpyFalling) {
			if (c->getPositionY() < player->getHauteurBurger()-10 && c->getPositionY() > player->getHauteurBurger() + 10 && c->getPositionX() > player->getPosition() - 50 && c->getPositionX() < player->getPosition() + 50) 
			{
				//Condiment* copy(c);
				c->setFalling(false);
				FallingCondiments.remove(c);
				//Powerup* p;
				switch (c->getSorte()) {

					/*case Condiment::POWERUP:
						p = dynamic_cast<Powerup*> (c);
						if (p) //v�rifie que le cast s'est bien pass�
						{
							activerPower(*p);
							break;
						}*/
				case Condiment::PAIN_H:
					finjeu = true;
				default:
					player->ajouterCondiment(c);
				}

			}
			else if (c->getPositionY() < 0) FallingCondiments.remove(c);
			/*else if (coronaVirusMode & c->getPositionY() == int(HAUTEUR / 2)) {//Les �l�ments qui passent la moiti� de l'�cran on des chances de se transformer en virus
				if (rand() % PROB_CORONA == 0) {
					Condiment* contaminedCondiment = new Powerup(Powerup::CORONA, c->getPosition());
					FallingCondiments.push_back(contaminedCondiment);
					FallingCondiments.remove(c);
				}
			}*/
		}
	}
}
void PanneauCentral::timeTick(){

}

void PanneauCentral::droite(){

}
void PanneauCentral::gauche(){

}

void PanneauCentral::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        player->deplacer(GAUCHE,LARGEUR);
    } else if (event->key() == Qt::Key_Right){
        player->deplacer(DROITE,LARGEUR);
    }
}

/*void PanneauCentral::resizeEvent(QResizeEvent *event){
    cerr << "allo\n";
    fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    cerr << height() << endl;
    cerr << frameSize().height()<<endl;
    player->setY(height());
    cerr << player->y() << endl;

}*/
