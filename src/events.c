#include	"data.h"

/* Gestion temporaire du double clavier :D */

#define		KEY_FORWARD	'z'
#define		KEY_LEFTWARD	'q'
/*
#define		KEY_FORWARD	'w'
#define		KEY_LEFTWARD	'a'
*/

#define		KEY_BACKWARD	's'
#define		KEY_RIGHTWARD	'd'

#define		KEY_LEFTSHT	SDLK_LEFT
#define		KEY_RIGHTSHT	SDLK_RIGHT
#define		KEY_UPSHT	SDLK_UP
#define		KEY_DOWNSHT	SDLK_DOWN

void		evQuit(SDL_Event* e)
{
  (void)e;
  SDLazy_Quit(0);
}

void		evMousemove(SDL_Event* e)
{
  (void)e;
}

void		evKeydown(SDL_Event* e)
{
  Data*		d = SDLazy_GetData();

  switch (e->key.keysym.sym)
    {
    case KEY_FORWARD:	ship_forward   (d, d->player, 1);	break;
    case KEY_BACKWARD:	ship_backward  (d, d->player, 1);	break;
    case KEY_LEFTWARD:	ship_leftward  (d, d->player, 1);	break;
    case KEY_RIGHTWARD:	ship_rightward (d, d->player, 1);	break;

    case KEY_LEFTSHT:	ship_leftshoot (d, d->player, 1);	break;
    case KEY_RIGHTSHT:	ship_rightshoot(d, d->player, 1);	break;
    case KEY_UPSHT:	ship_upshoot   (d, d->player, 1);	break;
    case KEY_DOWNSHT:	ship_downshoot (d, d->player, 1);	break;

    case SDLK_ESCAPE:	SDLazy_Quit(0);
    default: break;
    }
}

void		evKeyup(SDL_Event* e)
{
  Data*		d = SDLazy_GetData();

  switch (e->key.keysym.sym)
    {
    case KEY_FORWARD:	ship_forward   (d, d->player, 0);	break;
    case KEY_BACKWARD:	ship_backward  (d, d->player, 0);	break;
    case KEY_LEFTWARD:	ship_leftward  (d, d->player, 0);	break;
    case KEY_RIGHTWARD:	ship_rightward (d, d->player, 0);	break;

    case KEY_LEFTSHT:	ship_leftshoot (d, d->player, 0);	break;
    case KEY_RIGHTSHT:	ship_rightshoot(d, d->player, 0);	break;
    case KEY_UPSHT:	ship_upshoot   (d, d->player, 0);	break;
    case KEY_DOWNSHT:	ship_downshoot (d, d->player, 0);	break;
    default: break;
    }
}
