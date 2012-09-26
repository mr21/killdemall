#ifndef		SHIP_H
#define		SHIP_H

#include	"SDLazy.h"
#include	"data_typedef.h"

typedef		enum
{
  DIR_UP    = 1,
  DIR_RIGHT = 2,
  DIR_DOWN  = 4,
  DIR_LEFT  = 8
}		eShipDir;

typedef		enum
{
  XSHIP,
  KAMSHIP
}		eShipType;

typedef		struct
{
  eShipType	type;
  double	mxspd;
  double	accel;
  double	weight;
  double	shtfq_max;
  double	shtfq_lost;
  double	shtfq_curr;
  v2f		pos;
  v2f		dir;
  char		dir_press[4];
  eShipDir	shoot_dir;
}		Ship;

enum
{
  SHIP_AXE_X = 1, SHIP_AXE_Y
};

Ship*		ship_push(CList* ships, Ship*);
void		ship_move(Data*, Ship*);
void		ship_recoil(Ship*, double recoil_x, int dir);

void		ship_init(Ship*, eShipType);

/* ShipS */
void		ships_blit(CList* ships);

/* Setters */
void            ship_setaccel  (Ship*, double);
void            ship_setweight (Ship*, double);
void            ship_setspd_max(Ship*, double);
void            ship_setpos    (Ship*, v2f*);
void            ship_setfq_max (Ship*, double);
void            ship_setfq_lost(Ship*, double);
void            ship_resetfq   (Ship*);

/* Move */
void            ship_leftward (Data*, Ship*, char press);
void            ship_rightward(Data*, Ship*, char press);
void            ship_forward  (Data*, Ship*, char press);
void            ship_backward (Data*, Ship*, char press);

/* Shoot */
void            ship_leftshoot (Data*, Ship*, char press);
void            ship_rightshoot(Data*, Ship*, char press);
void            ship_upshoot   (Data*, Ship*, char press);
void            ship_downshoot (Data*, Ship*, char press);

#endif
