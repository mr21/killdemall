#include	"kamship.h"

void		kamship_init(KamShip* s)
{
  ship_init(&s->ship, KAMSHIP);
  s->target = NULL;
}
