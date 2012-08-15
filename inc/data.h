#ifndef		SHMUPSDL2D_H
#define		SHMUPSDL2D_H

#include	"CList.h"
#include	"data_typedef.h"
#include	"sdldata.h"
#include	"player.h"

struct		Data
{
  SDLData	sdldata;
  Player	player;
  CList		ammos;
};

void		init(Data*);

#endif
