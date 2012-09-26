#include	"kamship.h"
#include	"data.h"
#include	"sdldata.h"

void		kamship_init(KamShip* s)
{
  SDLData*	d = &((Data*)SDLazy_GetData())->sdldata;

  ship_init(&s->ship, KAMSHIP);
  s->spr_body = SDLazy_SpriteCreate(d->srf_kamship[SRF_KAMSHIP_BODY]);
  s->target = NULL;
}
