#ifndef		CORE_H
#define		CORE_H

#include	"data_typedef.h"
#include	"sdldata_typedef.h"
#include	"ship.h"

void		core(void);
void		core_ship_move(Data*, Ship*);
void		camera_focus(SDLData*, v2f*);

#endif
