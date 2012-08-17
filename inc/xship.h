#ifndef		XSHIP_H
#define		XSHIP_H

#include	"SDLazy.h"
#include	"ship.h"
#include	"sdldata_typedef.h"
#include	"data_typedef.h"

typedef		struct
{
  Ship		ship;
  SDLazy_Anim*	turret_anim[8];
  char		turret_shoot[4];
  double	time_last_turret_shoot;
}		XShip;

void		xship_init(SDLData*, XShip*);
void		xship_shoot(Data*, XShip*);

#endif
