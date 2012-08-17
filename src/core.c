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
#define		BULLET_SPD	650
  Ammo		b;
  v2f		vd, vp = p->ship.pos;

  if (p->ship.shoot_press[0])
    {
      vp.x += p->turret_shoot[0] ? 6 : -6;
      vp.y -= 35;
      vd.x = 0;
      vd.y = -BULLET_SPD;
    }
  else if (p->ship.shoot_press[1])
    {
      vp.x += 35;
      vp.y += p->turret_shoot[1] ? 6 : -6;
      vd.x = BULLET_SPD;
      vd.y = 0;
    }
  else if (p->ship.shoot_press[2])
    {
      vp.x += p->turret_shoot[2] ? -6 : 6;
      vp.y += 35;
      vd.x = 0;
      vd.y = BULLET_SPD;
    }
  else if (p->ship.shoot_press[3])
    {
      vp.x -= 35;
      vp.y += p->turret_shoot[3] ? -6 : 6;
      vd.x = -BULLET_SPD;
      vd.y = 0;
    }

  b.type = AMMO_BULLET;
  b.from_who = (Ship*)p;
  b.duration_time = 1.;
  b.rad = 0.;
  b.pos = vp;
  b.dir = vd;
  ammo_push(d, &b);
}

void		core_xship_shoot(Data* d, XShip* p)
{
  unsigned	u;
  (void)d;

  for (u = 0; u < 4; ++u)
    if (p->ship.shoot_press[u] &&
	SDLazy_GetTotalTime() > p->time_last_turret_shoot + p->ship.shoot_freq)
      {
	p->time_last_turret_shoot = SDLazy_GetTotalTime();
	p->turret_shoot[u] = !p->turret_shoot[u];
	SDLazy_AnimRewind(p->turret_anim[u * 2 + p->turret_shoot[u]]);
	SDLazy_AnimPlay(p->turret_anim[u * 2 + p->turret_shoot[u]]); /* rajouter une feature dans la lib, pour faire les deux en meme temps */
	create_ammo(d, p);
	p->ship.shoot_freq *= 1.1;
      }
}

void		core(void)
{
  Data*		d = SDLazy_GetData();

  core_camera_focus(&d->sdldata, &d->player->pos);
  core_ship_move(d, d->player);
  core_xship_shoot(d, (XShip*)d->player);
  ammos_core(&d->ammos);
}
