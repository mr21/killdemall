#include	"xship.h"

void		xship_move(XShip* s, int dir, int press)
{
  (press ? SDLazy_AnimPlay : SDLazy_AnimStop)(s->reactor_anim[dir]);
}
