#include	"data.h"

v2f*		v2f_calc_pos(SDLData* d, v2f* w)
{
  static v2f	v;

  v.x = (int)(SDLazy_GetWidth(0) / 2 - d->cam.x + w->x);
  v.y = (int)(SDLazy_GetHeight(0) / 2 - d->cam.y + w->y);
  return &v;
}

void		render_xship(SDLData* d, XShip* p)
{
  unsigned	u;
  v2f		v = *v2f_calc_pos(d, &p->ship.pos);

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
  v2f		v = *v2f_calc_pos(&d->sdldata, v2f_(SDLazy_GetWidth(d->sdldata.srf_bgs[BG0]) / -2,
						    SDLazy_GetHeight(d->sdldata.srf_bgs[BG0]) / -2));

  SDL_FillRect(SDLazy_GetScreen(), 0, 0);

  SDLazy_SetPos(d->sdldata.srf_bgs[BG0], &v);
  SDLazy_Blit(d->sdldata.srf_bgs[BG0]);

  render_xship(&d->sdldata, (XShip*)d->player);
}
