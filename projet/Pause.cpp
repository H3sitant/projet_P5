/*
*   Ce programme teste l'interface
*	Coralie Gr�goire
*/

#include "pause.h"

Pause::Pause(QWidget  *parent)
	: fenetreTexte(new QPlainTextEdit), QWidget(parent)
{
	
	QVBoxLayout *layout = new QVBoxLayout();
	reprendreP = new QPushButton("Reprendre");
	instructionsP = new QPushButton("Instructions");
	rejouerP = new QPushButton("Rejouer");
	quitterP = new QPushButton("Quitter");
	this->setLayout(layout);
	layout->addStretch();
	layout->addWidget(reprendreP);
	layout->addStretch();
	layout->addWidget(instructionsP);
	layout->addStretch();
	layout->addWidget(rejouerP);
	layout->addStretch();
	layout->addWidget(quitterP);
	layout->addStretch();
	createMenu();
}


void Pause::reprendre() {
	printf("reprendre");
}
void Pause::instructions() {
	printf("instrcutions");
}
void Pause::rejouer() {
	printf("rejouer");
}
void Pause::quitter() {
	printf("quitter");
}


void Pause::createMenu() {
	connect(reprendreP, &QPushButton::clicked, this, &Pause::reprendre);
	connect(instructionsP, &QPushButton::clicked, this, &Pause::instructions);
	connect(rejouerP, &QPushButton::clicked, this, &Pause::rejouer);
	connect(quitterP, &QPushButton::clicked, this, &Pause::quitter);
}