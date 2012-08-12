#ifndef		PLAYER_H
#define		PLAYER_H

#include	"SDLazy/SDLazy.h"
#include	"entity.h"
#include	"sdldata.h"

typedef		struct
{
  Entity	entity;
  SDLazy_Anim*	turret_anim[8];
  char		turret_shoot[4];
  double	time_last_turret_shoot;
}		Player;

void		player_init(SDLData*, Player*);

#endif
