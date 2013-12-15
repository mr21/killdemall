#include	"xship.h"

static void	_move(Ship* s, double* tmp, int neg)
{
  if (neg)
    {
      if (*tmp > -s->mxspd + .01 && (*tmp -= s->mxspd / s->accel * SDLazy_GetFrameTime()) < -s->mxspd)
	*tmp = -s->mxspd;
    }
  else if (*tmp < +s->mxspd - .01 && (*tmp += s->mxspd / s->accel * SDLazy_GetFrameTime()) > +s->mxspd)
    *tmp = +s->mxspd;
}

void		xship_core_dir(XShip* xs)
{
  Ship*		s = (Ship*)xs;

  if (xs->move_dir & DIR_LEFT && !(xs->move_dir & DIR_RIGHT))
    _move(s, &s->dir.x, 1);
  else if (xs->move_dir & DIR_RIGHT && !(xs->move_dir & DIR_LEFT))
    _move(s, &s->dir.x, 0);
  if (xs->move_dir & DIR_UP && !(xs->move_dir & DIR_DOWN))
    _move(s, &s->dir.y, 1);
  else if (xs->move_dir & DIR_DOWN && !(xs->move_dir & DIR_UP))
    _move(s, &s->dir.y, 0);
}
