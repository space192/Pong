#include "graphics.h"
void balle(POINT PositionFigure);
void Joueurs(POINT JoueursCentre);

int main(int argc, char *argv[])
{
	POINT PositionFigure;
	POINT JoueursCentre;
	init_graphics(800, 600);

	PositionFigure.x = 400; PositionFigure.y = 300;
	balle(PositionFigure);

	JoueursCentre.x = 20; JoueursCentre.y = 250;
	Joueurs(JoueursCentre);

	wait_escape();
	return(0);
}
