#include "graphics.h"
void balle(POINT PositionBalle);
void Joueurs(POINT JoueursUnCentre);
void Joueurs(POINT JoueursDeuxCentre);
void ScoresJoueurUn(int ScoreJoueurUn);
void ScoresJoueurDeux(int ScoreJoueurDeux);

int main(int argc, char *argv[])
{
	POINT PositionBalle;
	POINT JoueursUnCentre;
	POINT JoueursDeuxCentre;
	POINT LigneMillieuHaut;
	POINT LigneMillieuBas;
	POINT get_arrow();
	POINT get_arrow2();
	POINT PositionJoueurUn;
	POINT PositionJoueurDeux;
	int ScoreJoueurUn = 0;
	int ScoreJoueurDeux = 0;
	init_graphics(800, 600);


	PositionBalle.x = 400; PositionBalle.y = 300;
	balle(PositionBalle);

	LigneMillieuHaut.x = 400 ; LigneMillieuHaut.y = 600;
	LigneMillieuBas.x = 400; LigneMillieuBas.y = 0;
	draw_line(LigneMillieuBas, LigneMillieuHaut, blanc);
	
	ScoresJoueurUn(ScoreJoueurUn);
	ScoresJoueurDeux(ScoreJoueurDeux);
	PositionJoueurUn.x = 0; PositionJoueurUn.y = 0;
	PositionJoueurDeux.x = 0; PositionJoueurDeux.y = 0;
	while (ScoreJoueurUn < 5)
	{
		PositionJoueurUn.y = PositionJoueurUn.y + get_arrow2().y;
		JoueursUnCentre.x = 20; JoueursUnCentre.y = 300 + (PositionJoueurUn.y * 2);
		Joueurs(JoueursUnCentre);

		PositionJoueurDeux.y = PositionJoueurDeux.y + get_arrow().y;
		JoueursDeuxCentre.x = 780; JoueursDeuxCentre.y = 300 + (PositionJoueurDeux.y * 2);
		Joueurs(JoueursDeuxCentre);
	}

	wait_escape();
	return(0);
}
