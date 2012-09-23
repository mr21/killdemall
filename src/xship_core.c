#include	"xship.h"

void		xship_core(XShip* s)
{
  v2f		v = *SDLazy_GetPos(s->cannon_anim);
  double	d;

  v.x = g_sdlazy.mouse.x - v.x;
  v.y = g_sdlazy.mouse.y - v.y;
  d = v.y ? -atan(v.x / v.y) : 0;
  if (v.y >= 0)
    d += M_PI;
  SDLazy_SetRot(s->cannon_anim, d);
}
