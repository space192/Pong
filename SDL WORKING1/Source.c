#include "graphics.h"
void balle(POINT PositionFigure);

int main(int argc, char *argv[])
{
	POINT PositionFigure;
	init_graphics(800, 600);

	PositionFigure.x = 400; PositionFigure.y = 300;
	balle(PositionFigure);


	wait_escape();
	return(0);
}
