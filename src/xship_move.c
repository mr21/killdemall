#include	"xship.h"

void		xship_move(Data* d, XShip* s, int dir, int press)
{
  (void)d;
  (press ? SDLazy_AnimPlay : SDLazy_AnimStop)(s->reactor_anim[dir]);
}
