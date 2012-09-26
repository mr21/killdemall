#include	"SDLazy.h"
#include	"menu.h"

void		menu_core(Menu* d)
{
  static int	w;
  double	x = SDLazy_GetPosX(d->srf[SRF_MENU_BG]);

  if (!w)
    w = SDLazy_GetWidth(d->srf[SRF_MENU_BG]) - SDLazy_GetCenterX(d->srf[SRF_MENU_BG]);
  x -= (d->status ? (w + x) : x) * .2;
  SDLazy_SetPosX(d->srf[SRF_MENU_BG], x);
}
