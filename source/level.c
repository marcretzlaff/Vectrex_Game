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

//#define DEBUG

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
	.count_fall = 10,
	.count_rot = 3,
	
	//enemy.c
	.pipe_space = 65,
	.pipe_space_count = 65,
	.obstacles_iterator = 3,
	.obstacles_count = 4,

	//object.c
	.hole_heigth_half = 100,
	.max_next_pipe_rand = 50,
	
	//level change
	.end = 0,
};

// ---------------------------------------------------------------------------

void level_init()
{
	current_level.status = LEVEL_PLAY;
	current_level.count = 0;
	current_level.frame = 0;
	
	level_const.end = 0;

	//init s_levels_const
	#ifdef DEBUG
	level_const = (struct s_level_const){6,5,5,1,10,3,63,63,3,4,40,70,0};
	#else
	switch(current_game.level)
	{
		case 1:
			level_const = (struct s_level_const){6,5,5,1,10,3,127,127,1,2,45,80,0};
			break;
		case 2:
			level_const = (struct s_level_const){6,5,5,1,10,3,85,85,2,3,40,60,0};
			break;
		case 3:
			level_const = (struct s_level_const){6,5,5,1,10,3,63,63,3,4,40,70,0};
			break;
		case 4:
			level_const = (struct s_level_const){6,5,5,1,10,3,51,51,4,5,35,70,0};
			break;
		default:
			level_const = (struct s_level_const){6,5,5,1,10,3,63,63,3,4,35,50,0};
			break;
	}
	#endif
}	

// ---------------------------------------------------------------------------

void level_play(void)
{
	if(current_game.level == 1) init_player();
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

		if(level_const.end != 0) 
		{
			if(level_const.end < 100)
			{
				print_string(120, -40, "LEVEL\x80");
				print_unsigned_int(120, 40, current_game.level);
			}
			if(! --level_const.end) current_level.status = LEVEL_WON;
		}
		// end of frame
	}
}	

// ***************************************************************************
// end of file
// ***************************************************************************
