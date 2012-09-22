#include	<string.h>
#include	"xship.h"
#include	"sdldata.h"

static void	_turrets(SDLData* d, XShip* s)
{
  unsigned	u;

  for (u = 0; u < 8; ++u)
    {
      s->turret_anim[u] = SDLazy_AnimCreate(d->srf_ship[SRF_SHIP_TURRET], 7, 7, ANIM_PAUSE);
      SDLazy_SetCenter(s->turret_anim[u], v2f_(10.5, 34));
    }
  SDLazy_SetScaleX (s->turret_anim[1], -1);
  SDLazy_SetRot    (s->turret_anim[2], RADIANS(+90));
  SDLazy_SetRot    (s->turret_anim[3], RADIANS(+90));
  SDLazy_SetScaleX (s->turret_anim[3], -1);
  SDLazy_SetScale  (s->turret_anim[4], v2f_(-1, -1));
  SDLazy_SetScaleY (s->turret_anim[5], -1);
  SDLazy_SetRot    (s->turret_anim[6], RADIANS(-90));
  SDLazy_SetRot    (s->turret_anim[7], RADIANS(-90));
  SDLazy_SetScaleX (s->turret_anim[7], -1);
}

static void	_reactors(SDLData* d, XShip* s)
{
  unsigned	u;

  for (u = 0; u < 4; ++u)
    {
      s->reactor_anim[u] = SDLazy_AnimCreate(d->srf_ship[SRF_SHIP_REACTOR], 9, 5, ANIM_STOP);
      SDLazy_SetCenterAlign(s->reactor_anim[u], ALIGN_CENTER | ALIGN_BOTTOM);
      SDLazy_SetCenter(s->reactor_anim[u], v2f_(-0.2, 8.5));
      SDLazy_AnimTimer(s->reactor_anim[u], 70);
    }
  SDLazy_SetRot(s->reactor_anim[1], M_PI2);
  SDLazy_SetRot(s->reactor_anim[2], M_PI);
  SDLazy_SetRot(s->reactor_anim[3], -M_PI2);
}

static void	_base(SDLData* d, XShip* s)
{
  unsigned	u;

  for (u = 0; u < 4; ++u)
    s->bases_sprite[u] = SDLazy_SpriteCreate(d->srf_ship[SRF_SHIP_NO + u]);
}

static void	_cannon(SDLData* d, XShip* s)
{
  s->cannon_anim = SDLazy_AnimCreate(d->srf_ship[SRF_SHIP_CANNON], 8, 8, ANIM_PAUSE);
  SDLazy_SetCenter(s->cannon_anim, v2f_(6, 47));
  SDLazy_AnimTimer(s->cannon_anim, 40);
}

void		xship_init(SDLData* d, XShip* s)
{
  memset(s, 0, sizeof *s);
  _turrets(d, s);
  _reactors(d, s);
  _base(d, s);
  _cannon(d, s);
  s->ship.mxspd      = 300; /* 300 */
  s->ship.accel      = 0.15; /* 0.15 */
  s->ship.weight     = 1.07; /* 1.07 */
  s->ship.shtfq_max  = 0.05; /* 0.05 */
  s->ship.shtfq_lost = 1.1;
  s->ship.shtfq_curr = s->ship.shtfq_max;
}
