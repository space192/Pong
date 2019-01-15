#include "graphics.h"
void balle(POINT PositionFigure);
void Joueurs(POINT JoueursUnCentre);
void Joueurs(POINT JoueursDeuxCentre);

int main(int argc, char *argv[])
{
	POINT PositionFigure;
	POINT JoueursUnCentre;
	POINT JoueursDeuxCentre;
	POINT LigneMillieuHaut;
	POINT LigneMillieuBas;
	init_graphics(800, 600);

	PositionFigure.x = 400; PositionFigure.y = 300;
	balle(PositionFigure);

	JoueursUnCentre.x = 20; JoueursUnCentre.y = 300;
	Joueurs(JoueursUnCentre);

	JoueursDeuxCentre.x = 780; JoueursDeuxCentre.y = 300;
	Joueurs(JoueursDeuxCentre);
	
	LigneMillieuHaut.x = 400; LigneMillieuHaut.y = 600;
	LigneMillieuBas.x = 400; LigneMillieuBas.y = 0;
	draw_line(LigneMillieuBas, LigneMillieuHaut, blanc);
	

	wait_escape();
	return(0);
}
