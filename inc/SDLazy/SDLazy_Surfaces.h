#ifndef			SDLAZY_SURFACES_H
# define		SDLAZY_SURFACES_H

# include		<SDL/SDL.h>
# include		"CList/CList.h"
# include		"SDLazy_ObjHeader.h"
# include		"SDLazy_TinySprite.h"
# include		"myMath.h"

typedef			struct
{
  SDLazy_ObjHeader	header;
  SDLazy_TinySprite	tinySp;
  char const*		path;
  Uint8			to_free;
}			SDLazy_Surface;

typedef			struct
{
  CList			list;
}			SDLazy_Surfaces;

void			SDLazy_InitSurfaces(SDLazy_Surfaces*);
void			SDLazy_FreeSurfaces(SDLazy_Surfaces*);

SDLazy_Surface*		SDLazy_SurfaceLoad(char const* path, SDL_Rect* src_r);
SDLazy_Surface*		SDLazy_SurfacePack(SDL_Surface* ptr, SDL_Rect* src_r);
void			SDLazy_FreeSurface(SDLazy_Surface*);

#endif
