#include	"data.h"
#include	"sdldata.h"
#include	"render.h"
#include	"kamship.h"

void		kamship_blit(KamShip* k)
{
  SDLData*	d = &((Data*)SDLazy_GetData())->sdldata;
  v2f		v;

  pos_onscreen(&v, &d->cam, &k->ship.pos);
  SDLazy_SetPos(k->spr_body, &v);
  SDLazy_Blit(k->spr_body);
}
