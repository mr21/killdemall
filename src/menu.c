#include	"menu.h"
#include	"controls.h"

void		menu_init(Menu* d)
{
  SDLazy_Button*        b;

  d->srf[SRF_MENU_BG]       = SDLazy_SurfaceLoad("img/menu_bg.png",  NULL);
  d->srf[SRF_MENU_KEYBOARD] = SDLazy_SurfaceLoad("img/keyboard.png", SDLazy_Rect(0, 0, 128, 36));

  SDLazy_SetCenterAlign(d->srf[SRF_MENU_BG], ALIGN_TOP | ALIGN_RIGHT);
  SDLazy_SetPosAlign(d->srf[SRF_MENU_BG], ALIGN_TOP | ALIGN_RIGHT);

  b = SDLazy_ButtonCreate(d->srf[SRF_MENU_KEYBOARD], 2);
  SDLazy_SetCenterAlign(b, ALIGN_TOP | ALIGN_RIGHT);
  SDLazy_SetPosAlign(b, ALIGN_TOP | ALIGN_RIGHT);
  SDLazy_SetPosY(b, 20);
  SDLazy_ButtonSetFun(b, BUTTON_CLICUP, ctrls_switch);

  d->btn[BTN_MENU_KEYBOARD] = b;
}

void		menu_blit(Menu* d)
{
  SDLazy_SetScaleY(d->srf[SRF_MENU_BG], SDLazy_GetHeight(0) / 2.0);
  SDLazy_Blit(d->srf[SRF_MENU_BG]);

  SDLazy_SetPosX(d->btn[BTN_MENU_KEYBOARD], SDLazy_GetPosX(d->srf[SRF_MENU_BG]) - 8);
  SDLazy_Blit(d->btn[BTN_MENU_KEYBOARD]);
}

void		menu_core(Menu* d)
{
  (void)d;
}
