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
};

struct s_level_const level_const =
{
	//player.c
	.jumpmp = 6,
	.jump = 5,
	.timeout = 2,
	.speed = 1,
	.count_fall = 10,
	.count_rot = 3,
	.boost = 100,
	.boosttimeout = 255,
	.boosted = 0,
	
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
	int i;
	current_level.status = LEVEL_PLAY;

	//init s_levels_const
	#ifdef DEBUG
	level_const = (struct s_level_const){10,6,2,1,10,3,100,255,0,127,127,1,2,60,100,0};
	#else
	if(current_game.world)
	{
		switch(current_game.level)
		{
			case 1:
				level_const = (struct s_level_const){6,5,2,1,10,3,100,255,0,127,127,1,2,60,70,0};
				break;
			case 2:
				level_const = (struct s_level_const){6,5,2,1,10,3,100,255,0,85,85,2,3,50,70,0};
				break;
			case 3:
				level_const = (struct s_level_const){6,5,2,1,10,3,100,255,0,63,63,3,4,45,80,0};
				break;
			case 4:
				level_const = (struct s_level_const){6,5,2,1,10,3,100,255,0,51,51,4,5,45,90,0};
				break;
			default:
				level_const = (struct s_level_const){6,5,2,1,10,3,100,255,0,63,63,3,4,35,50,0};
				break;
		}
	}
	else //moon
	{
		switch(current_game.level)
		{
			case 1:
				level_const = (struct s_level_const){10,5,2,1,10,3,127,255,0,127,127,1,2,50,80,0};
				break;
			case 2:
				level_const = (struct s_level_const){10,5,2,1,10,3,127,255,0,85,85,2,3,45,70,0};
				break;
			case 3:
				level_const = (struct s_level_const){10,5,2,1,10,3,127,255,0,63,63,3,4,45,70,0};
				break;
			case 4:
				level_const = (struct s_level_const){10,5,2,1,10,3,127,255,0,51,51,4,5,40,100,0};
				break;
			default:
				level_const = (struct s_level_const){10,5,2,1,10,3,127,255,0,127,127,1,2,45,80,0};
				break;
		}
	}
	
	#endif
	
	//reset obstacles
	for(i = 0; i < OBSTACLES_COUNT;i++)
	{
		obstacles[i].activ = 0;
	}
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
