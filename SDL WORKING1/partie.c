#include "graphics.h"
#include <stdio.h>
#include "unistd.h"
#include "SDL.h"
#include "SDL_image.h"
void pause();

void Jeu(SDL_Surface* ecran)
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
	SDL_Surface *player = NULL;
	SDL_Surface *player2 = NULL;
	SDL_Surface *balle = NULL;
	int scoreJoueurUn = 0;
	int scoreJoueurDeux = 0;
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
	positionBalle.x = 400; positionBalle.y = 300;
	positionJoueurUn.x = 20; positionJoueurUn.y = 300;
	positionJoueurDeux.x = 780; positionJoueurDeux.y = 300;
	depBalle.x = 1; depBalle.y = 1;
	directionBalle.x = 1; directionBalle.y = 1;
	player = IMG_Load("Pod_Joueurs.bmp");
	player2 = IMG_Load("Pod_Joueurs.bmp");
	balle = IMG_Load("balle.bmp");
	SDL_EnableKeyRepeat(100, 100);

	while ((scoreJoueurUn < 5) && (scoreJoueurDeux < 5))
	{
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		depJoueur = get_arrow();
		positionJoueurUn.y = positionJoueurUn.y + (depJoueur.x * 8);
		positionJoueurDeux.y = positionJoueurDeux.y + (depJoueur.y * 8);
		if (positionJoueurUn.y > 506)
		{
			positionJoueurUn.y = 506;
		}
		else if (positionJoueurUn.y < 100)
		{
			positionJoueurUn.y = 100;
		}
		SDL_BlitSurface(player, NULL, ecran, &positionJoueurUn);
		if (positionJoueurDeux.y > 506)
		{
			positionJoueurDeux.y = 506;
		}
		else if (positionJoueurDeux.y < 100)
		{
			positionJoueurDeux.y = 100;
		}
		SDL_BlitSurface(player2, NULL, ecran, &positionJoueurDeux);

		basDroitUn.x = positionJoueurUn.x + 10;
		basDroitUn.y = positionJoueurUn.y - 100;
		hautDroitUn.x = positionJoueurUn.x + 10;
		hautDroitUn.y = positionJoueurUn.y + 100;

		basGaucheDeux.x = positionJoueurDeux.x - 10;
		basGaucheDeux.y = positionJoueurDeux.y - 100;
		hautGaucheDeux.x = positionJoueurDeux.x - 10;
		hautGaucheDeux.y = positionJoueurDeux.y + 100;

		if (positionBalle.x == 800)
		{
			positionBalle.x = 400;
			positionBalle.y = 300;
		}
		else if (positionBalle.x == 0)
		{
			positionBalle.x = 400;
			positionBalle.y = 300;
		}
		else
		{
			switch (directionBalle.y)
			{
			case 1:
				positionBalle.y += depBalle.y;
				if (positionBalle.y == 600)
				{
					directionBalle.y = 0;
				}
				break;
			case 0:
				positionBalle.y -= depBalle.y;
				if (positionBalle.y == 0)
				{
					directionBalle.y = 1;
				}
				break;
			}
			switch (directionBalle.x)
			{
			case 1:
				positionBalle.x += depBalle.x;
				if (positionBalle.x == 770)
				{
					if (positionBalle.y < hautGaucheDeux.y && positionBalle.y > basGaucheDeux.y)
					{
						directionBalle.x = 0;
					}
				}
				break;
			case 0:
				positionBalle.x -= depBalle.x;
				if (positionBalle.x == 30)
				{
					if (positionBalle.y < hautDroitUn.y && positionBalle.y > basDroitUn.y)
					{
						directionBalle.x = 1;
					}
				}
				break;
			}
			SDL_BlitSurface(balle, NULL, ecran, &positionBalle);
			SDL_Flip(ecran);
		}
	}
}