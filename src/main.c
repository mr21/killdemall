#include	"data.h"
#include	"events.h"
#include	"core.h"
#include	"render.h"

int		main(void)
{
  Data		data;

  SDLazy_Init(1024, 768, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE, "KillDemAll");
  SDLazy_SetData(&data);

  data_init(&data);

  SDLazy_SetCursor(CURSOR_CROSS);

  SDLazy_AddEvent(SDL_KEYDOWN, evKeydown);
  SDLazy_AddEvent(SDL_KEYUP, evKeyup);
  SDLazy_AddEvent(SDL_MOUSEBUTTONDOWN, evMousedown);
  SDLazy_AddEvent(SDL_QUIT, evQuit);

  SDLazy_Loop(&data, core, render);

  return 0;
}

/*
  Quelques resolutions par defaut :
  1280, 1024
  1152, 864
  1024, 768
  832, 624
  800, 600
*/
