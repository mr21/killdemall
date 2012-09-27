#include	<string.h>
#include	"ship.h"

void		ship_init(Ship* s, eShipType type)
{
  memset(s, 0, sizeof *s);
  ship_setweight(s, 1);
  s->type = type;
}
