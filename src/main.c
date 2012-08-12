#include	"data.h"
#include	"events.h"
#include	"core.h"

static void	initSDLData(SDLData* d)
{
  d->srf[SRF_BG]	= SDLazy_SurfaceLoad("img/bg.jpg",	NULL);

  d->cam.x = d->cam.y = 0;

  d->srf[SRF_P_NO]	= SDLazy_SurfaceLoad("img/sprites.png",	SDLazy_Rect(20, 20, 23, 23));
  d->srf[SRF_P_NE]	= SDLazy_SurfaceLoad("img/sprites.png",	SDLazy_Rect(43, 20, 23, 23));
  d->srf[SRF_P_SO]	= SDLazy_SurfaceLoad("img/sprites.png",	SDLazy_Rect(20, 43, 23, 23));
  d->srf[SRF_P_SE]	= SDLazy_SurfaceLoad("img/sprites.png",	SDLazy_Rect(43, 43, 23, 23));

  SDLazy_SetCenterAlign(d->srf[SRF_P_NO], ALIGN_BOTTOM | ALIGN_RIGHT);
  SDLazy_SetCenterAlign(d->srf[SRF_P_NE], ALIGN_BOTTOM | ALIGN_LEFT);
  SDLazy_SetCenterAlign(d->srf[SRF_P_SO], ALIGN_TOP | ALIGN_RIGHT);
  SDLazy_SetCenterAlign(d->srf[SRF_P_SE], ALIGN_TOP | ALIGN_LEFT);

  d->srf[SRF_AN_TIR]	= SDLazy_SurfaceLoad("img/sprites.png",	SDLazy_Rect(100, 70, 11, 10));
}

int		main(void)
{
  Data		d;

  SDLazy_Init(1000, 500, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE, "Shoot'em Up - SDL 2D");
  
  initSDLData(&d.sdldata);
  player_init(&d.sdldata, &d.player);

  SDLazy_SetCursor(CURSOR_CROSS);

  SDLazy_AddEvent(SDL_KEYDOWN, evKeydown);
  SDLazy_AddEvent(SDL_KEYUP, evKeyup);
  SDLazy_AddEvent(SDL_MOUSEMOTION, evMousemove);
  SDLazy_AddEvent(SDL_QUIT, evQuit);

  SDLazy_Loop(&d, core, render);

  return 0;
}
