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
void		xship_core_cannon_fire(XShip*);
void		xship_core_dir(XShip*);

/* Move */
void		xship_leftward (XShip*, char press);
void		xship_rightward(XShip*, char press);
void		xship_forward  (XShip*, char press);
void		xship_backward (XShip*, char press);

/* Shoot */
void		xship_leftshoot (XShip*, char press);
void		xship_rightshoot(XShip*, char press);
void		xship_upshoot   (XShip*, char press);
void		xship_downshoot (XShip*, char press);

#endif
