#include	"xship.h"

#define		LIM	7

static void	move(XShip* s, unsigned spr, unsigned key)
{
  double	d;

  d = -(key % 2 ? SDLazy_GetCenterX : SDLazy_GetCenterY)(s->bases_sprite[spr]);
  if (s->ship.dir_press[key])
    d += LIM;
  d *= 15. * SDLazy_GetFrameTime();
  (key % 2 ? SDLazy_IncCenterX : SDLazy_IncCenterY)(s->bases_sprite[spr], +d);
  (key % 2 ? SDLazy_IncCenterX : SDLazy_IncCenterY)(s->bases_sprite[spr + 1 + !(key % 2)], -d);
}

void		xship_move(XShip* s)
{
  move(s, 0, 3);
  move(s, 2, 1);
  move(s, 0, 2);
  move(s, 1, 0);
}
