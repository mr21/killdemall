#ifndef			SDLAZY_ANIMS_H
# define		SDLAZY_ANIMS_H

# include		"CList.h"
# include		"SDLazy_Surfaces.h"
# include		"SDLazy_ObjHeader.h"

# define		TIMER_DEFAULT		50

typedef			enum
  {
    ANIM_PLAYING,
    ANIM_PAUSE,
    ANIM_STOP
  }			eAnimStatus;

typedef			struct
{
  SDLazy_ObjHeader	header;
  SDLazy_TinySprite*	tinySp_tab;
  eAnimStatus		pause_or_stop;
  eAnimStatus		status;
  Uint16		nb_frames;
  Uint16		frame_curr;
  Uint16		frame_loop;
  Uint16		ms_interval;
  Uint32		ms_curr;
}			SDLazy_Anim;

typedef			struct
{
  Uint16		timer_default;
  CList			list;
}			SDLazy_Anims;

/* AnimS */
void			SDLazy_InitAnims(SDLazy_Anims*);
void			SDLazy_FreeAnims(SDLazy_Anims*);
void			SDLazy_AnimsUpdate(SDLazy_Anims*);

SDLazy_Anim*		SDLazy_AnimCreate(SDLazy_Surface*, Uint16 nb_frames, Uint16 frame_loop, eAnimStatus status);
void			SDLazy_AnimDestroy(SDLazy_Anim*);

/* Controles */
/*   Sur toutes les animations du programme */
void			SDLazy_AnimsPlay(void);
void			SDLazy_AnimsPause(void);
void			SDLazy_AnimsStop(void);
void			SDLazy_AnimsTimer(Uint16 ms);
/*   Sur une animation en particuliere */
void			SDLazy_AnimReplay(SDLazy_Anim*);
int			SDLazy_AnimPlay(SDLazy_Anim*);
int			SDLazy_AnimPause(SDLazy_Anim*);
int			SDLazy_AnimStop(SDLazy_Anim*);

/* Getters / Setters */
eAnimStatus		SDLazy_AnimStatus(SDLazy_Anim*);
Uint16			SDLazy_AnimNbFrames(SDLazy_Anim*);
void			SDLazy_AnimTimer(SDLazy_Anim*, Uint16 ms);
void			SDLazy_AnimFrameLoop(SDLazy_Anim*, Uint16 frame);

#endif
