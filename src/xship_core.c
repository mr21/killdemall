#include	"xship.h"

void		xship_core(XShip* s)
{
  v2f		v = *SDLazy_GetPos(s->cannon_anim);
  double	d;

  v.x = SDLazy_GetMouseX() - v.x;
  v.y = SDLazy_GetMouseY() - v.y;
  d = v.y ? -atan(v.x / v.y) : 0;
  if (v.y > 0)
    d += M_PI;
  else if (!v.y)
    d = v.x > 0 ? M_PI2 : -M_PI2;
  SDLazy_SetRot(s->cannon_anim, d);
}
