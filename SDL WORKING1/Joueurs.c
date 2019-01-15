#include "graphics.h"

void Joueurs(POINT JoueursCentre)
{
	POINT BasGauche;
	POINT HautDroit;

	BasGauche.x = JoueursCentre.x - 10;
	BasGauche.y = JoueursCentre.y - 100;
	HautDroit.x = JoueursCentre.x + 10;
	HautDroit.y = JoueursCentre.y + 100;

	draw_fill_rectangle(BasGauche, HautDroit, blanc);
}
