#include	"render.h"
#include	"data.h"
#include	"sdldata.h"
#include	"xship.h"
#include	"menu.h"

void		render(void)
{
  Data*		d = SDLazy_GetData();
  v2f		v;

  pos_onscreen(&v, &d->sdldata.cam, v2f_(SDLazy_GetWidth(d->sdldata.srf_bg[BG0]) / -2,
					 SDLazy_GetHeight(d->sdldata.srf_bg[BG0]) / -2));

  SDL_FillRect(SDLazy_GetScreen(), 0, 0);

  SDLazy_SetPos(d->sdldata.srf_bg[BG0], &v);
  SDLazy_Blit(d->sdldata.srf_bg[BG0]);

  ammos_blit(&d->sdldata, &d->ammos);

  xship_blit(&d->sdldata, (XShip*)d->player);

  menu_blit(&d->menu);
}
