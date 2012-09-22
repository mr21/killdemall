#ifndef		EVENTS_H
#define		EVENTS_H

#include	<SDL/SDL.h>

void		evKeydown(SDL_Event*);
void		evKeyup(SDL_Event*);
void		evMousemove(SDL_Event*);
void		evMousedown(SDL_Event*);
void		evQuit(SDL_Event*);

#endif
