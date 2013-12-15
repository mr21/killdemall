#include	"menu.h"
#include	"data.h"

void		menu_init(Menu* d)
{
  SDLazy_Button*        b;

  d->status = 0;

  d->srf[SRF_MENU_BG]         = SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect(370, 150, 150,  8));
  d->srf[SRF_MENU_FULLSCREEN] = SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect(370, 185,  30, 27));
  d->srf[SRF_MENU_KEYBOARD]   = SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect( 20, 150, 128, 36));
  d->srf[SRF_MENU_COMMANDS]   = SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect( 20, 280, 128, 36));
  d->srf[SRF_MENU_OPEN]       = SDLazy_SurfaceLoad("img/sprites.png", SDLazy_Rect(290, 150,  32, 32));

  SDLazy_SetCenterAlign(d->srf[SRF_MENU_BG], ALIGN_TOP | ALIGN_LEFT);
  SDLazy_SetPosAlign(d->srf[SRF_MENU_BG], ALIGN_TOP | ALIGN_RIGHT);
  SDLazy_SetCenterX(d->srf[SRF_MENU_BG], 15);

  b = SDLazy_ButtonCreate(d->srf[SRF_MENU_FULLSCREEN], 2);
  d->btn[BTN_MENU_FULLSCREEN] = b;
  SDLazy_SetPosAlign(b, ALIGN_TOP | ALIGN_RIGHT);
  SDLazy_SetPosY(b, 5);
  SDLazy_SetCenterAlign(b, ALIGN_TOP | ALIGN_LEFT);
  SDLazy_ButtonSetFun(b, BUTTON_CLICUP, SDLazy_Fullscreen);

  b = SDLazy_ButtonCreate(d->srf[SRF_MENU_KEYBOARD], 2);
  d->btn[BTN_MENU_KEYBOARD] = b;
  SDLazy_SetCenterAlign(b, ALIGN_TOP | ALIGN_LEFT);
  SDLazy_SetPosAlign(b, ALIGN_TOP | ALIGN_RIGHT);
  SDLazy_SetPosY(b, 50);
  SDLazy_ButtonSetFun(b, BUTTON_CLICUP, ctrls_qwerty_azerty);

  b = SDLazy_ButtonCreate(d->srf[SRF_MENU_COMMANDS], 2);
  d->btn[BTN_MENU_COMMANDS] = b;
  SDLazy_SetCenterAlign(b, ALIGN_TOP | ALIGN_LEFT);
  SDLazy_SetPosAlign(b, ALIGN_TOP | ALIGN_RIGHT);
  SDLazy_SetPosY(b, 100);
  SDLazy_ButtonSetFun(b, BUTTON_CLICUP, ctrls_switch_cmds);

  b = SDLazy_ButtonCreate(d->srf[SRF_MENU_OPEN], 2);
  d->btn[BTN_MENU_OPEN] = b;
  SDLazy_SetPosAlign(b, ALIGN_TOP | ALIGN_RIGHT);
  SDLazy_SetCenterAlign(b, ALIGN_CENTER | ALIGN_CENTER);
  SDLazy_ButtonSetFun(b, BUTTON_CLICUP, menu_toggle);
}
