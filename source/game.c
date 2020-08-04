// ***************************************************************************
// game
// ***************************************************************************

#include <vectrex.h>
#include "utils/controller.h"
#include "utils/print.h"
#include "utils/utils.h"
#include "utils/random.h"
#include "game.h"
#include "level.h"

// ---------------------------------------------------------------------------

struct game_t current_game =
{
	.option_players = 0,
	.option_mode = 0,
	.lives = 0,
	.level = 0,
	.score =  0,
	.player = 0,
	.control = 1,
	.maxlevel = 4,
	.world = 1
};

// ---------------------------------------------------------------------------

static inline __attribute__((always_inline))
void game_options(void)
{
	Select_Game(1 /* max_players */, 1 /* max_options */);
	current_game.option_players = Vec_Num_Players;
	current_game.option_mode = Vec_Num_Game;
}

// ---------------------------------------------------------------------------

void game_init(void)
{
	// activate first joystick, switch off second joystick
	enable_controller_1_x();
	enable_controller_1_y();
	disable_controller_2_x();
	disable_controller_2_y();
	
	// set player data
	current_game.lives = 1; 
	current_game.level = 1;
	current_game.score = 0;
	
	init_my_rng(VIA_t2_hi,~VIA_t2_hi,VIA_t2_hi << 4);
}

// ---------------------------------------------------------------------------
// main game loop, this is where the action happens

void game_play(void)
{
	while(current_game.lives)
	{
		level_init();
		level_play();

		if (current_level.status == LEVEL_WON)
		{
			++current_game.level;
		}
		else
		{
			if (--current_game.lives == 0)
			{
				game_over();
			}
		}
	}
}

// ---------------------------------------------------------------------------

void game_over(void)
{
	// update system high score
	int score[7];
	Clear_Score(&score);
	Add_Score_a(current_game.score, &score);
	New_High_Score(&score, (void*) &Vec_High_Score);

	unsigned int delay = 150;

	do
	{
		Sync();
		Intensity_5F();
		print_string(100, -100, "SCORE:\x80");
		print_unsigned_int(100, 40, current_game.score);
		print_string(80, -100, "HIGHSCORE:\x80");
		print_unsigned_int(80, 40, Vec_High_Score);
		print_string(0, -64, "GAME OVER\x80");
		print_string(20, -87, "SILVER SURFER\x80");
		Print_Ships(0x69, current_game.lives, 0xC0E2);
		check_buttons();
	}
	while((--delay) && !button_1_4_pressed());
}

// ---------------------------------------------------------------------------

int game(void)
{
	do
	{
		Wait_Recal();
		Print_Str_d( 80,-84,"SILVER SURFER\x80");
		Print_Str_d(-60,-91,"PRESS BUTTON 4\x80");
		Print_Str_d(-90,-75,"TO CONTINUE\x80");
		
		if(current_game.control)
		{
			Print_Str_d(-10,-93,"CONTROL    JOY\x80");
		}
		else
		{
			Print_Str_d(-10,-93,"CONTROL BUTTON\x80");
		}

		if(current_game.world)
		{
			Print_Str_d(20,-93, "WORLD    EARTH\x80");
		}
		else
		{
			Print_Str_d(20,-93, "WORLD     MOON\x80");
		}
		
		check_buttons();
		if(button_1_1_pressed())
		{
			current_game.control = (unsigned int) (current_game.control? 0:1);
		}
		if(button_1_2_pressed())
		{
			current_game.world = (unsigned int) (current_game.world? 0:1);
		}
	}
	while(!button_1_4_pressed());
	current_game.option_players = 1;
	current_game.option_mode = 1;
	if (button_1_4_held())
	{
		game_init();
		game_play();
		return 0;		// go to option screen, repeat cycle
	}
	else
	{
		return -1; 		// jump to title screen
	}
}

// ***************************************************************************
// end of file
// ***************************************************************************
