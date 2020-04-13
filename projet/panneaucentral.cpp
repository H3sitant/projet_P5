#include "panneaucentral.h"
#include "Personnage.h"
#include <iostream>
#include <QKeyEvent>
#include <QDebug>

using namespace std;


PanneauCentral::PanneauCentral(Burger *commande, FenetreJeu *parent): QGraphicsView(parent)
{
	this->parent = parent;
	this->commande = commande;
	victoire = false;
	finduJeux = false;
	tailleRecette = commande->getCondiments().size();
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
	Condiment *base = new Condiment(Condiment::PAIN_B, {player->x(),500-player->getHight()});
	scene->addItem(base);
	player->ajouterCondiment(base);
    /*QPalette pal = QPalette();
    pal.setColor(QPalette::Background, QColor(0,0,0,0));
    scene->setPalette(pal);*/
	
	timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(CheckPosition()));
	timer->start(50);
}

void PanneauCentral::FC()
{
	Condiment *newFallingC = new Condiment(true);
	newFallingC->setPos(rand() % LARGEUR-50, 0);
	//newFallingC->setPos(player->x(), 0);
	FallingCondiments.push_back(newFallingC);
	if (newFallingC->getSorte() == Condiment::POWERUP)
	{
		//newFallingC->setScale(0.5);
		if (newFallingC->getSortePow() == Powerup::RAINBOW)newFallingC->setOffset({ 45,-20 });
		else newFallingC->setOffset({ 50,-50 });	
	}
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
	if (!FallingCondiments.empty()) {
		verifierPowerups();
		list<Condiment*> cpyFalling(FallingCondiments);
		for (Condiment* c : cpyFalling) {
			if (c->getFalling() == true)
			{
				c->setPosition(c->getPositionX(), c->getPositionY() + 10);
				double itemSize = 0;
				if (c->getSorte() == Condiment::PAIN_H)itemSize = 20;
				if (c->getPositionY() > 500)
				{
					FallingCondiments.remove(c);
					delete c;
				}
				else if (c->getSorte() == Condiment::POWERUP && c->getPositionY() == 500 - player->getHight() - itemSize && c->getPositionX() > player->x() - 40 && c->getPositionX() < player->x() + 40)
				{
					c->setFalling(false);
					FallingCondiments.remove(c);
					activerPower(c);
					delete c;
				}
				else if (c->getPositionY() ==500-player->getHight()-itemSize && c->getPositionX() > player->x() - largeurCapter && c->getPositionX() < player->x() + largeurCapter)
				{
					c->setFalling(false);
					FallingCondiments.remove(c);
					if (c->getSorte() == Condiment::PAIN_H  )
					{
						finduJeux = true;
						timer->stop();
						player->ajouterCondiment(c);
						list<Condiment*> cpyFalling2(FallingCondiments);
						for (Condiment* c2 : cpyFalling2)
						{
							FallingCondiments.remove(c2);
							delete c2;
						}
						//Victoire si vrai
						if (*player->getBurger() == *commande) {
							victoire = true;
						}
						parent->finPartie(victoire);
					}
					else
					{
						
						player->ajouterCondiment(c);
					}
				}
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



//================================================
//PowerUp
//================================================
void PanneauCentral::verifierPowerups() {
	tempsRestantPowerup--;

	if (powerUpActif == 'R') {
		activerRainbow();
	}

	if (tempsRestantPowerup <= 0)
	{
		if (powerUpActif == 'S')
		{
			player->setmovementSpeed(10);
			largeurCapter = 10;
		}
		powerUpActif = NULL;
	}
}

void PanneauCentral::activerRainbow() {
	
	int i = 0;
	bool pileIsGood = true;
	Condiment::SorteCondiment condimentVoulu;
	for (Condiment *c : player->getBurger()->getCondiments()) {
		if (c->getSorte() != commande->getCondiments()[i]->getSorte()) {
			pileIsGood = false;
		}
		i++;
	}
	//list<Condiment*> newFalling;
	if (pileIsGood) {
		condimentVoulu = commande->getCondiments()[i]->getSorte();
		for (Condiment *c : FallingCondiments) {
			c->setSorte(condimentVoulu);
		}
	}
	else //On transforme les condiments en potion pour permettre au joueur de corriger ses erreurs
	{
		for (Condiment* c : FallingCondiments) {
			c->setSorte(Condiment::POWERUP);
			//c->setScale(0.5);
			c->setSortePow(Condiment::POTION);
			//newC->setPos(c->pos());
			//newFalling.push_back(newC);

		}
	}

	//FallingCondiments = newFalling;
}

void PanneauCentral::activerPower(Condiment *powerup)
{
	cout << "Powerup activ�!";
	//TODO Coder les diff�rentes effets des powerups
	switch (powerup->getSortePow()) {
	case Powerup::STAR:
		//powerUpActif = D�placement plus rapide
		//tempsRestantPowerup = TEMPS_MAX_POWERUP;
		cout << "Activer powerUp : Star";
		player->setmovementSpeed(20);
		largeurCapter = 15;
		powerUpActif = 'S';
		tempsRestantPowerup = 200;// 1=50 milliseconde
		break;
	case Powerup::RAINBOW:
		//powerUpActif = Toujours le bon item
		//tempsRestantPowerup = TEMPS_MAX_POWERUP;
		cout << "Activer powerUp : Rainbow";
		if (powerUpActif == 'S')
		{
			player->setmovementSpeed(10);
			largeurCapter = 10;
		}
		powerUpActif = 'R';
		tempsRestantPowerup = 200;
		activerRainbow();
		break;
	case Powerup::POTION:
		//Retire le dernier condiment de la pile du joueur
		//Powerup de type passif -> application imm�diate
		if (player->getBurger()->getCondiments().size() > 1) {
			scene->removeItem(player->getBurger()->getCondiments().back());
			player->retirerTop();
		}
		cout << "Activer powerUp : Potion";
		break;
	case Powerup::CORONA:
		//Le corona fait le bordel et m�lange le burger constitu�
		if (player->getBurger()->getCondiments().size() > 2) {
			player->getBurger()->mixBurger();
		}
		cout << "Activer powerUp : Covid";
		break;
	default:
		//throw (invalid_argument("Type de powerup non pris en charge"));
		break;
	}
}