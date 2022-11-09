#include "game.h"
#include <stdlib.h>
#include <ncurses.h>

WINDOW *CreationFenetre(int height, int width, int debut_X, int debut_Y){

	WINDOW *fenetrelocal;

	fenetrelocal = newwin(height, width, debut_X, debut_Y);
	box(fenetrelocal, 0, 0);
	wrefresh(fenetrelocal);

	return fenetrelocal;
}

int main(int ac, char **av){

	WINDOW *win = NULL;
	int h = 30;
	int w = 80;

	initscr();
	curs_set(false); // deasctiver le curseur
	refresh();
	// Tracer une fenetre avec des bordures au centre du terminal
	win = CreationFenetre(h, w, (LINES -h)/2, (COLS - w)/2);
	keypad(win, true); // pour recuperer la valeur des touches au clavier
	wgetch(win);
	endwin();

	return 0;
}

