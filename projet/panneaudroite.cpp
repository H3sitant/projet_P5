#include "panneaudroite.h"

PanneauDroite::PanneauDroite(QWidget*parent): QWidget(parent)
{
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
	connect(boutonMenu, &QPushButton::clicked, this, &PanneauDroite::slotBoutonMenu);

    labelPowerup = new QLabel(tr("POWERUP ACTIF: \n AUCUN"),this);
	labelImagePowerup = new QLabel();

	
	viderCase();
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

void PanneauDroite::reset() {
	viderCase();
	setTempsPowerup(0);
	ecrirePowerup("AUCUN");
}

void PanneauDroite::slotBoutonMenu() {
	emit boutonMenuClicked();
}

void PanneauDroite::setPowerupActif( Condiment* powerup) {
	setTempsPowerup(10);
	dessinerPowerup(powerup);
	QString powerupActif("POWERUP ACTIF : \n");
	ecrirePowerup(powerup->toString());
}

void PanneauDroite::diminuerTempsPowerup()
{
	if (--temps <= 0) {
		temps = 0;
		finPowerup();
	}
	setTempsPowerup(temps);
}

void PanneauDroite::ecrirePowerup(string sorte) {
	labelPowerup->setText(tr("POWERUP ACTIF: \n") + QString(sorte.c_str()));
}

void PanneauDroite::finPowerup() {
	viderCase();
	ecrirePowerup("AUCUN");
	emit finPowerupSignal();
}

void PanneauDroite::setTempsPowerup(int temps){
	this->temps = temps;
	labelTempsPowerup->setText(tr("TEMPS POWERUP: \n ") + QString::number(temps));
	
}

int PanneauDroite::getTempsPowerup() {
	return temps;
}
void PanneauDroite::dessinerPowerup( Condiment *powerup) {
	QPixmap imageCadre(":/images/Case_Rose.png");
	QPixmap imagePowerup = powerup->pixmap().scaled(imageCadre.width() - 160, imageCadre.height() - 160, Qt::KeepAspectRatio);
	QPainter painter(&imageCadre);
	painter.drawPixmap(imageCadre.width() / 2 - imagePowerup.width() / 2, imageCadre.height() / 2 - imagePowerup.height() / 2, imagePowerup);
	labelImagePowerup->setPixmap(imageCadre.scaledToWidth(150));
}

void PanneauDroite::viderCase() {
	QPixmap imageCadre(":/images/Case_Rose.png");
	labelImagePowerup->setPixmap(imageCadre.scaledToWidth(150));
}

