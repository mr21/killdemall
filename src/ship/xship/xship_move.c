#include	"xship.h"

void		xship_forward(XShip* s, char press)
{
  s->ship.dir_press[1] = press;
  (press ? SDLazy_AnimPlay : SDLazy_AnimStop)(s->reactor_anim[2]);
}

void		xship_rightward(XShip* s, char press)
{
  s->ship.dir_press[2] = press;
  (press ? SDLazy_AnimPlay : SDLazy_AnimStop)(s->reactor_anim[3]);
}

void		xship_leftward(XShip* s, char press)
{
  s->ship.dir_press[0] = press;
  (press ? SDLazy_AnimPlay : SDLazy_AnimStop)(s->reactor_anim[1]);
}

void		xship_backward(XShip* s, char press)
{
  s->ship.dir_press[3] = press;
  (press ? SDLazy_AnimPlay : SDLazy_AnimStop)(s->reactor_anim[0]);
}
