#include	"xship.h"

int		_which_reactor(unsigned n)
{
  switch (n)
    {
    default:
    case DIR_DOWN:  return 0;
    case DIR_LEFT:  return 1;
    case DIR_UP:    return 2;
    case DIR_RIGHT: return 3;
    }
}

void		xship_event_wasd(XShip* s, eShipDir dir, char press)
{
  s->move_dir = press ? s->move_dir | dir : s->move_dir ^ dir;
  (press ? SDLazy_AnimPlay : SDLazy_AnimStop)(s->reactor_anim[_which_reactor(dir)]);
}
