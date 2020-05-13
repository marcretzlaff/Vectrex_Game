// ***************************************************************************
// level
// ***************************************************************************

#include <vectrex.h>
#include "utils/utils.h"
#include "game.h"
#include "level.h"
#include "player.h"
#include "enemy.h"
#include "utils/print.h"

// ---------------------------------------------------------------------------

struct level_t current_level =
{
	.status = LEVEL_LOST,
	.count = 0,
	.frame = 0,
};

struct s_level_const level_const =
{
	//player.c
	.jumpmp = 6,
	.jump = 5,
	.timeout = 5,
	.speed = 1,
	
	//enemy.c
	.pipe_space = 65,
	.obstacles_iterator = 3,
	.obstacles_count = 4,

	//object.c
	.hole_heigth_half = 35,
	.max_next_pipe_rand = 50,
	
	//level change
	.end = 0,
};

// ---------------------------------------------------------------------------

void level_init()
{
	int i;
	current_level.status = LEVEL_PLAY;
	current_level.count = 0;
	current_level.frame = 0;

	//init s_levels_const
	switch(current_game.level)
	{
		case 1:
			level_const = (struct s_level_const){6,5,5,1,130,1,2,50,40,0};
			break;
		case 2:
			level_const = (struct s_level_const){6,5,5,1,65,3,4,35,50,0};
			
		case 3:
			level_const = (struct s_level_const){6,5,5,1,52,4,5,35,60,0};
			
		default:
			level_const = (struct s_level_const){6,5,5,1,65,3,4,35,50,0};
			break;
	}

	for(i = 0; i< OBSTACLES_COUNT; i++)
	{
		obstacles[i].activ = 0;
	}
}	

// ---------------------------------------------------------------------------

void level_play(void)
{
	init_player();
	while(current_level.status == LEVEL_PLAY)
	{
		// game loop header start - do not change
		DP_to_C8();
		Explosion_Snd(current_explosion);
		Init_Music_chk(current_music);
		Wait_Recal();
		Do_Sound();
		Intensity_5F();
		// game loop header end
		print_unsigned_int(120, -100, current_game.score);
		// frame start: this is where the action happens...
		handle_player();
		handle_enemies();

		current_level.frame += 1;
		// end of frame
	}
}	

// ***************************************************************************
// end of file
// ***************************************************************************
