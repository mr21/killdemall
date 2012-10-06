#ifndef		KAMSHIP_H
#define		KAMSHIP_H

#include	"SDLazy.h"
#include	"ship.h"
#include	"sdldata_typedef.h"

typedef			struct
{
  Ship			ship;
  SDLazy_Sprite*	spr_body;
  Ship*			target;
}			KamShip;

void		kamship_init(KamShip*);
void		kamship_blit(KamShip*);
void		kamship_core(KamShip*);

/* Events */
void		kamship_event_leftclic(KamShip*);

#endif
