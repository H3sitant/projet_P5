/*
*   Ce programme teste l'interface
*	Coralie Gr�goire
*/

#include "menu.h"

Menu::Menu(FenetrePrincipale * parent)
	: QWidget(parent)
{
	this->parent = parent;
	QVBoxLayout *layout = new QVBoxLayout;
	 jouer = new QPushButton("Jouer");

	 instructions = new QPushButton("Instructions");
	 reglages = new QPushButton("Reglages");
	this->setLayout(layout);
	layout->addStretch();
	layout->addWidget(jouer);
	layout->addSpacing(15);
	layout->addWidget(instructions);
	layout->addSpacing(15);
	layout->addWidget(reglages);
	layout->addStretch();
	createMenu();
}


void Menu::actionJouer() {
	printf("jouer");
	parent->demarrerNouvellePartie();
}
void Menu::actionInstruction() {
	printf("instrcutions");
	parent->afficherInstructions();
}
void Menu::actionReglages() {
	printf("reglages");
}

void Menu::createMenu() {
	connect(jouer, &QPushButton::clicked, this, &Menu::actionJouer);
	connect(instructions, &QPushButton::clicked, this, &Menu::actionInstruction);
	connect(reglages, &QPushButton::clicked, this, &Menu::actionReglages);
}