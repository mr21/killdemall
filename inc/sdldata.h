#ifndef		SDLDATA_H
#define		SDLDATA_H

#include	"SDLazy.h"
#include	"sdldata_typedef.h"
#include	"ammo.h"

enum
{
  SRF_BG,
  SRF_P_NO, SRF_P_NE, SRF_P_SO, SRF_P_SE,
  SRF_AN_TIR,
  NB_SRFS
};

struct			SDLData
{
  SDLazy_Surface*	srf[NB_SRFS];
  SDLazy_Surface*	srf_bullets[NB_AMMOS];
  v2f			cam;
};

#endif
