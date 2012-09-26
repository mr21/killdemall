#include	"data.h"
#include	"sdldata.h"
#include	"render.h"
#include	"kamship.h"

void		kamship_blit(KamShip* s)
{
  SDLData*	d = &((Data*)SDLazy_GetData())->sdldata;
  v2f		v;

  pos_onscreen(&v, &d->cam, &s->ship.pos);
  SDLazy_SetPos(d->srf_kamship[SRF_KAMSHIP_BODY], &v);
  SDLazy_Blit(d->srf_kamship[SRF_KAMSHIP_BODY]);
}
