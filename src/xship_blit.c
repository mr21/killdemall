#include	"xship.h"
#include	"sdldata.h"
#include	"render.h"

void		xship_blit(SDLData* d, XShip* s)
{
  v2f		v = *pos_onscreen(&d->cam, &s->ship.pos);
  unsigned	u;

  for (u = 0; u < 4; ++u)
    {
      SDLazy_SetPos(s->bases_sprite[u], &v);
      SDLazy_Blit(s->bases_sprite[u]);
    }
  for (u = 0; u < 8; ++u)
    {
      SDLazy_SetPos(s->turret_anim[u], &v);
      SDLazy_Blit(s->turret_anim[u]);
    }
}
