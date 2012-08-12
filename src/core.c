#include	"core.h"
#include	"data.h"

void		core_camera_focus(SDLData* d, v2f* v)
{
#define		CAMSPD		4.0
  d->cam.x += (v->x - d->cam.x) * CAMSPD * SDLazy_GetFrameTime();
  d->cam.y += (v->y - d->cam.y) * CAMSPD * SDLazy_GetFrameTime();
}

void		core_player_shoot(Data* d, Player* p)
{
  unsigned	u;
  double	cadence = .2;
  (void)d;

  for (u = 0; u < 4; ++u)
    if (p->entity.shoot_press[u])
      {
	if (SDLazy_GetTotalTime() > p->time_last_turret_shoot + cadence)
	  {
	    p->time_last_turret_shoot = SDLazy_GetTotalTime();
	    p->turret_shoot[u] = !p->turret_shoot[u];
	    SDLazy_AnimRewind(p->turret_anim[u * 2 + p->turret_shoot[u]]);
	    SDLazy_AnimPlay(p->turret_anim[u * 2 + p->turret_shoot[u]]); /* rajouter une feature dans la lib, pour faire les deux en meme temps */
	  }
      }
}

void		core(void)
{
  Data*		d = SDLazy_GetData();

  core_camera_focus(&d->sdldata, &d->player.entity.pos);

  core_entity_move(d, &d->player.entity);
  core_player_shoot(d, &d->player);
}
