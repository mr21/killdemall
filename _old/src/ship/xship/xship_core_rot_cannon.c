#include	"xship.h"
#include	"data.h"

void		xship_core_rot_cannon(XShip* x)
{
  v2f		v;
  double	rad;

  if ((Ship*)x == ((Data*)SDLazy_GetData())->player)
    {
      v = *SDLazy_GetPos(x->cannon_anim);
      v.x = SDLazy_GetMouseX() - v.x;
      v.y = SDLazy_GetMouseY() - v.y;
      if (!v.y)
	rad = v.x > 0 ? M_PI2 : -M_PI2;
      else
	{
	  rad = -atan(v.x / v.y);
	  if (v.y > 0)
	    rad += M_PI;
	}
      SDLazy_SetRot(x->cannon_anim, rad);
    }
}
