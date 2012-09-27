#include	"xship.h"

void		xship_core_dir(XShip* xs)
{
  Ship*		s = (Ship*)xs;
  double*       tmp;
  int           i;

  for (i = 0; i < 2; ++i)
    {
      tmp = i ? &s->dir.y : &s->dir.x;
      if (s->dir_press[i] && !s->dir_press[i + 2])
        {
          if (*tmp > -s->mxspd + .01 &&
              (*tmp -= s->mxspd / s->accel * SDLazy_GetFrameTime()) < -s->mxspd)
            *tmp = -s->mxspd;
        }
      else if (s->dir_press[i + 2] && !s->dir_press[i])
        {
          if (*tmp < +s->mxspd - .01 &&
              (*tmp += s->mxspd / s->accel * SDLazy_GetFrameTime()) > +s->mxspd)
            *tmp = +s->mxspd;
        }
    }
}
