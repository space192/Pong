#include "graphics.h"
#include <stdio.h>
#include "unistd.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
void pause();

int Jeu(SDL_Surface* ecran)
{
	SDL_Rect positionBalle;
	SDL_Rect get_arrow();
	SDL_Rect positionJoueurUn;
	SDL_Rect positionJoueurDeux;
	SDL_Rect depBalle;
	SDL_Rect directionBalle;
	SDL_Rect basDroitUn;
	SDL_Rect hautDroitUn;
	SDL_Rect basGaucheDeux;
	SDL_Rect hautGaucheDeux;
	SDL_Rect depJoueur;
	SDL_Rect basGaucheBalle;
	SDL_Rect hautDroitBalle;
	SDL_Rect positionLigne;
	SDL_Rect positionScoreJoueurUn;
	SDL_Rect positionScoreJoueurDeux;
	SDL_Surface *player = NULL;
	SDL_Surface *player2 = NULL;
	SDL_Surface *balle = NULL;
	SDL_Surface *ligne = NULL;
	SDL_Surface *scoreJoueurUn = NULL;
	SDL_Surface *scoreJoueurDeux = NULL;
	int scoreJoueursUn = 0;
	int scoreJoueursDeux = 0;
	TTF_Init();
	TTF_Font *police = NULL;
	police = TTF_OpenFont("police.ttf", 50);
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
	positionBalle.x = 400; positionBalle.y = 300;
	SDL_Color couleurBlanche = { 255, 255, 255 };
	positionScoreJoueurUn.x = 100; positionJoueurUn.y = 50;
	positionScoreJoueurDeux.x = 600; positionScoreJoueurDeux.y = 50;
	positionJoueurUn.x = 30; positionJoueurUn.y = 300;
	positionJoueurDeux.x = 750; positionJoueurDeux.y = 300;
	positionLigne.x = 0; positionLigne.y = 100;
	depBalle.x = 1; depBalle.y = 1;
	directionBalle.x = 1; directionBalle.y = 1;
	player = IMG_Load("Pod_Joueurs.bmp");
	player2 = IMG_Load("Pod_Joueurs.bmp");
	balle = IMG_Load("balle.bmp");
	ligne = IMG_Load("Barre_de_Score.bmp");
	SDL_EnableKeyRepeat(15, 15);

	while ((scoreJoueursUn < 5) && (scoreJoueursDeux < 5))
	{
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		depJoueur = get_arrow();
		positionJoueurUn.y = positionJoueurUn.y + (depJoueur.x * 10);
		positionJoueurDeux.y = positionJoueurDeux.y + (depJoueur.y * 10);
		if (positionJoueurUn.y > 500)
		{
			positionJoueurUn.y = 500;
		}
		else if (positionJoueurUn.y < 100)
		{
			positionJoueurUn.y = 100;
		}
		SDL_BlitSurface(player, NULL, ecran, &positionJoueurUn);
		if (positionJoueurDeux.y > 500)
		{
			positionJoueurDeux.y = 500;
		}
		else if (positionJoueurDeux.y < 100)
		{
			positionJoueurDeux.y = 100;
		}
		SDL_BlitSurface(player2, NULL, ecran, &positionJoueurDeux);
		SDL_BlitSurface(ligne, NULL, ecran, &positionLigne);
		basDroitUn.x = 50;
		basDroitUn.y = positionJoueurUn.y + 200;
		hautDroitUn.x = 50;
		hautDroitUn.y = positionJoueurUn.y;

		basGaucheDeux.x = 770;
		basGaucheDeux.y = positionJoueurDeux.y + 200;
		hautGaucheDeux.x = 770;
		hautGaucheDeux.y = positionJoueurDeux.y;

		basGaucheBalle.x = positionBalle.x;
		basGaucheBalle.y = positionBalle.y + 15;
		hautDroitBalle.x = positionBalle.x + 15;
		hautDroitBalle.y = positionBalle.y + 15;

		if (positionBalle.x == 800)
		{
			positionBalle.x = 400;
			positionBalle.y = 350;
			scoreJoueursUn++;
		}
		else if (positionBalle.x == 0)
		{
			positionBalle.x = 400;
			positionBalle.y = 350;
			scoreJoueursDeux++;
		}
		else
		{
			switch (directionBalle.y)
			{
			case 1:
				positionBalle.y += depBalle.y;
				if (positionBalle.y == 685)
				{
					directionBalle.y = 0;
				}
				break;
			case 0:
				positionBalle.y -= depBalle.y;
				if (positionBalle.y == 100)
				{
					directionBalle.y = 1;
				}
				break;
			}
			switch (directionBalle.x)
			{
			case 1:
				positionBalle.x += depBalle.x;
				if (positionBalle.x == 740)
				{
					if ((hautDroitBalle.y > hautGaucheDeux.y) && (hautDroitBalle.y < basGaucheDeux.y))
					{
						directionBalle.x = 0;
					}
				}
				break;
			case 0:
				positionBalle.x -= depBalle.x;
				if (positionBalle.x == 50)
				{
					if ((basGaucheBalle.y > hautDroitUn.y) && (basGaucheBalle.y < basDroitUn.y))
					{
						directionBalle.x = 1;
					}
				}
				break;
			}
			SDL_BlitSurface(balle, NULL, ecran, &positionBalle);
			SDL_Flip(ecran);
			SDL_Delay(5);
		}
	}
	TTF_CloseFont(police);
	TTF_Quit();
	return scoreJoueursUn;
	return scoreJoueursDeux;
}