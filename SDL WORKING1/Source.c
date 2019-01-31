#include "graphics.h"
#include <stdio.h>
#include "unistd.h"
void balle(POINT PositionBalle);
void Joueurs(POINT JoueursUnCentre);
void Joueurs(POINT JoueursDeuxCentre);
void ScoresJoueurUn(int ScoreJoueurUn);
void ScoresJoueurDeux(int ScoreJoueurDeux);

int main(int argc, char *argv[])
{
	int tailleFenetreX = 800;
	int tailleFenetreY = 600;
	POINT PositionBalle;
	POINT JoueursUnCentre;
	POINT JoueursDeuxCentre;
	POINT get_arrow();
	POINT PositionJoueurUn;
	POINT PositionJoueurDeux;
	POINT depBalle;
	POINT anciennePositionBalle;
	POINT directionBalle;
	int ScoreJoueurUn = 0;
	int ScoreJoueurDeux = 0;
	int scorePartie = 0;
	init_graphics(tailleFenetreX, tailleFenetreY);
	PositionBalle.x = 400; PositionBalle.y = 300;
	depBalle.x = 1; depBalle.y = 1;
	
	ScoresJoueurUn(ScoreJoueurUn);
	ScoresJoueurDeux(ScoreJoueurDeux);
	PositionJoueurUn.x = 0; PositionJoueurUn.y = 0;
	PositionJoueurDeux.x = 0; PositionJoueurDeux.y = 0;
	
	directionBalle.y = 1;
	directionBalle.x = 1;
	while (scorePartie < 10)
	{
		PositionJoueurUn.y = PositionJoueurUn.y + get_arrow().x;
		JoueursUnCentre.x = 20; JoueursUnCentre.y = 300 + (PositionJoueurUn.y * 2);				//déplacement des pods
		Joueurs(JoueursUnCentre);

		PositionJoueurDeux.y = PositionJoueurDeux.y + get_arrow().y;
		JoueursDeuxCentre.x = 780; JoueursDeuxCentre.y = 300 + (PositionJoueurDeux.y * 2);
		Joueurs(JoueursDeuxCentre);

		
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
			if (PositionBalle.x == 800)
			{
				directionBalle.x = 0;
			}
			break;
		case 0:
			PositionBalle.x -= depBalle.x;
			if (PositionBalle.x == 0)
			{
				directionBalle.x = 1;
			}
			break;
		}
		balle(PositionBalle);
	}


	wait_escape();
	return(0);
}
