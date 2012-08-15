#ifndef		AMMO_H
#define		AMMO_H

#include	"SDLazy.h"
#include	"data.h"
#include	"sdldata.h"
#include	"entity.h"

typedef		enum
{
  AMMO_BULLET,
  NB_AMMOS
}		eAmmoType;

typedef		struct
{
  eAmmoType	type;
  void*		from_who;
  v2f		pos;
  v2f		dir;
  double	rad;
}		Ammo;

Ammo*		ammo_push(Data*, Ammo*);
void		ammos_blit(SDLData*, CList* ammos);

#endif
