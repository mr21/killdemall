#include	"xship.h"
#include	"sound.h"
#include	"ammo.h"

void		xship_cannon_fire(XShip* s)
{
  Ammo		b;
  double	radAn = SDLazy_GetRot(s->cannon_anim);

  b.type = AMMO_ROCKET;
  b.from_who = (Ship*)s;
  b.duration_time = 1.;
  b.rad = radAn;
  b.dir.x = sin(radAn);
  b.dir.y = cos(radAn - M_PI);
  b.pos.x = s->ship.pos.x + b.dir.x * 40;
  b.pos.y = s->ship.pos.y + b.dir.y * 40;
  ship_recoil((Ship*)s, -b.dir.x * 200, SHIP_AXE_X);
  ship_recoil((Ship*)s, -b.dir.y * 200, SHIP_AXE_Y);
  b.dir.x *= 700.;
  b.dir.y *= 700.;
  ammo_push(SDLazy_GetData(), &b);
  sound_play(SND_XSHIP_CANNON, .8, 0, 30000 + rand() % 15000);
  SDLazy_AnimReplay(s->cannon_anim);
}
