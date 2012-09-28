#include	"ship.h"
#include	"xship.h"

/*
Ce code est encore temporaire.. l'heritage n'est pas très logique ici :S
*/

void		ship_forward(Ship* s, char press)
{
  s->dir_press[1] = press;
  xship_move((XShip*)s, 2, press);
}

void		ship_rightward(Ship* s, char press)
{
  s->dir_press[2] = press;
  xship_move((XShip*)s, 3, press);
}

void		ship_leftward(Ship* s, char press)
{
  s->dir_press[0] = press;
  xship_move((XShip*)s, 1, press);
}

void		ship_backward(Ship* s, char press)
{
  s->dir_press[3] = press;
  xship_move((XShip*)s, 0, press);
}

void            ship_upshoot(Ship* s, char press)
{
  s->shoot_dir = press ? s->shoot_dir | DIR_UP : s->shoot_dir ^ DIR_UP;
  ship_resetfq(s);
}

void            ship_rightshoot(Ship* s, char press)
{
  s->shoot_dir = press ? s->shoot_dir | DIR_RIGHT : s->shoot_dir ^ DIR_RIGHT;
  ship_resetfq(s);
}

void            ship_downshoot(Ship* s, char press)
{
  s->shoot_dir = press ? s->shoot_dir | DIR_DOWN : s->shoot_dir ^ DIR_DOWN;
  ship_resetfq(s);
}

void            ship_leftshoot(Ship* s, char press)
{
  s->shoot_dir = press ? s->shoot_dir | DIR_LEFT : s->shoot_dir ^ DIR_LEFT;
  ship_resetfq(s);
}
