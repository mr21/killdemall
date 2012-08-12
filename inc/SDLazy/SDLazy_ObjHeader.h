#ifndef			SDLAZY_OBJHEADER
# define		SDLAZY_OBJHEADER

# include		<SDL/SDL.h>
# include		"SDLazy_ObjType.h"
# include		"SDLazy_TinySprite.h"
# include		"myMath.h"

typedef struct SDLazy_ObjHeader SDLazy_ObjHeader;

struct			SDLazy_ObjHeader
{
  eObjType		obj_type;
  SDLazy_ObjHeader*	parent;
  SDL_Surface*		srf_src;
  SDL_Surface*		srf_dst;
  SDLazy_TinySprite*	tsp_curr;
  Uint8			cnt_align;
  v2f			cnt;
  SDL_Rect		pos_abs;
  Uint8			pos_align;
  v2f			pos_rel;
  double		rad_rel;
  v2f			scl_rel;
  double		cos_rad_rel;
  double		sin_rad_rel;
};

void			SDLazy_InitObjHeader(SDLazy_ObjHeader*, eObjType, SDL_Surface* src);

int			SDLazy_Hover(void* obj);

eObjType		SDLazy_GetType(void*);
double			SDLazy_GetWidth(void*);
double			SDLazy_GetHeight(void*);

/* Position / Scale / Rotation (relative) */

/*   Setters ( = ) */
void			SDLazy_SetPosAlign(void*, Uint8);
void			SDLazy_SetPos(void*, v2f*);
void			SDLazy_SetPosX(void*, double);
void			SDLazy_SetPosY(void*, double);
void			SDLazy_SetScale(void*, v2f*);
void			SDLazy_SetScaleX(void*, double);
void			SDLazy_SetScaleY(void*, double);
void			SDLazy_SetRot(void*, double);
void			SDLazy_SetCenterAlign(void*, Uint8);
void			SDLazy_SetCenter(void*, v2f*);
void			SDLazy_SetCenterX(void*, double);
void			SDLazy_SetCenterY(void*, double);

/*   Increment ( += ) */
void			SDLazy_IncPos(void*, v2f*);
void			SDLazy_IncPosX(void*, double);
void			SDLazy_IncPosY(void*, double);
void			SDLazy_IncScale(void*, v2f*);
void			SDLazy_IncScaleX(void*, double);
void			SDLazy_IncScaleY(void*, double);
void			SDLazy_IncRot(void*, double);
void			SDLazy_IncCenter(void*, v2f*);
void			SDLazy_IncCenterX(void*, double);
void			SDLazy_IncCenterY(void*, double);

/*   Getters */
Uint8			SDLazy_GetPosAlign(void*);
v2f*			SDLazy_GetPos(void*);
double			SDLazy_GetPosX(void*);
double			SDLazy_GetPosY(void*);
v2f*			SDLazy_GetScale(void*);
double			SDLazy_GetScaleX(void*);
double			SDLazy_GetScaleY(void*);
double			SDLazy_GetRot(void*);
Uint8			SDLazy_GetCenterAlign(void*);
v2f*			SDLazy_GetCenter(void*);
double			SDLazy_GetCenterX(void*);
double			SDLazy_GetCenterY(void*);

#endif
