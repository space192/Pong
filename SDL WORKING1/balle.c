#include "graphics.h"

void balle(POINT FigureCentre)
{
	POINT BasGaucheBalle;
	POINT HautDroitBalle;
	POINT destockageBasGaucheBalle;
	POINT destockageHautDroitBalle;

	BasGaucheBalle.x = FigureCentre.x - 4;
	BasGaucheBalle.y = FigureCentre.y - 4;
	HautDroitBalle.x = FigureCentre.x + 4;
	HautDroitBalle.y = FigureCentre.y + 4;

	destockageBasGaucheBalle = BasGaucheBalle;
	destockageHautDroitBalle = HautDroitBalle;

	draw_fill_rectangle(BasGaucheBalle, HautDroitBalle, blanc);

	draw_fill_rectangle(destockageBasGaucheBalle, destockageHautDroitBalle, noir);
}

