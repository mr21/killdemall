#include	"SDLazy.h"
#include	"menu.h"

void		menu_blit(Menu* d)
{
  double	x = SDLazy_GetPosX(d->srf[SRF_MENU_BG]);
  double	h2 = SDLazy_GetHeight(0) / 2;

  SDLazy_SetScaleY(d->srf[SRF_MENU_BG], h2 / 4);
  SDLazy_Blit(d->srf[SRF_MENU_BG]);

  SDLazy_SetPosX(d->btn[BTN_MENU_FULLSCREEN], x + 95);
  SDLazy_Blit(d->btn[BTN_MENU_FULLSCREEN]);

  SDLazy_SetPosX(d->btn[BTN_MENU_KEYBOARD], x - 2);
  SDLazy_Blit(d->btn[BTN_MENU_KEYBOARD]);

  SDLazy_SetPosX(d->btn[BTN_MENU_COMMANDS], x - 2);
  SDLazy_Blit(d->btn[BTN_MENU_COMMANDS]);

  SDLazy_SetPos(d->btn[BTN_MENU_OPEN], v2f_(x - 6, h2));
  SDLazy_Blit(d->btn[BTN_MENU_OPEN]);
}
