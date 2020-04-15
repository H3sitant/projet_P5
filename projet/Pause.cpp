/*
*   Ce programme teste l'interface
*	Coralie Grégoire
*/

#include "pause.h"

Pause::Pause(FenetrePrincipale  *parent)
	: fenetreTexte(new QPlainTextEdit), QWidget(parent)
{
	this->parent = parent;

	QVBoxLayout *layout = new QVBoxLayout();
	layout->setAlignment(Qt::AlignCenter);

	reprendreP = new QPushButton("Reprendre");
	reprendreP->setFixedSize(400, 45);

	instructionsP = new QPushButton("Instructions");
	instructionsP->setFixedHeight(45);

	rejouerP = new QPushButton("Rejouer");
	rejouerP->setFixedHeight(45);

	quitterP = new QPushButton("Menu principal");
	quitterP->setFixedHeight(45);

	layout->addSpacing(30);
	layout->addWidget(reprendreP);
	layout->addSpacing(10);
	layout->addWidget(instructionsP);
	layout->addSpacing(10);
	layout->addWidget(rejouerP);
	layout->addSpacing(10);
	layout->addWidget(quitterP);

	this->setLayout(layout);

	createMenu();
}


void Pause::reprendre() {
	parent->afficherJeu();
	printf("reprendre");
}
void Pause::instructions() {
	parent->afficherInstructions();
	printf("instructions");
}
void Pause::rejouer() {
	parent->demarrerNouvellePartie();
	printf("rejouer");
}
void Pause::quitter() {
	parent->afficherMenuPrincipal();
	printf("quitter");
}


void Pause::createMenu() {
	connect(reprendreP, &QPushButton::clicked, this, &Pause::reprendre);
	connect(instructionsP, &QPushButton::clicked, this, &Pause::instructions);
	connect(rejouerP, &QPushButton::clicked, this, &Pause::rejouer);
	connect(quitterP, &QPushButton::clicked, this, &Pause::quitter);
}