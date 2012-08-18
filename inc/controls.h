#ifndef		CONTROLS_H
#define		CONTROLS_H

#include	"SDLazy.h"
#include	"data_typedef.h"

typedef		enum
{
  KEYB_EN,
  KEYB_FR
}		eKeyB;

enum
{
  UPWARD, RIGHTWARD, DOWNWARD, LEFTWARD,
  UPSHOOT, RIGHTSHOOT, DOWNSHOOT, LEFTSHOOT,
  NB_CTRLS
};

typedef		struct
{
  SDLKey	key[NB_CTRLS];
}		Controls;

void		ctrls_init(Controls*, eKeyB);

#endif
