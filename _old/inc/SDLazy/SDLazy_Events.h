#ifndef			SDLAZY_EVENTS
# define		SDLAZY_EVENTS

# include		<SDL/SDL.h>

typedef			struct
{
  int			nb_f;
  int			sz_f;
  void			(**f)(SDL_Event*);
}			SDLazy_Event;

void			SDLazy_AddEvent(Uint8 type, void (*f)(SDL_Event*));
void			SDLazy_DelEvent(Uint8 type, void (*f)(SDL_Event*));

void			SDLazy_EventsUpdate(void);

/* Events par defaut */
void			SDLazy_ResizeEvent(SDL_Event*);
void			SDLazy_MouseMoveEvent(SDL_Event*);
void			SDLazy_ClicDownEvent(SDL_Event*);
void			SDLazy_ClicUpEvent(SDL_Event*);

#endif
