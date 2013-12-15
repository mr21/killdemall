#include	<string.h>
#include	"ship.h"
#include	"null.h"

void		ship_init(Ship* s, eShipType type)
{
  memset(s, 0, sizeof *s);
  s->type = type;
  s->target = NULL;
  s->core = null;
  s->left_clic = null;
  s->arrows = null;
  s->wasd = null;
  s->blit = null;
  ship_setweight(s, 1);
}
