#include	"kamship.h"
#include	"data.h"
#include	"sdldata.h"

void		kamship_init(KamShip* k)
{
  SDLData*	d = &((Data*)SDLazy_GetData())->sdldata;
  Ship*		s = (Ship*)k;

  ship_init(s, KAMSHIP);
  ship_setweight(s, 1.03);
  s->blit = kamship_blit;
  s->core = kamship_core;
  s->left_clic = kamship_event_leftclic;
  k->spr_body = SDLazy_SpriteCreate(d->srf_kamship[SRF_KAMSHIP_BODY]);
  k->dest.x = 0.;
  k->dest.y = 0.;
}
