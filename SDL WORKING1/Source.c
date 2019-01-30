#include "graphics.h"
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
	POINT LigneMillieuHaut;
	POINT LigneMillieuBas;
	POINT get_arrow();
	POINT PositionJoueurUn;
	POINT PositionJoueurDeux;
	int ScoreJoueurUn = 0;
	int ScoreJoueurDeux = 0;
	int scorePartie = 0;
	init_graphics(tailleFenetreX, tailleFenetreY);
	PositionBalle.x = 400; PositionBalle.y = 300;


	LigneMillieuHaut.x = 400 ; LigneMillieuHaut.y = 600;
	LigneMillieuBas.x = 400; LigneMillieuBas.y = 0;
	draw_line(LigneMillieuBas, LigneMillieuHaut, blanc);
	
	ScoresJoueurUn(ScoreJoueurUn);
	ScoresJoueurDeux(ScoreJoueurDeux);
	PositionJoueurUn.x = 0; PositionJoueurUn.y = 0;
	PositionJoueurDeux.x = 0; PositionJoueurDeux.y = 0;
	
	
	while (scorePartie < 10)
	{
		PositionJoueurUn.y = PositionJoueurUn.y + get_arrow().x;
		JoueursUnCentre.x = 20; JoueursUnCentre.y = 300 + (PositionJoueurUn.y * 2);				//d�placement des pods
		Joueurs(JoueursUnCentre);

		PositionJoueurDeux.y = PositionJoueurDeux.y + get_arrow().y;
		JoueursDeuxCentre.x = 780; JoueursDeuxCentre.y = 300 + (PositionJoueurDeux.y * 2);
		Joueurs(JoueursDeuxCentre);

		PositionBalle.x = PositionBalle.x + 2;
		PositionBalle.y = PositionBalle.y + 2;
		balle(PositionBalle);

	}

	wait_escape();
	return(0);
}
