#include	"xship.h"

void            xship_upshoot(XShip* s, char press)
{
  s->shoot_dir = press ? s->shoot_dir | DIR_UP : s->shoot_dir ^ DIR_UP;
  ship_resetfq((Ship*)s);
}

void            xship_rightshoot(XShip* s, char press)
{
  s->shoot_dir = press ? s->shoot_dir | DIR_RIGHT : s->shoot_dir ^ DIR_RIGHT;
  ship_resetfq((Ship*)s);
}

void            xship_downshoot(XShip* s, char press)
{
  s->shoot_dir = press ? s->shoot_dir | DIR_DOWN : s->shoot_dir ^ DIR_DOWN;
  ship_resetfq((Ship*)s);
}

void            xship_leftshoot(XShip* s, char press)
{
  s->shoot_dir = press ? s->shoot_dir | DIR_LEFT : s->shoot_dir ^ DIR_LEFT;
  ship_resetfq((Ship*)s);
}
