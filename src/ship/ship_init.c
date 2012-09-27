#include	<string.h>
#include	"ship.h"
#include	"null.h"

void		ship_init(Ship* s, eShipType type)
{
  memset(s, 0, sizeof *s);
  s->left_clic = null;
  ship_setweight(s, 1);
  s->type = type;
}
