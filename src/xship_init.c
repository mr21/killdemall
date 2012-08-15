#include	<string.h>
#include	"xship.h"
#include	"sdldata.h"

void		xship_init(SDLData* d, XShip* p)
{
  unsigned	u;

  memset(p, 0, sizeof *p);
  p->entity.mxspd = 300.;
  p->entity.accel = 0.15;
  for (u = 0; u < 8; ++u)
    {
      p->turret_anim[u] = SDLazy_AnimCreate(d->srf[SRF_AN_TIR], 7, 7, ANIM_PAUSE);
      SDLazy_SetCenter(p->turret_anim[u], v2f_(-23, -1.5));
    }
  SDLazy_SetScaleY(p->turret_anim[0], -1);
  SDLazy_SetRot(p->turret_anim[0], RADIANS(-90));
  SDLazy_SetRot(p->turret_anim[1], RADIANS(-90));
  SDLazy_SetScaleY(p->turret_anim[2], -1);
  SDLazy_SetScaleY(p->turret_anim[4], -1);
  SDLazy_SetRot(p->turret_anim[4], RADIANS(90));
  SDLazy_SetRot(p->turret_anim[5], RADIANS(90));
  SDLazy_SetScaleX(p->turret_anim[6], -1);
  SDLazy_SetScale(p->turret_anim[7], v2f_(-1, -1));
}
