#include	<string.h>
#include	"ship.h"

void		ship_init(Ship* s, eShipType type)
{
  memset(s, 0, sizeof *s);
  s->type = type;
  s->mxspd      = 300;
  s->accel      = 0.15;
  s->weight     = 1.07;
  s->shtfq_curr = s->shtfq_max  = 0.05;
  s->shtfq_lost = 1.1;
}

void		ship_setpos(Ship* s, v2f* pos)
{
  s->pos = *pos;
}

void		ship_setfq_max(Ship* s, double fq)
{
  s->shtfq_curr = s->shtfq_max = fq;
}

void		ship_setfq_lost(Ship* s, double lost)
{
  s->shtfq_lost = lost;
}
