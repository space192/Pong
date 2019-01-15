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
	int ScoreJoueurUn = 0;
	int ScoreJoueurDeux = 0;
	init_graphics(800, 600);

	PositionBalle.x = 400; PositionBalle.y = 300;
	balle(PositionBalle);
	
	JoueursUnCentre.x = 20; JoueursUnCentre.y = 300;
	Joueurs(JoueursUnCentre);

	JoueursDeuxCentre.x = 780; JoueursDeuxCentre.y = 300;
	Joueurs(JoueursDeuxCentre);

	LigneMillieuHaut.x = 400 ; LigneMillieuHaut.y = 600;
	LigneMillieuBas.x = 400; LigneMillieuBas.y = 0;
	draw_line(LigneMillieuBas, LigneMillieuHaut, blanc);
	
	ScoresJoueurUn(ScoreJoueurUn);
	ScoresJoueurDeux(ScoreJoueurDeux);

	wait_escape();
	return(0);
}