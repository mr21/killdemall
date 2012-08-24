#include	"xship.h"
#include	"data.h"

#define		BULLET_SPD	650
#define		FREQ_FACT	1.1
#define		RECOIL		120.0

static void	ammo0(XShip* s, v2f* vp, v2f* vd)
{
  vd->x = 0;
  vd->y = -BULLET_SPD;
  vp->x += (6 + SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_NO])) * (s->turret_shoot[0] ? 1 : -1);
  vp->y -= 33 + (s->turret_shoot[0] ?
		 SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NE]) :
		 SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NO]));
  s->ship.dir.y += RECOIL;
}

static void	ammo1(XShip* s, v2f* vp, v2f* vd)
{
  vd->x = BULLET_SPD;
  vd->y = 0;
  vp->y += (6 + SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NE])) * (s->turret_shoot[1] ? 1 : -1);
  vp->x += 33 - (s->turret_shoot[1] ?
		 SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_SE]) :
		 SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_NE]));
  s->ship.dir.x -= RECOIL;
}

static void	ammo2(XShip* s, v2f* vp, v2f* vd)
{
  vd->x = 0;
  vd->y = BULLET_SPD;
  vp->x += (6 + SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_SO])) * (s->turret_shoot[2] ? -1 : 1);
  vp->y += 33 + (s->turret_shoot[2] ?
		 SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NO]) :
		 SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NE]));
  s->ship.dir.y -= RECOIL;
}

static void	ammo3(XShip* s, v2f* vp, v2f* vd)
{
  vd->x = -BULLET_SPD;
  vd->y = 0;
  vp->y += (6 + SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NO])) * (s->turret_shoot[3] ? -1 : 1);
  vp->x -= 33 + (s->turret_shoot[3] ?
		 SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_NO]) :
		 SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_SO]));
  s->ship.dir.x += RECOIL;
}

static void	create_ammo(Data* d, XShip* p)
{
  Ammo		b;
  v2f		vd, vp = p->ship.pos;

  if (p->ship.shoot_press[0])
    ammo0(p, &vp, &vd);
  else if (p->ship.shoot_press[1])
    ammo1(p, &vp, &vd);
  else if (p->ship.shoot_press[2])
    ammo2(p, &vp, &vd);
  else if (p->ship.shoot_press[3])
    ammo3(p, &vp, &vd);

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
