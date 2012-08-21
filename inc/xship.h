#ifndef		XSHIP_H
#define		XSHIP_H

#include	"SDLazy.h"
#include	"ship.h"
#include	"sdldata_typedef.h"
#include	"data_typedef.h"

typedef			struct
{
  Ship			ship;
  SDLazy_Sprite*	bases_sprite[4];
  SDLazy_Anim*		turret_anim[8];
  SDLazy_Anim*		reactor_anim[4];
  char			turret_shoot[4];
  double		time_last_turret_shoot;
  v2f			base_pos[4];
}			XShip;

void		xship_init(SDLData*, XShip*);
void		xship_blit(SDLData*, XShip*);
void		xship_shoot(Data*, XShip*);
void		xship_move(Data*, XShip*, int dir, int press);
void		xship_move_bases(XShip*);

#endif
