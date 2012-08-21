#include	"core.h"

/*
debug:
printf("X(%+6.1f /%+6.1f) ; Y(%+6.1f /%+6.1f)\n",
       e->dir.x, e->dir_press[0] * -mxspd + e->dir_press[2] * mxspd,
       e->dir.y, e->dir_press[1] * -mxspd + e->dir_press[3] * mxspd);
*/

void		ship_move(Data* d, Ship* s)
{
  const double	friction = 0.1;
  double	mxspd = s->mxspd;
  double*	tmp;
  int		i;
  (void)d;

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
      else
	*tmp *= 1 - friction;
    }
  s->pos.x += s->dir.x * SDLazy_GetFrameTime();
  s->pos.y += s->dir.y * SDLazy_GetFrameTime();
}
