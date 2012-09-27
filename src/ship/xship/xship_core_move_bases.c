#include	"xship.h"

#define		LIM	12
#define		SPD	6

static void	move(XShip* s, int spr, int key, int tur)
{
  double	d;

  d = -(key % 2 ? SDLazy_GetCenterX : SDLazy_GetCenterY)(s->bases_sprite[spr]);
  if (s->ship.dir_press[key])
    d += LIM;
  d *= SPD * SDLazy_GetFrameTime();
  (key % 2 ? SDLazy_IncCenterX : SDLazy_IncCenterY)(s->bases_sprite[spr], +d);
  (key % 2 ? SDLazy_IncCenterX : SDLazy_IncCenterY)(s->bases_sprite[spr + 1 + !(key % 2)], -d);

  SDLazy_IncCenterX(s->turret_anim[tur + 0], d);
  SDLazy_IncCenterX(s->turret_anim[tur + 1], d);

  SDLazy_IncCenterY(s->turret_anim[tur ? tur - 1 : 7], d);
  SDLazy_IncCenterY(s->turret_anim[(tur + 2) % 8], d);
}

void		xship_core_move_bases(XShip* s)
{
  move(s, 0, 3, 0);
  move(s, 2, 1, 4);
  move(s, 0, 2, 6);
  move(s, 1, 0, 2);
}
