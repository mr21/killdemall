#include	"xship.h"
#include	"data.h"
#include	"sdldata.h"
#include	"render.h"

void		xship_blit(XShip* s)
{
  SDLData*	d = &((Data*)SDLazy_GetData())->sdldata;
  v2f		v;
  unsigned	u;

  pos_onscreen(&v, &d->cam, &s->ship.pos);

  for (u = 0; u < 4; ++u)
    SDLazy_SetPos(s->reactor_anim[u], &v),
      SDLazy_Blit(s->reactor_anim[u]);
  SDLazy_SetPos(d->srf_xship[SRF_XSHIP_BASE], &v);
  SDLazy_Blit(d->srf_xship[SRF_XSHIP_BASE]);
  for (u = 0; u < 4; ++u)
    SDLazy_SetPos(s->bases_sprite[u], &v),
      SDLazy_Blit(s->bases_sprite[u]);
  for (u = 0; u < 8; ++u)
    SDLazy_SetPos(s->turret_anim[u], &v),
      SDLazy_Blit(s->turret_anim[u]);
  SDLazy_SetPos(d->srf_xship[SRF_XSHIP_TOP], &v);
  SDLazy_Blit(d->srf_xship[SRF_XSHIP_TOP]);

  SDLazy_SetPos(s->cannon_anim, &v);
  SDLazy_Blit(s->cannon_anim);
}
