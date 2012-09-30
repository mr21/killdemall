#include	"xship.h"

void		xship_event_arrows(XShip* s, eShipDir dir, char press)
{
  s->shoot_dir = press ? s->shoot_dir | dir : s->shoot_dir ^ dir;
  ship_resetfq((Ship*)s);
}
