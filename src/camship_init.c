#include	"camship.h"

void		camship_init(CamShip* s)
{
  ship_init(&s->ship);
  s->target = NULL;
}
