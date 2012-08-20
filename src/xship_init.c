#include	<string.h>
#include	"xship.h"
#include	"sdldata.h"

static void	_turrets(SDLData* d, XShip* s)
{
  unsigned	u;

  for (u = 0; u < 8; ++u)
    {
      s->turret_anim[u] = SDLazy_AnimCreate(d->srf_ship[SRF_SHIP_AN_TURRET], 7, 7, ANIM_PAUSE);
      SDLazy_SetCenter(s->turret_anim[u], v2f_(-23, -1.5));
    }
  SDLazy_SetScaleY (s->turret_anim[0], -1);
  SDLazy_SetRot    (s->turret_anim[0], RADIANS(-90));
  SDLazy_SetRot    (s->turret_anim[1], RADIANS(-90));
  SDLazy_SetScaleY (s->turret_anim[2], -1);
  SDLazy_SetScaleY (s->turret_anim[4], -1);
  SDLazy_SetRot    (s->turret_anim[4], RADIANS(+90));
  SDLazy_SetRot    (s->turret_anim[5], RADIANS(+90));
  SDLazy_SetScaleX (s->turret_anim[6], -1);
  SDLazy_SetScale  (s->turret_anim[7], v2f_(-1, -1));
}

static void	_base(SDLData* d, XShip* s)
{
  unsigned	u;

  for (u = 0; u < 4; ++u)
    s->bases_sprite[u] = SDLazy_SpriteCreate(d->srf_ship[SRF_SHIP_NO + u]);
}

void		xship_init(SDLData* d, XShip* s)
{
  memset(s, 0, sizeof *s);
  _turrets(d, s);
  _base(d, s);
  s->ship.mxspd = 300.;
  s->ship.accel = 0.15;
  s->ship.weight = 1.;
}
