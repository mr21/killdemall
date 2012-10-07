#include	"kamship.h"

void		kamship_event_leftclic(KamShip* k)
{
  k->dest = *SDLazy_GetPos(k->spr_body);
  k->dest.x = SDLazy_GetMouseX() - k->dest.x;
  k->dest.y = SDLazy_GetMouseY() - k->dest.y;
}
