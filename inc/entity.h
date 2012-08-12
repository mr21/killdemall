#ifndef		ENTITY_H
#define		ENTITY_H

#include	"SDLazy/SDLazy.h"
#include	"data_typedef.h"

typedef		enum
{
  ENT_PLAYER,
  ENT_ENEMY
}		eEntityType;

typedef		struct
{
  eEntityType	type;
  double	mxspd;
  double	accel;
  v2f		pos;
  v2f		dir;
  char		dir_press[4];
  char		shoot_press[4];
}		Entity;

void            entity_leftward(Data*, Entity*, char press);
void            entity_rightward(Data*, Entity*, char press);
void            entity_forward(Data*, Entity*, char press);
void            entity_backward(Data*, Entity*, char press);

void            entity_leftshoot(Data*, Entity*, char press);
void            entity_rightshoot(Data*, Entity*, char press);
void            entity_upshoot(Data*, Entity*, char press);
void            entity_downshoot(Data*, Entity*, char press);

#endif
