#include "graphics.h"

void Joueurs(POINT JoueursCentre)
{
	POINT BasGauchePrincip;
	POINT HautDroitPrincip;
	POINT BasGaucheSecond;
	POINT HautDroitSecond;
	POINT BasGaucheters;
	POINT HautDroitters;
	POINT destockageBasGauchePrincip;
	POINT destockageHautDroitPrincip;


	BasGauchePrincip.x = JoueursCentre.x - 10;
	BasGauchePrincip.y = JoueursCentre.y - 100;
	HautDroitPrincip.x = JoueursCentre.x + 10;
	HautDroitPrincip.y = JoueursCentre.y + 100;

	destockageBasGauchePrincip = BasGauchePrincip;
	destockageHautDroitPrincip = HautDroitPrincip;

	draw_fill_rectangle(BasGauchePrincip, HautDroitPrincip, blanc);

	draw_fill_rectangle(destockageBasGauchePrincip, destockageHautDroitPrincip, noir);
}
