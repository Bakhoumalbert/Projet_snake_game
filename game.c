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
        
}

static void avoir_entrees(Game *game, WINDOW *win){ 
	
}

static void manger(Game *game){
        
}

static void fin_jeu(Game *game, int w, int h){ 
        
}

static void render(Game *game, WINDOW *win){ 
             
}

static void Lancer_Jeu(Game *game, long temps){ 
             
}

void init_jeu(Game *game, int longueur, int w, int h){ 
        game -> vie = true;
        game -> direction = EST;
	game -> longueurSerp = longueur;
	init_bordures(game, w, h);
	init_nourriture(game, 10, 10);
	init_serpent(game, 10, 50);
}
