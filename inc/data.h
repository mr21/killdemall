#ifndef		SHMUPSDL2D_H
#define		SHMUPSDL2D_H

#include	"data_typedef.h"
#include	"sdldata.h"
#include	"player.h"

struct		Data
{
  SDLData	sdldata;
  Player	player;
};

void		init(Data*);
void		render(void);

#endif
