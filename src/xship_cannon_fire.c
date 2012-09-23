#include	"xship.h"
#include	"sound.h"

void		xship_cannon_fire(XShip* s)
{
  sound_play(SND_XSHIP_CANNON, .8, 0, 44100);
  SDLazy_AnimReplay(s->cannon_anim);
}
