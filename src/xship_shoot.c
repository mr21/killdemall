#include	"xship.h"
#include	"data.h"

#define		BULLET_SPD	650
#define		RECOIL		120.0

/*
x 0001  1 UP
x 0010  2 RIGHT
x 0100  4 DOWN
x 1000  8 LEFT

x 0011  3 UP   | RIGHT
x 1001  9 UP   | LEFT
x 0110  6 DOWN | RIGHT
x 1100 12 DOWN | LEFT
*/

static void	ammoUp(XShip* s, v2f* vp, v2f* vd)
{
  vd->x += 0;
  vd->y += -BULLET_SPD;
  vp->x += (6 + SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_NO])) * (s->turret_shoot[0] ? 1 : -1);
  vp->y -= 33 + (s->turret_shoot[0] ?
		 SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NE]) :
		 SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NO]));
  ship_recoil((Ship*)s, RECOIL, SHIP_AXE_Y);
}

static void	ammoRight(XShip* s, v2f* vp, v2f* vd)
{
  vd->x += BULLET_SPD;
  vd->y += 0;
  vp->y += (6 + SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NE])) * (s->turret_shoot[1] ? 1 : -1);
  vp->x += 33 - (s->turret_shoot[1] ?
		 SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_SE]) :
		 SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_NE]));
  ship_recoil((Ship*)s, -RECOIL, SHIP_AXE_X);
}

static void	ammoDown(XShip* s, v2f* vp, v2f* vd)
{
  vd->x += 0;
  vd->y += BULLET_SPD;
  vp->x += (6 + SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_SO])) * (s->turret_shoot[2] ? -1 : 1);
  vp->y += 33 + (s->turret_shoot[2] ?
		 SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NO]) :
		 SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NE]));
  ship_recoil((Ship*)s, -RECOIL, SHIP_AXE_Y);
}

static void	ammoLeft(XShip* s, v2f* vp, v2f* vd)
{
  vd->x += -BULLET_SPD;
  vd->y += 0;
  vp->y += (6 + SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NO])) * (s->turret_shoot[3] ? -1 : 1);
  vp->x -= 33 + (s->turret_shoot[3] ?
		 SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_NO]) :
		 SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_SO]));
  ship_recoil((Ship*)s, RECOIL, SHIP_AXE_X);
}

static void	ammoUpRight(XShip* s, v2f* vp, v2f* vd)
{
  vd->x += BULLET_SPD * 0.7071;
  vd->y -= BULLET_SPD * 0.7071;
  vp->y -= SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NE]);
  vp->x -= SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_NE]);
  ship_recoil((Ship*)s, -RECOIL * 0.7071, SHIP_AXE_X);
  ship_recoil((Ship*)s, +RECOIL * 0.7071, SHIP_AXE_Y);
}

static void	ammoUpLeft(XShip* s, v2f* vp, v2f* vd)
{
  vd->x -= BULLET_SPD * 0.7071;
  vd->y -= BULLET_SPD * 0.7071;
  vp->y -= SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_NO]);
  vp->x -= SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_NO]);
  ship_recoil((Ship*)s, +RECOIL * 0.7071, SHIP_AXE_X);
  ship_recoil((Ship*)s, +RECOIL * 0.7071, SHIP_AXE_Y);
}

static void	ammoDownRight(XShip* s, v2f* vp, v2f* vd)
{
  vd->x += BULLET_SPD * 0.7071;
  vd->y += BULLET_SPD * 0.7071;
  vp->y -= SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_SE]);
  vp->x -= SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_SE]);
  ship_recoil((Ship*)s, -RECOIL * 0.7071, SHIP_AXE_X);
  ship_recoil((Ship*)s, -RECOIL * 0.7071, SHIP_AXE_Y);
}

static void	ammoDownLeft(XShip* s, v2f* vp, v2f* vd)
{
  vd->x -= BULLET_SPD * 0.7071;
  vd->y += BULLET_SPD * 0.7071;
  vp->y -= SDLazy_GetCenterY(s->bases_sprite[SRF_SHIP_SO]);
  vp->x -= SDLazy_GetCenterX(s->bases_sprite[SRF_SHIP_SO]);
  ship_recoil((Ship*)s, +RECOIL * 0.7071, SHIP_AXE_X);
  ship_recoil((Ship*)s, -RECOIL * 0.7071, SHIP_AXE_Y);
}

void		(*ammo[])(XShip* s, v2f* vp, v2f* vd) =
{
  NULL,		ammoUp,		ammoRight,	ammoUpRight,
  ammoDown,	NULL,		ammoDownRight,	NULL,
  ammoLeft,	ammoUpLeft,	NULL,		NULL,
  ammoDownLeft,	NULL,		NULL,		NULL
};

static float	_pan(eShipDir dir)
{
  return
    dir & DIR_LEFT  ? -.5 :
    dir & DIR_RIGHT ? +.5 :
    0;
}

static float	_freq()
{
  return 60000 + rand() % 20000;
}

static void	create_ammo(Data* d, XShip* p)
{
  Ammo		b;
  v2f		vd = {0, 0};
  v2f		vp = p->ship.pos;

  ammo[p->ship.shoot_dir](p, &vp, &vd);
  b.type = AMMO_BULLET;
  b.from_who = (Ship*)p;
  b.duration_time = 1.;
  b.rad = 0.;
  b.pos = vp;
  b.dir = vd;
  ammo_push(d, &b);
  sound_play(SND_XHSIP_SHOOT, .8, _pan(p->ship.shoot_dir), _freq());
}

void            xship_shoot(Data* d, XShip* p)
{
  unsigned	u, v;

  if (ammo[p->ship.shoot_dir])
    for (u = 1, v = 0; v < 4; ++v, u <<= 1)
      if (p->ship.shoot_dir & u &&
	  SDLazy_GetTotalTime() > p->time_last_turret_shoot + p->ship.shtfq_curr)
	{
	  p->time_last_turret_shoot = SDLazy_GetTotalTime();
	  p->turret_shoot[v] = !p->turret_shoot[v];
	  p->ship.shtfq_curr += p->ship.shtfq_lost;
	  SDLazy_AnimReplay(p->turret_anim[v * 2 + p->turret_shoot[v]]);
	  create_ammo(d, p);
	}
}
