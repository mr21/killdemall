#include	"sdldata.h"

void		sdldata_init(SDLData* d)
{
  d->srf_bgs[BG0]		= SDLazy_SurfaceLoad("img/bg.jpg", NULL);

  d->cam.x = d->cam.y = 0;

  d->srf_ship[SRF_SHIP_NO]	= SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect(20, 20, 23, 23));
  d->srf_ship[SRF_SHIP_NE]	= SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect(43, 20, 23, 23));
  d->srf_ship[SRF_SHIP_SO]	= SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect(20, 43, 23, 23));
  d->srf_ship[SRF_SHIP_SE]	= SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect(43, 43, 23, 23));

  SDLazy_SetCenterAlign(d->srf_ship[SRF_SHIP_NO], ALIGN_BOTTOM | ALIGN_RIGHT);
  SDLazy_SetCenterAlign(d->srf_ship[SRF_SHIP_NE], ALIGN_BOTTOM | ALIGN_LEFT);
  SDLazy_SetCenterAlign(d->srf_ship[SRF_SHIP_SO], ALIGN_TOP | ALIGN_RIGHT);
  SDLazy_SetCenterAlign(d->srf_ship[SRF_SHIP_SE], ALIGN_TOP | ALIGN_LEFT);

  d->srf_ship[SRF_SHIP_AN_TURRET]	= SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect(100, 70, 11, 10));
}
