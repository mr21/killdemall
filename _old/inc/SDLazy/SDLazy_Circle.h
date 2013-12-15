#ifndef			SDLAZY_CIRCLE_H
#define			SDLAZY_CIRCLE_H

typedef                 struct
{
  SDL_Surface*		srf;
  int			x;
  int			y;
  int			r;
  int			r_tmp;
  int			border_size;
  char			full_circle;
  double		deg[2];
  SDL_Color		col_ext;
  SDL_Color		col_int;
}			SDLazy_Circle;

void			SDLazy_DrawCircle(SDLazy_Circle* circle);

#endif
