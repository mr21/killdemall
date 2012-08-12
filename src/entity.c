#include	"entity.h"

void		entity_leftward(Data* d, Entity* e, char press)
{
  (void)d;
  e->dir_press[0] = press;
}

void		entity_rightward(Data* d, Entity* e, char press)
{
  (void)d;
  e->dir_press[2] = press;
}

void		entity_forward(Data* d, Entity* e, char press)
{
  (void)d;
  e->dir_press[1] = press;
}

void		entity_backward(Data* d, Entity* e, char press)
{
  (void)d;
  e->dir_press[3] = press;
}

void            entity_upshoot(Data* d, Entity* e, char press)
{
  (void)d;
  e->shoot_press[0] = press;
}

void            entity_rightshoot(Data* d, Entity* e, char press)
{
  (void)d;
  e->shoot_press[1] = press;
}

void            entity_downshoot(Data* d, Entity* e, char press)
{
  (void)d;
  e->shoot_press[2] = press;
}

void            entity_leftshoot(Data* d, Entity* e, char press)
{
  (void)d;
  e->shoot_press[3] = press;
}
