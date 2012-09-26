#include	"xship.h"
#include	"data.h"

#define		BULLET_SPD	650
#define		RECOIL		120.0

/* CE FICHIER EST L'UN DES PLUS DEGUEULASSE; A FACTORISER D'URGENCE!
(mais jle ferai sans doute jamais car j'osef) */

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
  vd->x = 0;
  vd->y = -BULLET_SPD;
  vp->x += (6 + SDLazy_GetCenterX(s->bases_sprite[SRF_XSHIP_NO])) * (s->turret_shoot[0] ? 1 : -1);
  vp->y -= 33 + (s->turret_shoot[0] ?
		 SDLazy_GetCenterY(s->bases_sprite[SRF_XSHIP_NE]) :
		 SDLazy_GetCenterY(s->bases_sprite[SRF_XSHIP_NO]));
  ship_recoil((Ship*)s, RECOIL, SHIP_AXE_Y);
}

static void	ammoRight(XShip* s, v2f* vp, v2f* vd)
{
  vd->x = BULLET_SPD;
  vd->y = 0;
  vp->y += (6 + SDLazy_GetCenterY(s->bases_sprite[SRF_XSHIP_NE])) * (s->turret_shoot[1] ? 1 : -1);
  vp->x += 33 - (s->turret_shoot[1] ?
		 SDLazy_GetCenterX(s->bases_sprite[SRF_XSHIP_SE]) :
		 SDLazy_GetCenterX(s->bases_sprite[SRF_XSHIP_NE]));
  ship_recoil((Ship*)s, -RECOIL, SHIP_AXE_X);
}

static void	ammoDown(XShip* s, v2f* vp, v2f* vd)
{
  vd->x = 0;
  vd->y = BULLET_SPD;
  vp->x += (6 + SDLazy_GetCenterX(s->bases_sprite[SRF_XSHIP_SO])) * (s->turret_shoot[2] ? -1 : 1);
  vp->y += 33 + (s->turret_shoot[2] ?
		 SDLazy_GetCenterY(s->bases_sprite[SRF_XSHIP_NO]) :
		 SDLazy_GetCenterY(s->bases_sprite[SRF_XSHIP_NE]));
  ship_recoil((Ship*)s, -RECOIL, SHIP_AXE_Y);
}

static void	ammoLeft(XShip* s, v2f* vp, v2f* vd)
{
  vd->x = -BULLET_SPD;
  vd->y = 0;
  vp->y += (6 + SDLazy_GetCenterY(s->bases_sprite[SRF_XSHIP_NO])) * (s->turret_shoot[3] ? -1 : 1);
  vp->x -= 33 + (s->turret_shoot[3] ?
		 SDLazy_GetCenterX(s->bases_sprite[SRF_XSHIP_NO]) :
		 SDLazy_GetCenterX(s->bases_sprite[SRF_XSHIP_SO]));
  ship_recoil((Ship*)s, RECOIL, SHIP_AXE_X);
}

static void	ammoUpRight(XShip* s, v2f* vp, v2f* vd)
{
  vd->x = +BULLET_SPD * 0.7071;
  vd->y = -BULLET_SPD * 0.7071;
  vp->y -= SDLazy_GetCenterY(s->bases_sprite[SRF_XSHIP_NE]);
  vp->x -= SDLazy_GetCenterX(s->bases_sprite[SRF_XSHIP_NE]);
  ship_recoil((Ship*)s, -RECOIL * 0.7071, SHIP_AXE_X);
  ship_recoil((Ship*)s, +RECOIL * 0.7071, SHIP_AXE_Y);
}

static void	ammoUpLeft(XShip* s, v2f* vp, v2f* vd)
{
  vd->x = -BULLET_SPD * 0.7071;
  vd->y = -BULLET_SPD * 0.7071;
  vp->y -= SDLazy_GetCenterY(s->bases_sprite[SRF_XSHIP_NO]);
  vp->x -= SDLazy_GetCenterX(s->bases_sprite[SRF_XSHIP_NO]);
  ship_recoil((Ship*)s, +RECOIL * 0.7071, SHIP_AXE_X);
  ship_recoil((Ship*)s, +RECOIL * 0.7071, SHIP_AXE_Y);
}

static void	ammoDownRight(XShip* s, v2f* vp, v2f* vd)
{
  vd->x = +BULLET_SPD * 0.7071;
  vd->y = +BULLET_SPD * 0.7071;
  vp->y -= SDLazy_GetCenterY(s->bases_sprite[SRF_XSHIP_SE]);
  vp->x -= SDLazy_GetCenterX(s->bases_sprite[SRF_XSHIP_SE]);
  ship_recoil((Ship*)s, -RECOIL * 0.7071, SHIP_AXE_X);
  ship_recoil((Ship*)s, -RECOIL * 0.7071, SHIP_AXE_Y);
}

static void	ammoDownLeft(XShip* s, v2f* vp, v2f* vd)
{
  vd->x = -BULLET_SPD * 0.7071;
  vd->y = +BULLET_SPD * 0.7071;
  vp->y -= SDLazy_GetCenterY(s->bases_sprite[SRF_XSHIP_SO]);
  vp->x -= SDLazy_GetCenterX(s->bases_sprite[SRF_XSHIP_SO]);
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

static float	_freq(Ship* s)
{
  return 44100 + 10000 *
    (1 - (s->shtfq_curr - s->shtfq_max) / (0.2 - s->shtfq_max)) +
    rand() % 10000;
}

static void	create_ammo(XShip* p)
{
  Ammo		b;
  v2f		vd;
  v2f		vp = p->ship.pos;

  ammo[p->ship.shoot_dir](p, &vp, &vd);
  b.type = AMMO_BULLET;
  b.from_who = (Ship*)p;
  b.duration_time = 1.;
  b.rad = 0.;
  b.pos = vp;
  b.dir = vd;
  ammo_push(SDLazy_GetData(), &b);
  sound_play(SND_XSHIP_SHOOT, .8, _pan(p->ship.shoot_dir), _freq(&p->ship));
}

void            xship_shoot(XShip* p)
{
  int		anim;

  if (ammo[p->ship.shoot_dir] &&
      SDLazy_GetTotalTime() > p->time_last_turret_shoot + p->ship.shtfq_curr)
    {
      p->time_last_turret_shoot = SDLazy_GetTotalTime();
      p->ship.shtfq_curr *= p->ship.shtfq_lost;
      create_ammo(p);
      anim = p->ship.shoot_dir;
      if (anim < 3 || anim == 4 || anim == 8)
	{
	  anim = anim < 3 ? anim - 1 : anim == 4 ? 2 : 3;
	  SDLazy_AnimReplay(p->turret_anim[anim * 2 + p->turret_shoot[anim]]);
	  p->turret_shoot[anim] = !p->turret_shoot[anim];
	}
    }
}
