#include	"xship.h"

void            xship_upshoot(XShip* s, char press)
{
  ((Ship*)s)->shoot_dir = press ? ((Ship*)s)->shoot_dir | DIR_UP : ((Ship*)s)->shoot_dir ^ DIR_UP;
  ship_resetfq((Ship*)s);
}

void            xship_rightshoot(XShip* s, char press)
{
  ((Ship*)s)->shoot_dir = press ? ((Ship*)s)->shoot_dir | DIR_RIGHT : ((Ship*)s)->shoot_dir ^ DIR_RIGHT;
  ship_resetfq((Ship*)s);
}

void            xship_downshoot(XShip* s, char press)
{
  ((Ship*)s)->shoot_dir = press ? ((Ship*)s)->shoot_dir | DIR_DOWN : ((Ship*)s)->shoot_dir ^ DIR_DOWN;
  ship_resetfq((Ship*)s);
}

void            xship_leftshoot(XShip* s, char press)
{
  ((Ship*)s)->shoot_dir = press ? ((Ship*)s)->shoot_dir | DIR_LEFT : ((Ship*)s)->shoot_dir ^ DIR_LEFT;
  ship_resetfq((Ship*)s);
}
