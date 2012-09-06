#include	"controls.h"
#include	"data.h"

static void	kbfr(Controls* c)
{
  c->kb = KEYB_FR;
  c->key[c->move_wasd ? UPWARD   : UPSHOOT]   = 'z';
  c->key[c->move_wasd ? LEFTWARD : LEFTSHOOT] = 'q';
}

static void	kben(Controls* c)
{
  c->kb = KEYB_EN;
  c->key[c->move_wasd ? UPWARD   : UPSHOOT]   = 'w';
  c->key[c->move_wasd ? LEFTWARD : LEFTSHOOT] = 'a';
}

static void	_set_cmds(Controls* c)
{
  SDLKey*	t = c->key;

  if (c->move_wasd)
    {
      t[UPSHOOT]	= SDLK_UP;
      t[RIGHTSHOOT]	= SDLK_RIGHT;
      t[DOWNSHOOT]	= SDLK_DOWN;
      t[LEFTSHOOT]	= SDLK_LEFT;
      t[RIGHTWARD]	= 'd';
      t[DOWNWARD]	= 's';
    }
  else
    {
      t[RIGHTSHOOT]	= 'd';
      t[DOWNSHOOT]	= 's';
      t[UPWARD]		= SDLK_UP;
      t[RIGHTWARD]	= SDLK_RIGHT;
      t[DOWNWARD]	= SDLK_DOWN;
      t[LEFTWARD]	= SDLK_LEFT;
    }
  (c->kb == KEYB_EN ? kben : kbfr)(c);
}

void		ctrls_init(Controls* c)
{
  c->kb = KEYB_EN;
  c->move_wasd = 1;
  _set_cmds(c);
}

void		ctrls_qwerty_azerty(void)
{
  Controls*	c = &((Data*)SDLazy_GetData())->ctrls;

  (c->kb == KEYB_EN ? kbfr : kben)(c);
}

void		ctrls_switch_cmds(void)
{
  Controls*	c = &((Data*)SDLazy_GetData())->ctrls;

  c->move_wasd = !c->move_wasd;
  _set_cmds(c);
}
