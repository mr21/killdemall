#ifndef		SOUND_H
#define		SOUND_H

#include	"fmod.h"
#include	"fmod_errors.h"

typedef		enum
{
  SND_XHSIP_SHOOT,
  NB_SND
}		eSound;

typedef		struct
{
  FMOD_SYSTEM*	system;
  FMOD_SOUND*	mp3[NB_SND];
  FMOD_CHANNEL*	chan;
}		Sound;

int		sound_init(Sound*);
void		sound_play(eSound, float vol, float pan, float freq);

#endif
