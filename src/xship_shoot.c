#include	"xship.h"
#include	"data.h"

#define		BULLET_SPD	800
#define		FREQ_FACT	1.1

static void	create_ammo(Data* d, XShip* p)
{
  Ammo		b;
  v2f		vd, vp = p->ship.pos;

  if (p->ship.shoot_press[0])
    {
      vp.x += p->turret_shoot[0] ? 6 : -6,	vp.y -= 35;
      vd.x = 0,					vd.y = -BULLET_SPD;
    }
  else if (p->ship.shoot_press[1])
    {
      vp.x += 35,				vp.y += p->turret_shoot[1] ? 6 : -6;
      vd.x = BULLET_SPD,			vd.y = 0;
    }
  else if (p->ship.shoot_press[2])
    {
      vp.x += p->turret_shoot[2] ? -6 : 6,	vp.y += 35;
      vd.x = 0,					vd.y = BULLET_SPD;
    }
  else if (p->ship.shoot_press[3])
    {
      vp.x -= 35,				vp.y += p->turret_shoot[3] ? -6 : 6;
      vd.x = -BULLET_SPD,			vd.y = 0;
    }

  b.type = AMMO_BULLET;
  b.from_who = (Ship*)p;
  b.duration_time = 1.;
  b.rad = 0.;
  b.pos = vp;
  b.dir = vd;
  ammo_push(d, &b);
}

void            xship_shoot(Data* d, XShip* p)
{
  unsigned      u;

  for (u = 0; u < 4; ++u)
    if (p->ship.shoot_press[u] &&
        SDLazy_GetTotalTime() > p->time_last_turret_shoot + p->ship.shoot_freq)
      {
	p->time_last_turret_shoot = SDLazy_GetTotalTime();
        p->turret_shoot[u] = !p->turret_shoot[u];
        p->ship.shoot_freq *= FREQ_FACT;
        SDLazy_AnimReplay(p->turret_anim[u * 2 + p->turret_shoot[u]]);
        create_ammo(d, p);
      }
}
