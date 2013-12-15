#include	"data.h"
#include	"ship.h"
#include	"controls.h"

void		evQuit(SDL_Event* e)
{
  (void)e;
  SDLazy_Quit(0);
}

void		evMousedown(SDL_Event* e)
{
  Data*		d = SDLazy_GetData();

  if (e->button.button == SDL_BUTTON_LEFT && !menu_mouseover(&d->menu))
    d->player->left_clic((void*)d->player);
}

static void	ship(Data* d, SDLKey k, char press)
{
  SDLKey*	c = d->ctrls.key;

  if      (k == c[UPWARD])     d->player->wasd  ((void*)d->player, DIR_UP,    press);
  else if (k == c[RIGHTWARD])  d->player->wasd  ((void*)d->player, DIR_RIGHT, press);
  else if (k == c[DOWNWARD])   d->player->wasd  ((void*)d->player, DIR_DOWN,  press);
  else if (k == c[LEFTWARD])   d->player->wasd  ((void*)d->player, DIR_LEFT,  press);
  else if (k == c[UPSHOOT])    d->player->arrows((void*)d->player, DIR_UP,    press);
  else if (k == c[RIGHTSHOOT]) d->player->arrows((void*)d->player, DIR_RIGHT, press);
  else if (k == c[DOWNSHOOT])  d->player->arrows((void*)d->player, DIR_DOWN,  press);
  else if (k == c[LEFTSHOOT])  d->player->arrows((void*)d->player, DIR_LEFT,  press);
}

void		evKeydown(SDL_Event* e)
{
  Data*		d = SDLazy_GetData();

  switch (e->key.keysym.sym)
    {
    case SDLK_ESCAPE:	SDLazy_Quit(0);
    case SDLK_TAB:	menu_open(&d->menu);
    default:		ship(d, e->key.keysym.sym, 1);
    }
}

void		evKeyup(SDL_Event* e)
{
  Data*		d = SDLazy_GetData();

  switch (e->key.keysym.sym)
    {
    case SDLK_TAB:	menu_close(&d->menu);
    default:		ship(d, e->key.keysym.sym, 0);
    }
}
