#include	"core.h"

void		ship_move(Ship* s)
{
  double	mxspd = s->mxspd;
  double*	tmp;
  int		i;

  for (i = 0; i < 2; ++i)
    {
      tmp = i ? &s->dir.y : &s->dir.x;
      if (s->dir_press[i] && !s->dir_press[i + 2])
	{
	  if (*tmp > -mxspd + .01 &&
	      (*tmp -= mxspd / s->accel * SDLazy_GetFrameTime()) < -mxspd)
	    *tmp = -mxspd;
	}
      else if (s->dir_press[i + 2] && !s->dir_press[i])
	{
	  if (*tmp < +mxspd - .01 &&
	      (*tmp += mxspd / s->accel * SDLazy_GetFrameTime()) > +mxspd)
	    *tmp = +mxspd;
	}
      *tmp /= s->weight;
    }
  s->pos.x += s->dir.x * SDLazy_GetFrameTime();
  s->pos.y += s->dir.y * SDLazy_GetFrameTime();
}
