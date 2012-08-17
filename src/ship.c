#include	"ship.h"

static void	restore_shoot_freq(Ship* s)
{
  s->shoot_freq = .05;
}

void		ship_leftward(Data* d, Ship* s, char press)
{
  (void)d;
  s->dir_press[0] = press;
}

void		ship_rightward(Data* d, Ship* s, char press)
{
  (void)d;
  s->dir_press[2] = press;
}

void		ship_forward(Data* d, Ship* s, char press)
{
  (void)d;
  s->dir_press[1] = press;
}

void		ship_backward(Data* d, Ship* s, char press)
{
  (void)d;
  s->dir_press[3] = press;
}

void            ship_upshoot(Data* d, Ship* s, char press)
{
  (void)d;
  s->shoot_press[0] = press;
  restore_shoot_freq(s);
}

void            ship_rightshoot(Data* d, Ship* s, char press)
{
  (void)d;
  s->shoot_press[1] = press;
  restore_shoot_freq(s);
}

void            ship_downshoot(Data* d, Ship* s, char press)
{
  (void)d;
  s->shoot_press[2] = press;
  restore_shoot_freq(s);
}

void            ship_leftshoot(Data* d, Ship* s, char press)
{
  (void)d;
  s->shoot_press[3] = press;
  restore_shoot_freq(s);
}
