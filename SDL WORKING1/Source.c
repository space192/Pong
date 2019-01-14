#include "graphics.h"
#define TailleX 300
#define TailleY 300
#define CoteCarre 100
int main(int argc, char *argv[])
{
	POINT CarreBasGauche;
	POINT CarreHautDroite;
	POINT CercleCentre;
	POINT CercleCentre2;

	init_graphics(TailleX, TailleY);


	CercleCentre.x = 0.5 * TailleX; CercleCentre.y = 0.5 * TailleY;
	draw_fill_circle(CercleCentre, 0.45 * CoteCarre, rouge);


	CercleCentre2.x = 0.5 * TailleX; CercleCentre2.y = 0.5 * TailleY;
	draw_fill_circle(CercleCentre2, 0.25 * CoteCarre, noir);



	wait_escape();
	return(0);
}
