#ifndef		SDLDATA_H
#define		SDLDATA_H

#include	"SDLazy/SDLazy.h"

enum
{
  SRF_BG,
  SRF_P_NO, SRF_P_NE, SRF_P_SO, SRF_P_SE,
  SRF_AN_TIR,
  NB_SRFS
};

typedef			struct
{
  SDLazy_Surface*	srf[NB_SRFS];
  v2f			cam;
}			SDLData;

#endif
