#ifndef FENETREJEU_H
#define FENETREJEU_H

#include <QMainWindow>
#include <QtWidgets>

class FenetreJeu : public QMainWindow
{
    Q_OBJECT

public:
    FenetreJeu(const char * appName=nullptr);
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
