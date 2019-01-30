#include "graphics.h"

POINT depballe()
{
	POINT movBalle;
	movBalle.x = movBalle.y = 0;

	movBalle.x = movBalle.x + 2;
	movBalle.y = movBalle.y + 2;
	return movBalle;
}