#include "graphics.h"
#include <stdio.h>
#include "unistd.h"
#include <stdlib.h>
#include <SDL.h>
void balle(POINT PositionBalle);
void Joueurs(POINT JoueursUnCentre);
void Joueurs(POINT JoueursDeuxCentre);
void ScoresJoueurUn(int ScoreJoueurUn);
void ScoresJoueurDeux(int ScoreJoueurDeux);

int main(int argc, char *argv[])
{
	int tailleFenetreX = 800;
	int tailleFenetreY = 700;
	POINT PositionBalle;
	POINT JoueursUnCentre;
	POINT JoueursDeuxCentre;
	POINT get_arrow();
	POINT PositionJoueurUn;
	POINT BasDroitUn;
	POINT HautDroitUn;
	POINT PositionJoueurDeux;
	POINT BasGaucheDeux;
	POINT HautGaucheDeux;
	POINT depBalle;
	POINT directionBalle;
	POINT multiDirectionBalle;
	POINT ligneHautGauche;
	POINT ligneHautDroite;
	int ScoreJoueurUn = 0;
	int ScoreJoueurDeux = 0;
	int scorePartie = 0;
	init_graphics(tailleFenetreX, tailleFenetreY);
	ligneHautGauche.x = 0; ligneHautGauche.y = 607;
	ligneHautDroite.x = 800; ligneHautDroite.y = 607;
	draw_line(ligneHautDroite, ligneHautGauche, blanc);
	PositionBalle.x = 400; PositionBalle.y = 300;
	depBalle.x = 1; depBalle.y = 1;


	SDL_Surface *ecran = NULL, *zozor = NULL;
	SDL_Rect positionZozor;

	positionZozor.x = 400;
	positionZozor.y = 350;

	SDL_Init(SDL_INIT_VIDEO);


	/* Chargement et blittage de Zozor sur la scène */
	zozor = SDL_LoadBMP("zozor.bmp");
	SDL_BlitSurface(zozor, NULL, &positionZozor);

	pause();

	SDL_FreeSurface(zozor);
	SDL_Quit();


	ScoresJoueurUn(ScoreJoueurUn);
	ScoresJoueurDeux(ScoreJoueurDeux);

	PositionJoueurUn.x = 0; PositionJoueurUn.y = 0;
	PositionJoueurDeux.x = 0; PositionJoueurDeux.y = 0;

	directionBalle.y = 1;
	directionBalle.x = 1;
	while (scorePartie < 10)
	{
		multiDirectionBalle = get_arrow();



		switch (multiDirectionBalle.x) //getarrow.x correspond au déplacement en y du joueur 1
		{
		case 1:
			PositionJoueurUn.y = PositionJoueurUn.y + multiDirectionBalle.x;
			break;
		case -1:
			PositionJoueurUn.y = PositionJoueurUn.y + multiDirectionBalle.x;
			break;
		}
		switch (multiDirectionBalle.y) //getarrow.y correspond au déplacement en y du joueur 2
		{
		case 1:
			PositionJoueurDeux.y = PositionJoueurDeux.y + multiDirectionBalle.y;
			break;
		case -1:
			PositionJoueurDeux.y = PositionJoueurDeux.y + multiDirectionBalle.y;
			break;
		}
		JoueursUnCentre.x = 20; JoueursUnCentre.y = 300 + (PositionJoueurUn.y * 2);				//déplacement des pods
		if (JoueursUnCentre.y > 506)
		{
			JoueursUnCentre.y = 506;
		}
		else if (JoueursUnCentre.y < 100)
		{
			JoueursUnCentre.y = 100;
		}
		Joueurs(JoueursUnCentre);

		JoueursDeuxCentre.x = 780; JoueursDeuxCentre.y = 300 + (PositionJoueurDeux.y * 2);
		if (JoueursDeuxCentre.y > 506)
		{
			JoueursDeuxCentre.y = 506;
		}
		else if (JoueursDeuxCentre.y < 100)
		{
			JoueursDeuxCentre.y = 100;
		}
		Joueurs(JoueursDeuxCentre);

		BasDroitUn.x = JoueursUnCentre.x + 10;
		BasDroitUn.y = JoueursUnCentre.y - 100;
		HautDroitUn.x = JoueursUnCentre.x + 10;
		HautDroitUn.y = JoueursUnCentre.y + 100;

		BasGaucheDeux.x = JoueursDeuxCentre.x - 10;
		BasGaucheDeux.y = JoueursDeuxCentre.y - 100;
		HautGaucheDeux.x = JoueursDeuxCentre.x - 10;
		HautGaucheDeux.y = JoueursDeuxCentre.y + 100;

		if (PositionBalle.x == 800)
		{
			ScoreJoueurUn++;
			PositionBalle.x = 400;
			PositionBalle.y = 300;
			ScoresJoueurUn(ScoreJoueurUn);
		}
		else if (PositionBalle.x == 0)
		{
			ScoreJoueurDeux++;
			PositionBalle.x = 400;
			PositionBalle.y = 300;
			ScoresJoueurDeux(ScoreJoueurDeux);
		}
		else
		{

			switch (directionBalle.y)
			{
			case 1:
				PositionBalle.y += depBalle.y;
				if (PositionBalle.y == 600)
				{
					directionBalle.y = 0;
				}
				break;
			case 0:
				PositionBalle.y -= depBalle.y;
				if (PositionBalle.y == 0)
				{
					directionBalle.y = 1;
				}
				break;
			}
			switch (directionBalle.x)
			{
			case 1:
				PositionBalle.x += depBalle.x;
				if (PositionBalle.x == 770)
				{
					if (PositionBalle.y < HautGaucheDeux.y && PositionBalle.y > BasGaucheDeux.y)
					{
						directionBalle.x = 0;
					}
				}
				break;
			case 0:
				PositionBalle.x -= depBalle.x;
				if (PositionBalle.x == 30)
				{
					if (PositionBalle.y < HautDroitUn.y && PositionBalle.y > BasDroitUn.y)
					{
						directionBalle.x = 1;
					}
				}
				break;
			}
			balle(PositionBalle);
		}
	}
	wait_escape();
	return(0);
}
