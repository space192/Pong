#include "graphics.h"

void Joueurs(POINT JoueursCentre)
{
	POINT BasGauchePrincip;
	POINT HautDroitPrincip;
	POINT BasGaucheSecond;
	POINT HautDroitSecond;
	POINT BasGaucheters;
	POINT HautDroitters;

	BasGauchePrincip.x = JoueursCentre.x - 10;
	BasGauchePrincip.y = JoueursCentre.y - 100;
	HautDroitPrincip.x = JoueursCentre.x + 10;
	HautDroitPrincip.y = JoueursCentre.y + 100;

	draw_fill_rectangle(BasGauchePrincip, HautDroitPrincip, blanc);

	BasGaucheSecond.x = JoueursCentre.x - 10;
	BasGaucheSecond.y = JoueursCentre.y + 100;
	HautDroitSecond.x = JoueursCentre.x - 10;
	HautDroitSecond.y = JoueursCentre.y + 200;

	draw_fill_rectangle(BasGaucheSecond, HautDroitSecond, noir);

	BasGaucheters.x = JoueursCentre.x - 10;
	BasGaucheters.y = JoueursCentre.y - 200;
	HautDroitters.x = JoueursCentre.x + 10;
	HautDroitters.y = JoueursCentre.y + 300;

	draw_fill_rectangle(BasGaucheters, HautDroitters, noir);
}
