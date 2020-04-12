#ifndef FENETREJEU_H
#define FENETREJEU_H

#include <QMainWindow>
#include <QtWidgets>
#include "FenetrePrincipale.h"

class FenetreJeu : public QWidget
{
    Q_OBJECT

public:
	FenetreJeu(FenetrePrincipale * parent=nullptr);
	~FenetreJeu();

public slots:
     void pause();


private:
    QHBoxLayout *mainLayout;
    QWidget *panneauGauche;
    QWidget *panneauDroite;
    QWidget *panneauCentral;
    QBasicTimer *timer;
};
#endif // FENETREJEU_H
