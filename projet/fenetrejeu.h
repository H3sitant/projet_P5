#ifndef FENETREJEU_H
#define FENETREJEU_H

#include <QMainWindow>
#include <QtWidgets>
#include "burger.h"
#include "panneaucentral.h"
#include "panneaugauche.h"

class FenetreJeu : public QWidget
{
    Q_OBJECT

public:
	FenetreJeu(QWidget * parent=nullptr);
	~FenetreJeu();

	
	void demarrerNouvellePartie();
	
	void genererCommande(int nbrItem=5);

public slots:
     void pause();
	 void finPartie(bool victoire);

signals:
	void pauseSignal();
	void finPartieSignal(bool victoire);

private:
    QHBoxLayout *mainLayout;
    PanneauGauche *panneauGauche;
    QWidget *panneauDroite;
    PanneauCentral *panneauCentral;
    QBasicTimer *timer;
	Burger *commande;

	
};
#endif // FENETREJEU_H
