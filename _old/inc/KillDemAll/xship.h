#ifndef		XSHIP_H
#define		XSHIP_H

#include	"SDLazy.h"
#include	"ship.h"
#include	"sdldata_typedef.h"

typedef			struct
{
  Ship			ship;
  SDLazy_Sprite*	bases_sprite[4];
  SDLazy_Anim*		turret_anim[8];
  SDLazy_Anim*		reactor_anim[4];
  SDLazy_Anim*		cannon_anim;
  eShipDir		shoot_dir;
  eShipDir		move_dir;
  char			turret_shoot[4];
  double		time_last_turret_shoot;
  v2f			base_pos[4];
}			XShip;

void		xship_init(XShip*);
void		xship_blit(XShip*);

/* Core */
void		xship_core(XShip*);
void		xship_core_move_bases(XShip*);
void		xship_core_shoot(XShip*);
void		xship_core_rot_cannon(XShip*);
void		xship_core_dir(XShip*);

/* Events */
void		xship_event_cannon_fire(XShip*);
void		xship_event_wasd(XShip*, eShipDir, char press);
void		xship_event_arrows(XShip*, eShipDir, char press);

#endif
