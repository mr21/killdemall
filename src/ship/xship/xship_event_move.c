#include	"xship.h"

int		tmp(unsigned n)
{
  switch (n)
    {
    default: return 0;
    case 2: return 1;
    case 4: return 2;
    case 8: return 3;
    }
}

void		xship_event_wasd(XShip* s, eShipDir dir, char press)
{
  s->move_dir = press ? s->move_dir | dir : s->move_dir ^ dir;
  (press ? SDLazy_AnimPlay : SDLazy_AnimStop)(s->reactor_anim[]);
}

/*------------------------------------*/

void		xship_forward(XShip* s, char press)
{
  s->dir_press[1] = press;
  (press ? SDLazy_AnimPlay : SDLazy_AnimStop)(s->reactor_anim[2]);
}

void		xship_rightward(XShip* s, char press)
{
  s->dir_press[2] = press;
  (press ? SDLazy_AnimPlay : SDLazy_AnimStop)(s->reactor_anim[3]);
}

void		xship_leftward(XShip* s, char press)
{
  s->dir_press[0] = press;
  (press ? SDLazy_AnimPlay : SDLazy_AnimStop)(s->reactor_anim[1]);
}

void		xship_backward(XShip* s, char press)
{
  s->dir_press[3] = press;
  (press ? SDLazy_AnimPlay : SDLazy_AnimStop)(s->reactor_anim[0]);
}
