#include	"render.h"
#include	"data.h"
#include	"sdldata.h"
#include	"menu.h"
#include	"xship.h"
#include	"kamship.h"

static int	ship_blit(Ship* s)
{
  switch (s->type)
    {
    case XSHIP:	  xship_blit((XShip*)s);     break;
    case KAMSHIP: kamship_blit((KamShip*)s); break;
    }
  return CLIST_CONTINUE;
}

static void	ships_blit(CList* ships)
{
  CList_foreach(ships, ship_blit);
}

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

  ships_blit(&d->ships);
  ammos_blit(&d->sdldata, &d->ammos);
  menu_blit(&d->menu);
}
