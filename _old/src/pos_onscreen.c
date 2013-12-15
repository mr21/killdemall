#include	"sdldata.h"
#include	"SDLazy.h"

void		pos_onscreen(v2f* v, v2f* cam, v2f* w)
{
  v->x = (int)(SDLazy_GetWidth(0)  / 2 - cam->x + w->x);
  v->y = (int)(SDLazy_GetHeight(0) / 2 - cam->y + w->y);
}
