#ifndef __GAME_H_
#define __GAME_H_

#include "Entite.h"
#include <ncurses.h>

#define SIZE_SNAKE  128

typedef enum  Direction{NORD, OUEST, SUD, EST} Direction;

typedef struct{
	bool vie;
	int limitdroite;
	int limitbas;
	int longueurSerp;
	Entite nourriture;
	Entite snake[SIZE_SNAKE];
	Direction direction;
} Game;

void init_jeu(WINDOW *, Game *, int, int, int);
void Lancer_Jeu(Game *, WINDOW *, long);

#endif
