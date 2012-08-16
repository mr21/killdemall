#include	"core.h"
#include	"data.h"

void		core_camera_focus(SDLData* d, v2f* v)
{
#define		CAMSPD		4.0
  d->cam.x += (v->x - d->cam.x) * CAMSPD * SDLazy_GetFrameTime();
  d->cam.y += (v->y - d->cam.y) * CAMSPD * SDLazy_GetFrameTime();
}

static void	create_ammo(Data* d, XShip* p)
{
  Ammo		b;

  b.type = AMMO_BULLET;
  b.from_who = (Ship*)p;
  b.pos = p->ship.pos;

  ammo_push(d, &b);
}

void		core_xship_shoot(Data* d, XShip* p)
{
  unsigned	u;
  double	cadence = .2;
  (void)d;

  for (u = 0; u < 4; ++u)
    if (p->ship.shoot_press[u] &&
	SDLazy_GetTotalTime() > p->time_last_turret_shoot + cadence)
      {
	p->time_last_turret_shoot = SDLazy_GetTotalTime();
	p->turret_shoot[u] = !p->turret_shoot[u];
	SDLazy_AnimRewind(p->turret_anim[u * 2 + p->turret_shoot[u]]);
	SDLazy_AnimPlay(p->turret_anim[u * 2 + p->turret_shoot[u]]); /* rajouter une feature dans la lib, pour faire les deux en meme temps */
	create_ammo(d, p);
      }
}

void		core(void)
{
  Data*		d = SDLazy_GetData();

  core_camera_focus(&d->sdldata, &d->player->pos);

  core_ship_move(d, d->player);
  core_xship_shoot(d, (XShip*)d->player);
}
