#include "graphics.h"
#include <stdio.h>
#include "unistd.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
void pause();
int Jeu(SDL_Surface *ecran);


int main(int argc, char *argv[])
{
	SDL_Surface *ecran = NULL, *menu = NULL, *regle = NULL, *joueur1win = NULL, *joueur2win = NULL, *easteregg = NULL;
	Mix_Music *easterEgg;
	Mix_Music *victorySound;
	SDL_Rect positionMenu;
	POINT positionClic;
	POINT wait_clic();
	int lancement = 0;
	int continuer = 1;
	int totalPoint = 0;
	int rejouer = 0;
	int affRegle = 0;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetIcon(IMG_Load("pingpong.bmp"), NULL);
	ecran = SDL_SetVideoMode(800, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("PING PONG", NULL);
	menu = IMG_Load("menu.bmp");
	regle = IMG_Load("regles.bmp");
	joueur1win = IMG_Load("Joueur 1 win.bmp");
	joueur2win = IMG_Load("Joueur 2 win.bmp");
	easteregg = IMG_Load("easter egg.bmp");
	positionMenu.x = 0;
	positionMenu.y = 0;
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	easterEgg = Mix_LoadMUS("easter egg.WAV");
	victorySound = Mix_LoadMUS("victory.wav");
	SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
	
	SDL_Flip(ecran);
	while (continuer)
	{
		positionClic = wait_clic();
		if (((rejouer == 0) && (positionClic.x > 271) && (positionClic.x < 522) && (positionClic.y < 330) && (positionClic.y > 285)))
		{
			totalPoint = Jeu(ecran);
			rejouer = 0;
			if (totalPoint > 0)
			{
				SDL_BlitSurface(joueur1win, NULL, ecran, &positionMenu);
				SDL_Flip(ecran);
				Mix_PlayMusic(victorySound, 1);
				rejouer = 1;
			}
			else if (totalPoint < 0)
			{
				SDL_BlitSurface(joueur2win, NULL, ecran, &positionMenu);
				SDL_Flip(ecran);
				Mix_PlayMusic(victorySound, 1);
				rejouer = 1;
			}
		}
		else if ((rejouer == 0) && (positionClic.x > 271) && (positionClic.x < 522) && (positionClic.y > 445) && (positionClic.y < 490))
		{
			continuer = 0;
		}
		else if ((affRegle == 0) && (rejouer == 0) && (positionClic.x > 749) && (positionClic.x < 770) && (positionClic.y > 28) && (positionClic.y < 57))
		{
			SDL_BlitSurface(regle, NULL, ecran, &positionMenu);
			SDL_Flip(ecran);
			affRegle = 1;
		}
		else if ((rejouer == 0) && (positionClic.x > 491) && (positionClic.x < 502) && (positionClic.y > 126) && (positionClic.y < 137))
		{
			
			SDL_BlitSurface(easteregg, NULL, ecran, &positionMenu);
			SDL_Flip(ecran);
			Mix_PlayMusic(easterEgg, 1);
			SDL_Delay(5000);
			SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
			SDL_Flip(ecran);
		}
		else if ((rejouer == 1) && (positionClic.x > 240) && (positionClic.x < 580) && (positionClic.y > 502) && (positionClic.y < 548))
		{
			SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
			SDL_Flip(ecran);
			continuer = 1;
			rejouer = 0;
		}
		else if ((rejouer == 1) && (positionClic.x > 312) && (positionClic.x < 489) && (positionClic.y > 573) && (positionClic.y < 618))
		{
			SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
			SDL_Flip(ecran);
			continuer = 0;
			rejouer = 0;
		}
		else if ((affRegle == 1) && (rejouer == 0) && (positionClic.x > 736) && (positionClic.x < 772) && (positionClic.y > 31) && (positionClic.y < 60))
		{
			SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
			SDL_Flip(ecran);
			affRegle = 0;
		}
	}
	Mix_FreeMusic(easterEgg);
	SDL_FreeSurface(ecran);
	SDL_FreeSurface(menu);
	SDL_FreeSurface(regle);
	SDL_FreeSurface(joueur1win);
	SDL_FreeSurface(joueur2win);
	SDL_Quit();
	
	return EXIT_SUCCESS;

}
