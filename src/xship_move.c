#include	"xship.h"

#define		LIM	7

static void	move(XShip* s, unsigned spr, unsigned key, unsigned turret)
{
  double	d;

  d = -(key % 2 ? SDLazy_GetCenterX : SDLazy_GetCenterY)(s->bases_sprite[spr]);
  if (s->ship.dir_press[key])
    d += LIM;
  d *= 15. * SDLazy_GetFrameTime();
  (key % 2 ? SDLazy_IncCenterX : SDLazy_IncCenterY)(s->bases_sprite[spr], +d);
  (key % 2 ? SDLazy_IncCenterX : SDLazy_IncCenterY)(s->bases_sprite[spr + 1 + !(key % 2)], -d);

  SDLazy_IncCenterY(s->turret_anim[turret + 0], -d);
  SDLazy_IncCenterY(s->turret_anim[turret + 1], -d);

  SDLazy_IncCenterX(s->turret_anim[turret ? turret - 1 : 7], -d);
  SDLazy_IncCenterX(s->turret_anim[(turret + 2) % 8], -d);
}

void		xship_move(XShip* s)
{
  move(s, 0, 3, 0);
  move(s, 2, 1, 4);
  move(s, 0, 2, 6);
  move(s, 1, 0, 2);
}
