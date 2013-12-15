#ifndef		SDLDATA_H
#define		SDLDATA_H

#include	"SDLazy.h"
#include	"sdldata_typedef.h"
#include	"ammo.h"

enum
{
  BG0,
  NB_BGS
};

enum
{
  SRF_XSHIP_NO, SRF_XSHIP_NE, SRF_XSHIP_SO, SRF_XSHIP_SE,
  SRF_XSHIP_TURRET, SRF_XSHIP_REACTOR, SRF_XSHIP_CANNON,
  SRF_XSHIP_BASE, SRF_XSHIP_TOP,
  NB_SRF_XSHIP
};

enum
{
  SRF_KAMSHIP_BODY,
  NB_SRF_KAMSHIP
};

struct			SDLData
{
  SDLazy_Surface*	srf_bg[NB_BGS];
  SDLazy_Surface*	srf_xship[NB_SRF_XSHIP];
  SDLazy_Surface*	srf_kamship[NB_SRF_KAMSHIP];
  SDLazy_Surface*	srf_ammo[NB_AMMOS];
  v2f			cam;
};

void			sdldata_init(SDLData*);

#endif
