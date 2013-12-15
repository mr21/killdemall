#include	"menu.h"
#include	"sound.h"
#include	"data.h"

static void	_snd(int status)
{
  sound_play(SND_MENU_OPEN, .9, .8, status ? 25000 : 22050);
}

void		menu_open(Menu* d)
{
  _snd(d->status = 1);
  SDLazy_ButtonSetState(d->btn[BTN_MENU_OPEN], 1);
}

void		menu_close(Menu* d)
{
  _snd(d->status = 0);
  SDLazy_ButtonSetState(d->btn[BTN_MENU_OPEN], 0);
}

void		menu_toggle(void)
{
  Menu*         d = &((Data*)SDLazy_GetData())->menu;

  _snd(d->status = !d->status);
}
