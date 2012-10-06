#include	"kamship.h"
#include	"data.h"
#include	"sdldata.h"

void		kamship_init(KamShip* ks)
{
  SDLData*	d = &((Data*)SDLazy_GetData())->sdldata;
  Ship*		s = (Ship*)ks;

  ship_init(s, KAMSHIP);
  s->blit = kamship_blit;
  s->core = kamship_core;
  s->left_clic = kamship_event_leftclic;
  ks->spr_body = SDLazy_SpriteCreate(d->srf_kamship[SRF_KAMSHIP_BODY]);
  ks->target = NULL;
}
