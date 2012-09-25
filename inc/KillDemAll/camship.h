#ifndef		CAMSHIP_H
#define		CAMSHIP_H

#include	"SDLazy.h"
#include	"ship.h"
#include	"sdldata_typedef.h"

typedef			struct
{
  Ship			ship;
  Ship*			target;
}			CamShip;

void		camship_init(CamShip*);
void		camship_blit(CamShip*);
void		camship_core(CamShip*);

#endif
