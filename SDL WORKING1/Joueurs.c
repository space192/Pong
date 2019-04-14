#include "graphics.h"
#include "SDL.h"
#include "SDL_image.h"

int Joueurs(SDL_Rect positionJoueurs, SDL_Surface *ecran)
{
	SDL_Surface *player = NULL;

	player = IMG_Load("Pod_Joueurs.bmp");
	SDL_SetColorKey(player, SDL_SRCCOLORKEY, SDL_MapRGB(player->format, 0, 0, 255));
	SDL_BlitSurface(player, NULL, ecran, &positionJoueurs);
}
