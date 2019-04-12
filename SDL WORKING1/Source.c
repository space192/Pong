#include "graphics.h"
#include <stdio.h>
#include "unistd.h"
#include "SDL.h"
#include "SDL_image.h"
void pause();
void Jeu();


int main(int argc, char *argv[])
{
	SDL_Surface *ecran = NULL, *menu = NULL;
	SDL_Rect positionMenu;
	POINT positionClic;
	POINT wait_clic();
	int lancement = 0;
	int continuer = 1;

	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(800, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("PING PONG", NULL);

	menu = IMG_Load("menu.bmp");
	positionMenu.x = 0;
	positionMenu.y = 0;
	SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
	
	SDL_Flip(ecran);
	while (continuer)
	{
		positionClic = wait_clic();
		if ((positionClic.x > 271) && (positionClic.x < 522) && (positionClic.y < 330) && (positionClic.y > 285))
		{
			continuer = 0;
			Jeu();
		}
		else if ((positionClic.x > 271) && (positionClic.x < 522) && (positionClic.y > 445) && (positionClic.y < 490))
		{
			continuer = 0;
			SDL_Quit();
		}
	}
	SDL_FreeSurface(menu);
	SDL_Quit();
	
	return EXIT_SUCCESS;

}
