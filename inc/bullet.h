#ifndef		BULLET_H
#define		BULLET_H

#include	"entity.h"

typedef		struct
{
  Entity*	entity;
  v2f		pos;
  v2f		dir;
}		Bullet;

void		bullet_create(Data*, Entity*, v2f* pos, v2f* dir);

#endif
