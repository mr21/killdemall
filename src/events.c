#include	"data.h"
#include	"controls.h"

void		evQuit(SDL_Event* e)
{
  (void)e;
  SDLazy_Quit(0);
}

void		evMousedown(SDL_Event* e)
{
  if (e->button.button == SDL_BUTTON_LEFT)
    xship_cannon_fire((XShip*)((Data*)SDLazy_GetData())->player);
}

static void	ship(Data* d, SDLKey k, char press)
{
  SDLKey*	c = d->ctrls.key;

  if      (k == c[UPWARD])	ship_forward    (d, d->player, press);
  else if (k == c[DOWNWARD])	ship_backward   (d, d->player, press);
  else if (k == c[LEFTWARD])	ship_leftward   (d, d->player, press);
  else if (k == c[RIGHTWARD])	ship_rightward  (d, d->player, press);
  else if (k == c[UPSHOOT])	ship_upshoot    (d, d->player, press);
  else if (k == c[RIGHTSHOOT])	ship_rightshoot (d, d->player, press);
  else if (k == c[DOWNSHOOT])	ship_downshoot  (d, d->player, press);
  else if (k == c[LEFTSHOOT])	ship_leftshoot  (d, d->player, press);
}

void		evKeydown(SDL_Event* e)
{
  Data*		d = SDLazy_GetData();

  switch (e->key.keysym.sym)
    {
    case SDLK_ESCAPE:	SDLazy_Quit(0);
    case SDLK_TAB:	menu_openclose(&d->menu, 1);
    default:		ship(d, e->key.keysym.sym, 1);
    }
}

void		evKeyup(SDL_Event* e)
{
  Data*		d = SDLazy_GetData();

  switch (e->key.keysym.sym)
    {
    case SDLK_TAB:	menu_openclose(&d->menu, 0);
    default:		ship(d, e->key.keysym.sym, 0);
    }
}
