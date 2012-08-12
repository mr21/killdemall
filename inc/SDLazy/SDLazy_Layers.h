#ifndef			SDLAZY_LAYERS_H
# define		SDLAZY_LAYERS_H

# include		<SDL/SDL.h>
# include		"myMath.h"

typedef			struct
{
  v2f			center;
  v2f			scale;
  double		radians;
}			SDLazy_Layer;

typedef			struct
{
  SDLazy_Layer		layers;
}			SDLazy_Layers;

void			SDLazy_LayerCreate(Uint32 id);
void			SDLazy_FreeLayers(void);

/* Le centre du calque */
v2f*			SDLazy_LayerGetCenter(Uint32 id);
void			SDLazy_LayerSetCenter(Uint32 id, v2f* center);
void			SDLazy_LayerMove(Uint32 id, v2f* incr);

/* Zoom */
v2f*			SDLazy_LayerGetScale(Uint32 id);
void			SDLazy_LayerSetScale(Uint32 id, v2f* scale);
void			SDLazy_LayerZoom(Uint32 id, v2f* zoom);

/* Rotation */
double			SDLazy_LayerGetRad(Uint32 id);
void			SDLazy_LayerSetRad(Uint32 id, double rad);
void			SDLazy_LayerRot(Uint32 id, double incr);

#endif
