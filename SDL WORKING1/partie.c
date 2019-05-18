#include "graphics.h"
#include <stdio.h>
#include "unistd.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
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
	SDL_Surface *score0;
	SDL_Surface *score1;
	SDL_Surface *score2;
	SDL_Surface *score3;
	SDL_Surface *score4;
	SDL_Surface *score5;
	Mix_Music *rebond;
	Mix_Music *score;
	int scoreJoueurUn = 0;
	int scoreJoueurDeux = 0;
	int vitesse = 10;
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
	positionBalle.x = 400; positionBalle.y = 300;
	positionScoreJoueurUn.x = 200; positionJoueurUn.y = 50;
	positionScoreJoueurDeux.x = 600; positionScoreJoueurDeux.y = 0;
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
	score0 = IMG_Load("0.bmp");
	score1 = IMG_Load("1.bmp");
	score2 = IMG_Load("2.bmp");
	score3 = IMG_Load("3.bmp");
	score4 = IMG_Load("4.bmp");
	score5 = IMG_Load("5.bmp");
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
	rebond = Mix_LoadMUS("rebond.wav");
	score = Mix_LoadMUS("point.wav");

	while ((scoreJoueurUn < 5) && (scoreJoueurDeux < 5))
	{
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		depJoueur = get_arrow();
		positionJoueurUn.y = positionJoueurUn.y + (depJoueur.x * 10);
		positionJoueurDeux.y = positionJoueurDeux.y + (depJoueur.y * 10);
		if (positionJoueurUn.y > 575)
		{
			positionJoueurUn.y = 575;
		}
		else if (positionJoueurUn.y < 100)
		{
			positionJoueurUn.y = 100;
		}
		SDL_BlitSurface(player, NULL, ecran, &positionJoueurUn);
		if (positionJoueurDeux.y > 575)
		{
			positionJoueurDeux.y = 575;
		}
		else if (positionJoueurDeux.y < 100)
		{
			positionJoueurDeux.y = 100;
		}
		SDL_BlitSurface(player2, NULL, ecran, &positionJoueurDeux);
		SDL_BlitSurface(ligne, NULL, ecran, &positionLigne);
		basDroitUn.x = 50;
		basDroitUn.y = positionJoueurUn.y + 125;
		hautDroitUn.x = 50;
		hautDroitUn.y = positionJoueurUn.y;

		basGaucheDeux.x = 770;
		basGaucheDeux.y = positionJoueurDeux.y + 125;
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
			scoreJoueurUn++;
			vitesse = 10;
			Mix_PlayMusic(score, 1);
		}
		else if (positionBalle.x == 0)
		{
			positionBalle.x = 400;
			positionBalle.y = 350;
			scoreJoueurDeux++;
			vitesse = 10;
			Mix_PlayMusic(score, 1);
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
					Mix_PlayMusic(rebond, 1);
				}
				break;
			case 0:
				positionBalle.y -= depBalle.y;
				if (positionBalle.y == 100)
				{
					directionBalle.y = 1;
					Mix_PlayMusic(rebond, 1);
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
						Mix_PlayMusic(rebond, 1);
						if (vitesse > 2)
						{
							vitesse = vitesse - 0.5;
						}
						
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
						Mix_PlayMusic(rebond, 1);
						if (vitesse > 2)
						{
							vitesse = vitesse - 0.5;
						}
						
					}
				}
				break;
			}
			switch (scoreJoueurUn)
			{
			case 0:
				SDL_BlitSurface(score0, NULL, ecran, &positionScoreJoueurUn);
				break;
			case 1:
				SDL_BlitSurface(score1, NULL, ecran, &positionScoreJoueurUn);
				break;
			case 2:
				SDL_BlitSurface(score2, NULL, ecran, &positionScoreJoueurUn);
				break;
			case 3:
				SDL_BlitSurface(score3, NULL, ecran, &positionScoreJoueurUn);
				break;
			case 4:
				SDL_BlitSurface(score4, NULL, ecran, &positionScoreJoueurUn);
				break;
			case 5:
				SDL_BlitSurface(score5, NULL, ecran, &positionScoreJoueurUn);
				break;
			}
			switch (scoreJoueurDeux)
			{
			case 0:
				SDL_BlitSurface(score0, NULL, ecran, &positionScoreJoueurDeux);
				break;
			case 1:
				SDL_BlitSurface(score1, NULL, ecran, &positionScoreJoueurDeux);
				break;
			case 2:
				SDL_BlitSurface(score2, NULL, ecran, &positionScoreJoueurDeux);
				break;
			case 3:
				SDL_BlitSurface(score3, NULL, ecran, &positionScoreJoueurDeux);
				break;
			case 4:
				SDL_BlitSurface(score4, NULL, ecran, &positionScoreJoueurDeux);
				break;
			case 5:
				SDL_BlitSurface(score5, NULL, ecran, &positionScoreJoueurDeux);
				break;
			}
			SDL_BlitSurface(balle, NULL, ecran, &positionBalle);
			SDL_Flip(ecran);
			SDL_Delay(vitesse / 2);
		}
	}
	Mix_FreeMusic(rebond);
	Mix_FreeMusic(score);
	Mix_CloseAudio();
	return scoreJoueurUn;
	return scoreJoueurDeux;
}