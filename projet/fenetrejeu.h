#ifndef FENETREJEU_H
#define FENETREJEU_H

#include <QMainWindow>
#include <QtWidgets>
#include "FenetrePrincipale.h"
#include "burger.h"

class FenetreJeu : public QWidget
{
    Q_OBJECT

public:
	FenetreJeu(FenetrePrincipale * parent=nullptr);
	~FenetreJeu();

	void genererCommande(int nbrItem=5);

public slots:
     void pause();


private:
    QHBoxLayout *mainLayout;
    QWidget *panneauGauche;
    QWidget *panneauDroite;
    QWidget *panneauCentral;
    QBasicTimer *timer;
	FenetrePrincipale * parent;
	Burger *commande;
};
#endif // FENETREJEU_H
