#ifndef		CONTROLS_H
#define		CONTROLS_H

#include	"SDLazy.h"
#include	"data_typedef.h"

typedef		enum
{
  KEYB_FR,
  KEYB_EN
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
  eKeyB		kb;
  char		move_wasd;
}		Controls;

void		ctrls_init(Controls*);
void		ctrls_qwerty_azerty(void);
void		ctrls_switch_cmds(void);

#endif
