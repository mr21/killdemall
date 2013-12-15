#include	"xship.h"
#include	"kamship.h"

static int	_core(Ship* s)
{
  ship_core(s);
  s->core(s);
  return CLIST_CONTINUE;
}

void		ships_core(CList* ships)
{
  CList_foreach(ships, _core);
}
