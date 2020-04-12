#include "panneaudroite.h"

PanneauDroite::PanneauDroite(FenetreJeu*parent): QWidget(parent)
{
	this->parent = parent;
    layoutPanneauDroite = new QVBoxLayout();
    this->setLayout(layoutPanneauDroite);

    QLabel *boutonMenuLabel = new QLabel(tr("MENU"));
    boutonMenuLabel->setWordWrap(true);
    boutonMenuLabel->setAlignment(Qt::AlignCenter);
    boutonMenuLabel->setTextInteractionFlags(Qt::NoTextInteraction);
    boutonMenuLabel->setMouseTracking(false);
    boutonMenuLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QHBoxLayout* boutonMenuLayout = new QHBoxLayout();
    boutonMenuLayout->addWidget(boutonMenuLabel);
    boutonMenuLayout->setMargin(0);
    boutonMenuLayout->setSpacing(0);
    boutonMenuLayout->setContentsMargins(5,5,5,5);

    boutonMenu = new QPushButton(this);
    boutonMenu->setText("");
    boutonMenu->setLayout(boutonMenuLayout);
    boutonMenu->setStyleSheet("qproperty-alignment: AlignRight;");
	connect(boutonMenu, &QPushButton::clicked, this->parent, &FenetreJeu::pause);

    labelPowerup = new QLabel(tr("POWERUP ACTIF: \n AUCUN"),this);
	labelImagePowerup = new QLabel();
	Powerup  p(Powerup::CORONA, { 0,0 });
	
	dessinerPowerup(p);
    labelTempsPowerup = new QLabel(tr("TEMPS POWERUP: \n 0"),this);


    layoutPanneauDroite->addWidget(boutonMenu);
	layoutPanneauDroite->addSpacing(75);
    layoutPanneauDroite->addWidget(labelPowerup);
	layoutPanneauDroite->addWidget(labelImagePowerup);
    layoutPanneauDroite->addWidget(labelTempsPowerup);
    layoutPanneauDroite->addStretch();
	labelImagePowerup->setAlignment(Qt::AlignCenter);
	labelImagePowerup->setStyleSheet("center");

}


void PanneauDroite::endPowerup(){

}
void PanneauDroite::dessinerPowerup(const Powerup &powerup) {
	QPixmap imageCadre(":/images/Case_Rose.png");
	QPixmap imagePowerup = powerup.pixmap().scaled(imageCadre.width() - 160, imageCadre.height() - 160, Qt::KeepAspectRatio);
	QPainter painter(&imageCadre);
	painter.drawPixmap(imageCadre.width() / 2 - imagePowerup.width() / 2, imageCadre.height() / 2 - imagePowerup.height() / 2, imagePowerup);
	labelImagePowerup->setPixmap(imageCadre.scaledToWidth(150));
}