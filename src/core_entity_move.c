#include	"core.h"

/*
debug:
printf("X(%+6.1f /%+6.1f) ; Y(%+6.1f /%+6.1f)\n",
       e->dir.x, e->dir_press[0] * -mxspd + e->dir_press[2] * mxspd,
       e->dir.y, e->dir_press[1] * -mxspd + e->dir_press[3] * mxspd);
*/

void		core_entity_move(Data* d, Entity* e)
{
  const double	friction = 0.1;
  double	mxspd, *tmp;
  int		i;
  (void)d;

  for (i = 0; i < 2; ++i)
    {
      tmp = i ? &e->dir.y : &e->dir.x;
      mxspd = e->mxspd;
      if (e->dir_press[i] && !e->dir_press[i + 2])
	{
	  if (e->dir_press[!i] || e->dir_press[!i + 2])
	    mxspd /= 2.;
	  if (*tmp > -mxspd + .01 &&
	      (*tmp -= mxspd / e->accel * SDLazy_GetFrameTime()) < -mxspd)
	    *tmp = -mxspd;
	}
      else if (e->dir_press[i + 2] && !e->dir_press[i])
	{
	  if (e->dir_press[!i] || e->dir_press[!i + 2])
	    mxspd /= 2.;
	  if (*tmp < +mxspd - .01 &&
	      (*tmp += mxspd / e->accel * SDLazy_GetFrameTime()) > +mxspd)
	    *tmp = +mxspd;
	}
      else
	*tmp *= 1 - friction;
    }
  e->pos.x += e->dir.x * SDLazy_GetFrameTime();
  e->pos.y += e->dir.y * SDLazy_GetFrameTime();
}
