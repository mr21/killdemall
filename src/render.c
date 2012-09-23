#include	"render.h"
#include	"data.h"
#include	"sdldata.h"
#include	"xship.h"
#include	"menu.h"

void		render(void)
{
  static Uint32	bg_col;
  Data*		d = SDLazy_GetData();
  v2f		v;

  if (!bg_col)
    bg_col = SDL_MapRGB(SDLazy_GetScreen()->format, 15, 15, 21);

  pos_onscreen(&v, &d->sdldata.cam, v2f_(SDLazy_GetWidth(d->sdldata.srf_bg[BG0]) / -2,
					 SDLazy_GetHeight(d->sdldata.srf_bg[BG0]) / -2));

  SDL_FillRect(SDLazy_GetScreen(), 0, bg_col);

  SDLazy_SetPos(d->sdldata.srf_bg[BG0], &v);
  SDLazy_Blit(d->sdldata.srf_bg[BG0]);

  xship_blit(&d->sdldata, (XShip*)d->player);

  ammos_blit(&d->sdldata, &d->ammos);

  menu_blit(&d->menu);
}
