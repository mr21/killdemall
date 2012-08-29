#ifndef		SHIP_H
#define		SHIP_H

#include	"SDLazy.h"
#include	"data_typedef.h"

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
  v2f		pos;
  v2f		dir;
  char		dir_press[4];
  char		shoot_press[4];
  double	shoot_freq;
}		Ship;

enum
{
  SHIP_AXE_X = 1, SHIP_AXE_Y
};

Ship*		ship_push(CList* ships, Ship*);
void		ship_move(Data*, Ship*);
void		ship_recoil(Ship*, double recoil_x, int dir);

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
