#include	"ship.h"

void		ship_leftward(Data* d, Ship* e, char press)
{
  (void)d;
  e->dir_press[0] = press;
}

void		ship_rightward(Data* d, Ship* e, char press)
{
  (void)d;
  e->dir_press[2] = press;
}

void		ship_forward(Data* d, Ship* e, char press)
{
  (void)d;
  e->dir_press[1] = press;
}

void		ship_backward(Data* d, Ship* e, char press)
{
  (void)d;
  e->dir_press[3] = press;
}

void            ship_upshoot(Data* d, Ship* e, char press)
{
  (void)d;
  e->shoot_press[0] = press;
}

void            ship_rightshoot(Data* d, Ship* e, char press)
{
  (void)d;
  e->shoot_press[1] = press;
}

void            ship_downshoot(Data* d, Ship* e, char press)
{
  (void)d;
  e->shoot_press[2] = press;
}

void            ship_leftshoot(Data* d, Ship* e, char press)
{
  (void)d;
  e->shoot_press[3] = press;
}
