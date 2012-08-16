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

  SDLazy_SetPos(d->srf[SRF_P_NO], &v);
  SDLazy_SetPos(d->srf[SRF_P_NE], &v);
  SDLazy_SetPos(d->srf[SRF_P_SO], &v);
  SDLazy_SetPos(d->srf[SRF_P_SE], &v);

  SDLazy_Blit(d->srf[SRF_P_NO]);
  SDLazy_Blit(d->srf[SRF_P_NE]);
  SDLazy_Blit(d->srf[SRF_P_SO]);
  SDLazy_Blit(d->srf[SRF_P_SE]);

  for (u = 0; u < 8; ++u)
    {
      SDLazy_SetPos(p->turret_anim[u], &v);
      SDLazy_Blit(p->turret_anim[u]);
    }
}

void		render(void)
{
  Data*		d = SDLazy_GetData();
  v2f		v = *v2f_calc_pos(&d->sdldata, v2f_(SDLazy_GetWidth(d->sdldata.srf[SRF_BG]) / -2,
						    SDLazy_GetHeight(d->sdldata.srf[SRF_BG]) / -2));

  SDL_FillRect(SDLazy_GetScreen(), 0, 0);

  SDLazy_SetPos(d->sdldata.srf[SRF_BG], &v);
  SDLazy_Blit(d->sdldata.srf[SRF_BG]);

  render_xship(&d->sdldata, (XShip*)d->player);
}
