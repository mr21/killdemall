#include		"ammo.h"
#include		"sdldata.h"
#include		"render.h"

static SDLData*		g_d;

static void		blit(Ammo* b)
{
  SDLazy_Surface*	am = g_d->srf_ammo[b->type];

  SDLazy_SetPos(am, pos_onscreen(&g_d->cam, &b->pos));
  SDLazy_Blit(am);
}

void			ammos_blit(SDLData* d, CList* ammos)
{
  g_d = d;
  CList_foreach(ammos, blit);
}
