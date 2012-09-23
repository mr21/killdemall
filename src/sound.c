#include	<stdio.h>
#include	"SDLazy.h"
#include	"sound.h"
#include	"data.h"

int		sound_init(Sound* s)
{
  FMOD_RESULT	res;
  unsigned	u;
  char const*	snd[] =
    {
      "sound/menu_open.wav",
      "sound/xship_shoot.wav",
      "sound/xship_cannon.wav"
    };

  if (FMOD_OK != (res = FMOD_System_Create(&s->system)) ||
      FMOD_OK != (res = FMOD_System_Init(s->system, 32, FMOD_INIT_NORMAL, NULL)))
    return printf("FMOD error! (%d) %s\n", res, FMOD_ErrorString(res));
  for (u = 0; u < sizeof snd / 8; ++u)
    if (FMOD_OK != (res = FMOD_System_CreateSound(s->system, snd[u], FMOD_SOFTWARE, 0, &s->mp3[u])))
      return printf("FMOD error! (%d) %s\n", res, FMOD_ErrorString(res));
  return 0;
}

void		sound_play(eSound snd, float vol, float pan, float freq)
{
  static Sound*	s;

  if (!s)
    s = &((Data*)SDLazy_GetData())->sound;

  FMOD_System_PlaySound(s->system, FMOD_CHANNEL_FREE, s->mp3[snd], 0, &s->chan);
  FMOD_Channel_SetVolume(s->chan, vol);
  FMOD_Channel_SetPan(s->chan, pan);
  FMOD_Channel_SetFrequency(s->chan, freq);

  FMOD_System_Update(s->system);
}
