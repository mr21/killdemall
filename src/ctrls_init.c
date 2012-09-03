#include	"controls.h"
#include	"data.h"

static void	kbfr(Controls* c)
{
  c->kb = KEYB_FR;
  c->key[UPWARD]	= 'z';
  c->key[LEFTWARD]	= 'q';
}

static void	kben(Controls* c)
{
  c->kb = KEYB_EN;
  c->key[UPWARD]	= 'w';
  c->key[LEFTWARD]	= 'a';
}

void		ctrls_init(Controls* c, eKeyB kb)
{
  c->key[UPSHOOT]	= SDLK_UP;
  c->key[RIGHTSHOOT]	= SDLK_RIGHT;
  c->key[DOWNSHOOT]	= SDLK_DOWN;
  c->key[LEFTSHOOT]	= SDLK_LEFT;
  c->key[RIGHTWARD]	= 'd';
  c->key[DOWNWARD]	= 's';
  (kb == KEYB_FR ? kbfr : kben)(c);
}

void		ctrls_switch(void)
{
  Data*		d = SDLazy_GetData();

  (d->ctrls.kb == KEYB_EN ? kbfr : kben)(&d->ctrls);
}
