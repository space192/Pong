#include "graphics.h"
void balle(POINT PositionFigure);
void Joueurs(POINT JoueursUnCentre);
void Joueurs(POINT JoueursDeuxCentre);

int main(int argc, char *argv[])
{
	POINT PositionFigure;
	POINT JoueursUnCentre;
	POINT JoueursDeuxCentre;
	POINT LigneMillieu;
	init_graphics(800, 600);

	PositionFigure.x = 400; PositionFigure.y = 300;
	balle(PositionFigure);

	JoueursUnCentre.x = 20; JoueursUnCentre.y = 300;
	Joueurs(JoueursUnCentre);

	JoueursDeuxCentre.x = 400; JoueursDeuxCentre.y = 300;
	Joueurs(JoueursDeuxCentre);
	

	wait_escape();
	return(0);
}
