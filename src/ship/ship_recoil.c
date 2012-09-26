#include	"ship.h"

void		ship_recoil(Ship* s, double recoil, int dir)
{
  if (dir & SHIP_AXE_X)
    s->dir.x += recoil / s->weight;
  if (dir & SHIP_AXE_Y)
    s->dir.y += recoil / s->weight;
}
