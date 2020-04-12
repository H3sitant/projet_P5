#include "panneaucentral.h"
#include "Personnage.h"
#include <iostream>
#include <QKeyEvent>
#include <QDebug>

using namespace std;


PanneauCentral::PanneauCentral()
{
	finduJeux = false;
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
	SetRecette(Grosseur_liste);
	
	timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(CheckPosition()));
	timer->start(50);
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
	newFallingC->setPos(rand() % LARGEUR, 0);
	//newFallingC->setPos(player->x(), 0);
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
				//else if (c->getPositionY() < player->getHauteurBurger()-10 && c->getPositionY() > player->getHauteurBurger() + 10 && c->getPositionX() > player->getPosition() - 50 && c->getPositionX() < player->getPosition() + 50) 
				else if (c->getPositionY() ==500-player->getHight()-itemSize && c->getPositionX() > player->x() - 10 && c->getPositionX() < player->x() + 10)
				{
					//Condiment* copy(c);
					c->setFalling(false);
					FallingCondiments.remove(c);
					Powerup* p;
					if (c->getSorte() == Condiment::POWERUP) {
						p = dynamic_cast<Powerup*> (c);
						if (p) //v�rifie que le cast s'est bien pass�
						{
							activerPower(p);
							break;
						}
					}
					else if (c->getSorte() == Condiment::PAIN_H)
					{
						finduJeux == true;
						timer->stop();
						player->ajouterCondiment(c);
						list<Condiment*> cpyFalling2(FallingCondiments);
						for (Condiment* c2 : cpyFalling2)
						{
							FallingCondiments.remove(c2);
							delete c2;
						}
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


void PanneauCentral::verifierPowerups() {
	if (powerUpActif != NULL) {
		if (tempsRestantPowerup-- > 0) {
			switch (powerUpActif) {
			case 'R': //Rainbow
				activerRainbow();
				break;
			default:
				throw invalid_argument("Type de PowerUp non pris en charge");
			}
		}
		else {
			powerUpActif = NULL;
		}
	}
}

void PanneauCentral::activerRainbow() {
	int i = 0;
	bool pileIsGood = true;
	Condiment::SorteCondiment condimentVoulu;
	for (Condiment *c : player->getCondiments()) {
		if (c->getSorte() != recette[i].getSorte()) {
			pileIsGood = false;
		}
		i++;
	}
	list<Condiment*> newFalling;
	if (pileIsGood) {
		condimentVoulu = recette[i].getSorte();
		for (Condiment *c : FallingCondiments) {
			newFalling.push_back(new Condiment(condimentVoulu));
		}
	}
	else //On transforme les condiments en potion pour permettre au joueur de corriger ses erreurs
	{
		for (Condiment* c : FallingCondiments) {
			newFalling.push_back(new Powerup(Powerup::POTION));
		}
	}
	FallingCondiments = newFalling;
}

void PanneauCentral::activerPower(Powerup *powerup)
{
	cout << "Powerup activ�!";
	//TODO Coder les diff�rentes effets des powerups
	switch (powerup->getSortePow()) {
	case Powerup::STAR:
		//powerUpActif = powerup.toString();
		//tempsRestantPowerup = TEMPS_MAX_POWERUP;
		break;
	case Powerup::RAINBOW:
		powerUpActif = powerup->toString();
		tempsRestantPowerup = TEMPS_MAX_POWERUP;
		activerRainbow();
		break;
	case Powerup::POTION:
		//Retire le dernier condiment de la pile du joueur
		//Powerup de type passif -> application imm�diate
		if (!player->getCondiments().empty()) {
			player->retirerTop();
		}
		break;
	case Powerup::CORONA:
		//Le corona fait le bordel et m�lange le burger constitu�
		player->mixBurger();
		break;
	default:
		throw (invalid_argument("Type de powerup non pris en charge"));
	}
}