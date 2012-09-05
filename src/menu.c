#include	"menu.h"
#include	"controls.h"

void		menu_init(Menu* d)
{
  SDLazy_Button*        b;

  d->status = 0;

  d->srf[SRF_MENU_BG]       = SDLazy_SurfaceLoad("img/menu_bg.png",  NULL);
  d->srf[SRF_MENU_KEYBOARD] = SDLazy_SurfaceLoad("img/keyboard.png", SDLazy_Rect(0, 0, 128, 36));

  SDLazy_SetCenterAlign(d->srf[SRF_MENU_BG], ALIGN_TOP | ALIGN_LEFT);
  SDLazy_SetPosAlign(d->srf[SRF_MENU_BG], ALIGN_TOP | ALIGN_RIGHT);
  SDLazy_SetCenterX(d->srf[SRF_MENU_BG], 10);

  b = SDLazy_ButtonCreate(d->srf[SRF_MENU_KEYBOARD], 2);
  SDLazy_SetCenterAlign(b, ALIGN_TOP | ALIGN_LEFT);
  SDLazy_SetPosAlign(b, ALIGN_TOP | ALIGN_RIGHT);
  SDLazy_SetPosY(b, 20);
  SDLazy_ButtonSetFun(b, BUTTON_CLICUP, ctrls_switch);

  d->btn[BTN_MENU_KEYBOARD] = b;
}

void		menu_openclose(Menu* d)
{
  d->status = !d->status;
}

void		menu_blit(Menu* d)
{
  SDLazy_SetScaleY(d->srf[SRF_MENU_BG], SDLazy_GetHeight(0) / 2.0);
  SDLazy_Blit(d->srf[SRF_MENU_BG]);
  SDLazy_SetPosX(d->btn[BTN_MENU_KEYBOARD], SDLazy_GetPosX(d->srf[SRF_MENU_BG]) + 3);
  SDLazy_Blit(d->btn[BTN_MENU_KEYBOARD]);
}

void		menu_core(Menu* d)
{
  static int	w;
  double	x = SDLazy_GetPosX(d->srf[SRF_MENU_BG]);

  if (!w)
    w = SDLazy_GetWidth(d->srf[SRF_MENU_BG]) - SDLazy_GetCenterX(d->srf[SRF_MENU_BG]);
  x -= (d->status ? (w + x) : x) * SDLazy_GetFrameTime() * 6;
  SDLazy_SetPosX(d->srf[SRF_MENU_BG], x);
}
