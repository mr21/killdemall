#include	"ship.h"

void		ship_setaccel  (Ship* s, double acc ) { s->accel      = acc;          }
void		ship_setspd_max(Ship* s, double max ) { s->mxspd      = max;          }
void		ship_setweight (Ship* s, double w   ) { s->weight     = w;            }
void		ship_setpos    (Ship* s, v2f*   pos ) { s->pos        = *pos;         }
void		ship_setfq_max (Ship* s, double fq  ) { s->shtfq_max  = fq;           }
void		ship_setfq_lost(Ship* s, double lost) { s->shtfq_lost = lost;         }
void		ship_resetfq   (Ship* s)              { s->shtfq_curr = s->shtfq_max; }
void		ship_settarget (Ship* s, Ship* trg)   { s->target     = trg;          }
