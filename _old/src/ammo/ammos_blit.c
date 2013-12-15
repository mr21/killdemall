#include		"ammo.h"
#include		"sdldata.h"
#include		"render.h"

static SDLData*		g_d;

static int		blit(Ammo* b)
{
  SDLazy_Surface*	am = g_d->srf_ammo[b->type];
  v2f			v;

  pos_onscreen(&v, &g_d->cam, &b->pos);
  SDLazy_SetPos(am, &v);
  SDLazy_SetRot(am, b->rad);
  SDLazy_Blit(am);
  return CLIST_CONTINUE;
}

void			ammos_blit(SDLData* d, CList* ammos)
{
  g_d = d;
  CList_foreach(ammos, blit);
}
