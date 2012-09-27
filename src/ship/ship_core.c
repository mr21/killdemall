#include	"ship.h"

void		ship_core(Ship* s)
{
  s->pos.x += s->dir.x * SDLazy_GetFrameTime();
  s->pos.y += s->dir.y * SDLazy_GetFrameTime();
  s->dir.x /= s->weight;
  s->dir.y /= s->weight;
}
