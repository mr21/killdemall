#ifndef		PLAYER_H
#define		PLAYER_H

#include	"SDLazy/SDLazy.h"
#include	"entity.h"
#include	"sdldata.h"

typedef		struct
{
  Entity	entity;
  SDLazy_Anim*	anim_tirs[8];
}		Player;

void		player_init(SDLData*, Player*);

#endif
