#include	"xship.h"

#define		LIM	12
#define		SPD	6

/*
  La logique entre les nombres de ce fichier,
  est tout bonnement incomprehensible...
  Je vais revoir l'algo qui a été moulte fois modifie ces temps-ci
*/

static int	bit2dec(unsigned n)
{
  switch (n)
    {
    default:
    case DIR_UP:    return 1;
    case DIR_DOWN:  return 3;
    case DIR_RIGHT: return 2;
    case DIR_LEFT:  return 2;
    }
}

static void	move(XShip* s, int spr, eShipDir dir, int tur)
{
  double	d;
  int		dec = bit2dec(dir);

  d = -(dec % 2 ? SDLazy_GetCenterX : SDLazy_GetCenterY)(s->bases_sprite[spr]);
  if (s->move_dir & dir)
    d += LIM;
  d *= SPD * SDLazy_GetFrameTime();
  (dec % 2 ? SDLazy_IncCenterX : SDLazy_IncCenterY)(s->bases_sprite[spr], +d);
  (dec % 2 ? SDLazy_IncCenterX : SDLazy_IncCenterY)(s->bases_sprite[spr + 1 + !(dec % 2)], -d);

  SDLazy_IncCenterX(s->turret_anim[tur + 0], d);
  SDLazy_IncCenterX(s->turret_anim[tur + 1], d);

  SDLazy_IncCenterY(s->turret_anim[tur ? tur - 1 : 7], d);
  SDLazy_IncCenterY(s->turret_anim[(tur + 2) % 8], d);
}

void		xship_core_move_bases(XShip* s)
{
  move(s, 0, DIR_DOWN,  0);
  move(s, 1, DIR_LEFT,  2);
  move(s, 2, DIR_UP,    4);
  move(s, 0, DIR_RIGHT, 6);
}
