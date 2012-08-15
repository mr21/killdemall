#ifndef		SHMUPSDL2D_H
#define		SHMUPSDL2D_H

#include	"CList.h"
#include	"data_typedef.h"
#include	"sdldata.h"
#include	"xship.h"

struct		Data
{
  SDLData	sdldata;
  CList		ships;
  XShip		player;
  CList		ammos;
};

void		data_init(Data*);

#endif
