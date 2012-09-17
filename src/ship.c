#include	"ship.h"
#include	"xship.h"

/*
Ce code est encore temporaire.. l'heritage n'est pas très logique ici :S
*/

static void	restore_shoot_freq(Ship* s)
{
  s->shtfq_curr = s->shtfq_max;
}

void		ship_forward(Data* d, Ship* s, char press)
{
  (void)d;
  s->dir_press[1] = press;
  xship_move(d, (XShip*)s, 2, press);
}

void		ship_rightward(Data* d, Ship* s, char press)
{
  (void)d;
  s->dir_press[2] = press;
  xship_move(d, (XShip*)s, 3, press);
}

void		ship_leftward(Data* d, Ship* s, char press)
{
  (void)d;
  s->dir_press[0] = press;
  xship_move(d, (XShip*)s, 1, press);
}

void		ship_backward(Data* d, Ship* s, char press)
{
  (void)d;
  s->dir_press[3] = press;
  xship_move(d, (XShip*)s, 0, press);
}

void            ship_upshoot(Data* d, Ship* s, char press)
{
  (void)d;
  s->shoot_dir = press ? s->shoot_dir | DIR_UP : s->shoot_dir ^ DIR_UP;
  restore_shoot_freq(s);
}

void            ship_rightshoot(Data* d, Ship* s, char press)
{
  (void)d;
  s->shoot_dir = press ? s->shoot_dir | DIR_RIGHT : s->shoot_dir ^ DIR_RIGHT;
  restore_shoot_freq(s);
}

void            ship_downshoot(Data* d, Ship* s, char press)
{
  (void)d;
  s->shoot_dir = press ? s->shoot_dir | DIR_DOWN : s->shoot_dir ^ DIR_DOWN;
  restore_shoot_freq(s);
}

void            ship_leftshoot(Data* d, Ship* s, char press)
{
  (void)d;
  s->shoot_dir = press ? s->shoot_dir | DIR_LEFT : s->shoot_dir ^ DIR_LEFT;
  restore_shoot_freq(s);
}
