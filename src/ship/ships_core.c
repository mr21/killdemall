#include	"xship.h"
#include	"kamship.h"

static int	_core(Ship* s)
{
  ship_core(s);
  switch (s->type)
    {
    case XSHIP:   xship_core((XShip*)s); break;
    case KAMSHIP: /**/ break;
    }
  return CLIST_CONTINUE;
}

void		ships_core(CList* ships)
{
  CList_foreach(ships, _core);
}
