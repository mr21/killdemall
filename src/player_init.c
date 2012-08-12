#include	<string.h>
#include	"player.h"
#include	"sdldata.h"

void		player_init(SDLData* d, Player* p)
{
  unsigned	u;

  memset(p, 0, sizeof *p);
  p->entity.mxspd = 300.;
  p->entity.accel = 0.15;
  for (u = 0; u < 8; ++u)
    {
      p->anim_tirs[u] = SDLazy_AnimCreate(d->srf[SRF_AN_TIR], 7, 7, ANIM_PAUSE);
      SDLazy_SetCenter(p->anim_tirs[u], v2f_(-23, -1.5));
    }
  SDLazy_SetRot(p->anim_tirs[0], RADIANS(-90));
  SDLazy_SetScaleY(p->anim_tirs[1], -1);
  SDLazy_SetScaleY(p->anim_tirs[3], -1);
  SDLazy_SetRot(p->anim_tirs[3], RADIANS(90));
  SDLazy_SetRot(p->anim_tirs[4], RADIANS(90));
  SDLazy_SetScaleX(p->anim_tirs[5], -1);
  SDLazy_SetScale(p->anim_tirs[6], v2f_(-1, -1));
  SDLazy_SetScaleY(p->anim_tirs[7], -1);
  SDLazy_SetRot(p->anim_tirs[7], RADIANS(-90));
}
