#include "game.h"
#include <unistd.h>

static void init_bordures(Game *game, int w, int h){
	game -> limitdroite = w - 1;
	game -> limitbas = h - 1;
}

static void init_nourriture(Game *game, int x, int y){ 
        game -> nourriture.x = x;
        game -> nourriture.y = y;
}

static void init_serpent(Game *game, int x, int y){ 
        game -> snake[0].x = x;
        game -> snake[0].y = y;

	for(int i =1; i < game -> longueurSerp; i++){
 		y++;
		game -> snake[i].x = x;
        	game -> snake[i].y = y;

	}
}

static void update_snake(Game *game, WINDOW *win){ 

	// La case precedant va pendre la case suivante pour de"placer le serpent
	for(int i = game -> longueurSerp - 1; i > 0; i--){
		game -> snake[i].x = game -> snake[i - 1].x;
		game -> snake[i].y = game -> snake[i - 1].y;
	}

	// modifier la direction adequate a la directionj du serpent
	if(game -> direction == NORD)
        	game -> snake[0].x--;
	else if(game -> direction == OUEST)
              	game -> snake[0].y--;
	else if(game -> direction == SUD)
                game -> snake[0].x++;
	else if(game -> direction == EST)
                game -> snake[0].y++;
}

static void Avoir_Entrees(Game *game, WINDOW *win){ 

	int ch = wgetch(win); // attend un caractere au clavier

	switch(ch){
		case KEY_UP:
			game -> direction = NORD;
			break;
		case KEY_RIGHT:
			game -> direction = EST;
			break;
		case KEY_LEFT:
                        game -> direction = OUEST;
                        break;
		case KEY_DOWN:
                        game -> direction = SUD;
                        break;
		case 'q':
                        game -> vie = false;
                        break;
		default:
			break;

	}
}

static void manger(Game *game){
        
}

static void fin_jeu(Game *game, int w, int h){ 
        
}

static void DessinSerpent(Game *game, WINDOW *win){

	werase(win); // efface la fenetre
	box(win, 0, 0); // redessine les bordures
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, game -> nourriture.x, game -> nourriture.y, " ");
	wattroff(win, COLOR_PAIR(2));

	wattron(win, COLOR_PAIR(1));

	for(int i =1; i < game -> longueurSerp; i++){
		mvwprintw(win, game -> snake[i].x, game -> snake[i].y, " ");
	}
	wattroff(win, COLOR_PAIR(1));
	wrefresh(win); // Afficher la nourriture
}

void Lancer_Jeu(Game *game,WINDOW *win, long temps){

	while(game -> vie){ // A chaque tour de boucle, j'affiche et je fais un pose
		Avoir_Entrees(game, win); // recupere ce qui est saisi au clavier
		update_snake(game, win);
		DessinSerpent(game, win);
		usleep(temps);
	}
}

void init_jeu(WINDOW *win,Game *game, int longueur, int w, int h){ 
        game -> vie = true;
        game -> direction = EST;
	game -> longueurSerp = longueur;
	wattron(win, A_REVERSE);
	init_bordures(game, w, h);
	init_nourriture(game, 10, 10);
	init_serpent(game, 10, 50);
	wattron(win, A_REVERSE);
}
