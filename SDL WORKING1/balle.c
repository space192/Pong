#include "graphics.h"

void balle(POINT FigureCentre)
{
	POINT BasGaucheBalle;
	POINT HautDroitBalle;

	BasGaucheBalle.x = FigureCentre.x - 4;
	BasGaucheBalle.y = FigureCentre.y - 4;
	HautDroitBalle.x = FigureCentre.x + 4;
	HautDroitBalle.y = FigureCentre.y + 4;

	draw_fill_rectangle(BasGaucheBalle, HautDroitBalle, blanc);
}

