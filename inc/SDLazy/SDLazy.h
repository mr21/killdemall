#ifndef				SDLAZY_H
# define			SDLAZY_H

# include			<SDL/SDL.h>
# include			<SDL/SDL_image.h>

# include			"SDLazy_Cursors.h"
# include			"SDLazy_Events.h"
# include			"SDLazy_Surfaces.h"
# include			"SDLazy_Sprites.h"
# include			"SDLazy_Buttons.h"
# include			"SDLazy_Anims.h"
# include			"SDLazy_Layers.h"
# include			"SDLazy_Circle.h"
# include			"SDLazy_Align.h"
# include			"myMath.h"

typedef				struct
{
  void*				data;
  const char*			title;
  char*				titleFPS;
  Uint32			flags;
  Uint16			fpsDelay;
  Uint16			delay;
  double			frameTime;
  double			totalTime;
  v2i				mouse;
  SDL_Surface*			scr;
  SDLazy_Layers			layers;
  SDLazy_Cursors		cursors;
  SDLazy_Surfaces		surfaces;
  SDLazy_Sprites		sprites;
  SDLazy_Buttons		buttons;
  SDLazy_Anims			anims;
  SDLazy_Event			e[SDL_USEREVENT];
}				SDLazy;

extern SDLazy			g_sdlazy;

void				SDLazy_Init(Sint32 w, Sint32 h, Uint32 flags, const char* title);
void				SDLazy_Loop(void* data, void (*core)(void), void (*render)(void));
void				SDLazy_Quit(char* msg);
SDL_Rect*			SDLazy_Rect(Sint32 x, Sint32 y, Uint32 w, Uint32 h);
void				SDLazy_Fullscreen(void);

/* Getters / Setters */
void*				SDLazy_GetData(void);
double				SDLazy_GetFrameTime(void);
double				SDLazy_GetTotalTime(void);
void				SDLazy_SetFPS(Uint16 delay);
void				SDLazy_SetFPSMax(Uint16 max);

/* Mouse */
v2i*				SDLazy_GetMouse(void);
int				SDLazy_GetMouseX(void);
int				SDLazy_GetMouseY(void);

SDL_Surface*			SDLazy_GetScreen(void);

/* Blit */
void				SDLazy_Blit(void* obj);
void				SDLazy_BlitOnParent(void* obj);
void				SDLazy_BlitOnScreen(void* obj);

/*
** Acces aux pixels d'une surface
** Les fonctions _Secure s'assurent que x et y soient bien des coordonnees valides
*/
SDL_Surface*			SDLazy_RotScale(SDL_Surface* src, SDL_Rect* src_r, double rad, v2f* scale);
void				SDLazy_SetPix(SDL_Surface*, Sint32 x, Sint32 y, Uint32 px);
Uint32				SDLazy_GetPix(SDL_Surface*, Sint32 x, Sint32 y);
void				SDLazy_SetPix_Secure(SDL_Surface*, Sint32 x, Sint32 y, Uint32 px);
Uint32				SDLazy_GetPix_Secure(SDL_Surface*, Sint32 x, Sint32 y);

#endif
