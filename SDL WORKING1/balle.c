#include "graphics.h"

void balle(POINT FigureCentre)
{
	POINT BasGaucheBalle;
	POINT HautDroitBalle;
	POINT destockageBasGaucheBalle;
	POINT destockageHautDroitBalle;

	BasGaucheBalle.x = FigureCentre.x - 6;
	BasGaucheBalle.y = FigureCentre.y - 6;
	HautDroitBalle.x = FigureCentre.x + 6;
	HautDroitBalle.y = FigureCentre.y + 6;

	destockageBasGaucheBalle = BasGaucheBalle;
	destockageHautDroitBalle = HautDroitBalle;

	draw_fill_rectangle(BasGaucheBalle, HautDroitBalle, blanc);

	draw_fill_rectangle(destockageBasGaucheBalle, destockageHautDroitBalle, noir);
}

