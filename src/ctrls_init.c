#include	"controls.h"
#include	"data.h"

static void	kbfr(Controls* c)
{
  c->key[UPWARD]	= 'z';
  c->key[RIGHTWARD]	= 'd';
  c->key[DOWNWARD]	= 's';
  c->key[LEFTWARD]	= 'q';
}

static void	kben(Controls* c)
{
  c->key[UPWARD]	= 'w';
  c->key[RIGHTWARD]	= 'd';
  c->key[DOWNWARD]	= 's';
  c->key[LEFTWARD]	= 'a';
}

void		ctrls_init(Controls* c, eKeyB kb)
{
  c->key[UPSHOOT]	= SDLK_UP;
  c->key[RIGHTSHOOT]	= SDLK_RIGHT;
  c->key[DOWNSHOOT]	= SDLK_DOWN;
  c->key[LEFTSHOOT]	= SDLK_LEFT;
  (kb == KEYB_FR ? kbfr : kben)(c);
}
