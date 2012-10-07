#include	"kamship.h"

void		kamship_event_leftclic(KamShip* k)
{
  k->ship.dir = *SDLazy_GetPos(k->spr_body);
  k->ship.dir.x = SDLazy_GetMouseX() - k->ship.dir.x;
  k->ship.dir.y = SDLazy_GetMouseY() - k->ship.dir.y;
}
