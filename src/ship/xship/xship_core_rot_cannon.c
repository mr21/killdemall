#include	"xship.h"

void		xship_core_rot_cannon(XShip* s)
{
  v2f		v = *SDLazy_GetPos(s->cannon_anim);
  double	d;

  v.x = SDLazy_GetMouseX() - v.x;
  v.y = SDLazy_GetMouseY() - v.y;
  if (!v.y)
    d = v.x > 0 ? M_PI2 : -M_PI2;
  else
    {
      d = -atan(v.x / v.y);
      if (v.y > 0)
	d += M_PI;
    }
  SDLazy_SetRot(s->cannon_anim, d);
}
