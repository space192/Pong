#include "graphics.h"
#include "SDL.h"
#include "SDL_image.h"

void balle(SDL_Rect positionBalle, SDL_Surface *ecran)
{
	SDL_Surface *balles = NULL;

	balles = IMG_Load("balle.bmp");
	SDL_SetColorKey(balles, SDL_SRCCOLORKEY, SDL_MapRGB(balles->format, 0, 0, 255));
	SDL_BlitSurface(balles, NULL, ecran, &positionBalle);
}

