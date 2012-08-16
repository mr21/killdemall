#include	"render.h"
#include	"data.h"
#include	"sdldata.h"
#include	"xship.h"

void		render_xship(SDLData* d, XShip* p)
{
  unsigned	u;
  v2f		v = *pos_onscreen(&d->cam, &p->ship.pos);

  SDLazy_SetPos(d->srf_ship[SRF_SHIP_NO], &v);
  SDLazy_SetPos(d->srf_ship[SRF_SHIP_NE], &v);
  SDLazy_SetPos(d->srf_ship[SRF_SHIP_SO], &v);
  SDLazy_SetPos(d->srf_ship[SRF_SHIP_SE], &v);

  SDLazy_Blit(d->srf_ship[SRF_SHIP_NO]);
  SDLazy_Blit(d->srf_ship[SRF_SHIP_NE]);
  SDLazy_Blit(d->srf_ship[SRF_SHIP_SO]);
  SDLazy_Blit(d->srf_ship[SRF_SHIP_SE]);

  for (u = 0; u < 8; ++u)
    {
      SDLazy_SetPos(p->turret_anim[u], &v);
      SDLazy_Blit(p->turret_anim[u]);
    }
}

void		render(void)
{
  Data*		d = SDLazy_GetData();
  v2f		v = *pos_onscreen(&d->sdldata.cam, v2f_(SDLazy_GetWidth(d->sdldata.srf_bg[BG0]) / -2,
							SDLazy_GetHeight(d->sdldata.srf_bg[BG0]) / -2));

  SDL_FillRect(SDLazy_GetScreen(), 0, 0);

  SDLazy_SetPos(d->sdldata.srf_bg[BG0], &v);
  SDLazy_Blit(d->sdldata.srf_bg[BG0]);

  render_xship(&d->sdldata, (XShip*)d->player);

  ammos_blit(&d->sdldata, &d->ammos);
}
