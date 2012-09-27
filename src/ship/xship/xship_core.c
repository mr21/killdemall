#include	"xship.h"

void		xship_core(XShip* s)
{
  xship_core_rot_cannon(s);
  xship_core_move_bases(s);
  xship_core_shoot(s);
  xship_core_dir(s);
}
