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
  v2f		pos;
  v2f		dir;
  char		dir_press[4];
  char		shoot_press[4];
  double	shoot_freq;
}		Ship;

Ship*		ship_push(CList* ships, Ship*);
void		ship_move(Data*, Ship*);

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
