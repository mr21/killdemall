#include	"xship.h"
#include	"data.h"

#define		BULLET_SPD	650
#define		FREQ_FACT	1.1
#define		RECOIL		120.0

static void	ammo0(XShip* s, v2f* vp, v2f* vd, float* pan)
{
  vd->x = 0;
  vd->y = -BULLET_SPD;
  vp->x += (6 + SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_NO])) * (s->turret_shoot[0] ? 1 : -1);
  vp->y -= 33 + (s->turret_shoot[0] ?
		 SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NE]) :
		 SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NO]));
  ship_recoil((Ship*)s, RECOIL, SHIP_AXE_Y);
  *pan = s->turret_shoot[0] ? .5 : -.5;
}

static void	ammo1(XShip* s, v2f* vp, v2f* vd, float* pan)
{
  vd->x = BULLET_SPD;
  vd->y = 0;
  vp->y += (6 + SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NE])) * (s->turret_shoot[1] ? 1 : -1);
  vp->x += 33 - (s->turret_shoot[1] ?
		 SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_SE]) :
		 SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_NE]));
  ship_recoil((Ship*)s, -RECOIL, SHIP_AXE_X);
  *pan = .5;
}

static void	ammo2(XShip* s, v2f* vp, v2f* vd, float* pan)
{
  vd->x = 0;
  vd->y = BULLET_SPD;
  vp->x += (6 + SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_SO])) * (s->turret_shoot[2] ? -1 : 1);
  vp->y += 33 + (s->turret_shoot[2] ?
		 SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NO]) :
		 SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NE]));
  ship_recoil((Ship*)s, -RECOIL, SHIP_AXE_Y);
  *pan = s->turret_shoot[2] ? -.5 : .5;
}

static void	ammo3(XShip* s, v2f* vp, v2f* vd, float* pan)
{
  vd->x = -BULLET_SPD;
  vd->y = 0;
  vp->y += (6 + SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NO])) * (s->turret_shoot[3] ? -1 : 1);
  vp->x -= 33 + (s->turret_shoot[3] ?
		 SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_NO]) :
		 SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_SO]));
  ship_recoil((Ship*)s, RECOIL, SHIP_AXE_X);
  *pan = -.5;
}

static void	create_ammo(Data* d, XShip* p)
{
  Ammo		b;
  v2f		vd, vp = p->ship.pos;
  float		pan;

  if (p->ship.shoot_dir & DIR_UP)
    ammo0(p, &vp, &vd, &pan);
  else if (p->ship.shoot_dir & DIR_RIGHT)
    ammo1(p, &vp, &vd, &pan);
  else if (p->ship.shoot_dir & DIR_DOWN)
    ammo2(p, &vp, &vd, &pan);
  else if (p->ship.shoot_dir & DIR_LEFT)
    ammo3(p, &vp, &vd, &pan);

  b.type = AMMO_BULLET;
  b.from_who = (Ship*)p;
  b.duration_time = 1.;
  b.rad = 0.;
  b.pos = vp;
  b.dir = vd;
  ammo_push(d, &b);
  sound_play(SND_XHSIP_SHOOT, .8, pan, 60000 + rand() % 20000);
}

void            xship_shoot(Data* d, XShip* p)
{
  unsigned	u = 1, v = 0;

  for (; v < 4; ++v, u <<= 1)
    if (p->ship.shoot_dir & u &&
        SDLazy_GetTotalTime() > p->time_last_turret_shoot + p->ship.shoot_freq)
      {
	p->time_last_turret_shoot = SDLazy_GetTotalTime();
        p->turret_shoot[v] = !p->turret_shoot[v];
        p->ship.shoot_freq *= FREQ_FACT;
        SDLazy_AnimReplay(p->turret_anim[v * 2 + p->turret_shoot[v]]);
        create_ammo(d, p);
      }
}
