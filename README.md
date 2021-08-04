# Skyburger
![image](https://user-images.githubusercontent.com/44242537/128113669-295a21ba-0dd7-4160-a5e4-638efb570cfb.png)

Le jeu Skyburger a été développé en C++ à l'aide de Qt par un groupe d'étudiants 
en génie électrique et génie informatique de l'Université de 
Sherbrooke dans le cadre de leur projet de deuxième session.

## But du jeu
![image](https://user-images.githubusercontent.com/44242537/128113978-a69a7070-0abe-48e4-a4f4-656d18fc140f.png)

Le but du jeu est d'attraper les différents ingrédients afin de compléter la
recette demandée.

## Condiments
Il existe 5 condiments différents soit:
* Pain (P)
* Boulette (B)
* Laitue (L)
* Tomate (T)
* Oignon (O)

Le pain possède la particularité de terminer la partie lorsqu'il est ramassé.
Le burger constitué est alors comparée avec la recette demandée afin de savoir si
le joueur passe au niveau suivant ou s'il a perdu la partie.

## Powerups
Il existe 4 "powerups" différents. Ces éléments tombent tout comme les condiments,
mais possèdent des effets spéciaux.

### Potion Magique
La potion magique (M) permet de retirer l'ingrédient au dessus du burger. Son effet est immédiat.

### Rainbow
L'arc-en-ciel (R) transforme tous les ingrédients tombant en l'ingrédiant souhaité
par le joueur pour compléter son hamburger.

### Étoile
Implémentation à venir (S)

### COVID-19
Le COVID-19 (C) est le seul condiment nuisible. Celui-ci mélange tout le burger constitué
par le joueur. De plus, les condiments tombant ont une certaine probabilité de se
transformer en virus au cours de leur chute.
