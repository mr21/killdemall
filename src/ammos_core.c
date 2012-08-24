#include	"CList.h"
#include	"ammo.h"

static int	ammo_update(Ammo* am)
{
  if (am->duration_time < SDLazy_GetTotalTime())
    return CLIST_ERASE;
  am->pos.x += am->dir.x * SDLazy_GetFrameTime();
  am->pos.y += am->dir.y * SDLazy_GetFrameTime();
  return CLIST_CONTINUE;
}

void		ammos_core(CList* ammos)
{
  CList_foreach(ammos, ammo_update);
}
