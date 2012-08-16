#include	"sdldata.h"
#include	"SDLazy.h"

v2f*		pos_onscreen(v2f* cam, v2f* w)
{
  static v2f	v;

  v.x = (int)(SDLazy_GetWidth(0) / 2 - cam->x + w->x);
  v.y = (int)(SDLazy_GetHeight(0) / 2 - cam->y + w->y);
  return &v;
}
