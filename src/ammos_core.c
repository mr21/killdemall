#include	"CList.h"
#include	"ammo.h"

static int	ammo_update(Ammo* am)
{
  if (am->duration_time < SDLazy_GetTotalTime())
    return 1;
  am->pos.x += am->dir.x * SDLazy_GetFrameTime();
  am->pos.y += am->dir.y * SDLazy_GetFrameTime();
  return 0;
}

void		ammos_core(CList* ammos)
{
  CLink*	ln = CList_begin(ammos);

  while (ln)
    ln = ammo_update(ln->data) ? CList_erase(ln) : ln->next;
}
