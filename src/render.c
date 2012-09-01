#include	"render.h"
#include	"data.h"
#include	"sdldata.h"
#include	"xship.h"

static void	menu(SDLData* d)
{
  SDLazy_SetScaleY(d->srf_menu[SRF_MENU_BG], SDLazy_GetHeight(0) / 2.0);
  SDLazy_Blit(d->srf_menu[SRF_MENU_BG]);
}

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


  menu(&d->sdldata);
}
