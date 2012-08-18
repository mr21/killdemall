#include	"data.h"
#include	"controls.h"

void		evQuit(SDL_Event* e)
{
  (void)e;
  SDLazy_Quit(0);
}

void		evMousemove(SDL_Event* e)
{
  (void)e;
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
  switch (e->key.keysym.sym)
    {
    case SDLK_ESCAPE:	SDLazy_Quit(0);
    default:		ship(SDLazy_GetData(), e->key.keysym.sym, 1);
    }
}

void		evKeyup(SDL_Event* e)
{
  ship(SDLazy_GetData(), e->key.keysym.sym, 0);
}
