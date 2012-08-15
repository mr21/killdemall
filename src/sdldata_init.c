#include	"sdldata.h"

void		sdldata_init(SDLData* d)
{
  d->srf[SRF_BG]	= SDLazy_SurfaceLoad("img/bg.jpg",      NULL);

  d->cam.x = d->cam.y = 0;

  d->srf[SRF_P_NO]	= SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect(20, 20, 23, 23));
  d->srf[SRF_P_NE]	= SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect(43, 20, 23, 23));
  d->srf[SRF_P_SO]	= SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect(20, 43, 23, 23));
  d->srf[SRF_P_SE]	= SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect(43, 43, 23, 23));

  SDLazy_SetCenterAlign(d->srf[SRF_P_NO], ALIGN_BOTTOM | ALIGN_RIGHT);
  SDLazy_SetCenterAlign(d->srf[SRF_P_NE], ALIGN_BOTTOM | ALIGN_LEFT);
  SDLazy_SetCenterAlign(d->srf[SRF_P_SO], ALIGN_TOP | ALIGN_RIGHT);
  SDLazy_SetCenterAlign(d->srf[SRF_P_SE], ALIGN_TOP | ALIGN_LEFT);

  d->srf[SRF_AN_TIR]	= SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect(100, 70, 11, 10));
}
