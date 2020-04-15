/*
*   Ce programme teste l'interface
*	Coralie Grégoire
*/

#include "menu.h"

Menu::Menu(FenetrePrincipale * parent)
	: QWidget(parent)
{
	this->parent = parent;
	
	QVBoxLayout *layout = new QVBoxLayout;
	layout->setAlignment(Qt::AlignCenter);

	jouer = new QPushButton("Jouer");
	jouer->setFixedSize(400, 45);

	instructions = new QPushButton("Instructions");
	instructions->setFixedHeight(45);

	quitter = new QPushButton("Quitter");
	quitter->setFixedHeight(45);
	
	layout->addSpacing(200);
	layout->addWidget(jouer);
	layout->addSpacing(10);
	layout->addWidget(instructions);
	layout->addSpacing(10);
	layout->addWidget(quitter);

	this->setLayout(layout);

	createMenu();
}


void Menu::actionJouer() {
	printf("jouer");
	parent->demarrerNouvellePartie();
}
void Menu::actionInstructions() {
	printf("instructions");
	parent->afficherInstructions();
}
void Menu::actionQuitter() {
	printf("quitter");
	parent->close();
}

void Menu::createMenu() {
	connect(jouer, &QPushButton::clicked, this, &Menu::actionJouer);
	connect(instructions, &QPushButton::clicked, this, &Menu::actionInstructions);
	connect(quitter, &QPushButton::clicked, this, &Menu::actionQuitter);
}