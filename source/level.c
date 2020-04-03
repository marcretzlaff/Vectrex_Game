// ***************************************************************************
// level
// ***************************************************************************

#include <vectrex.h>
#include "utils/utils.h"
#include "game.h"
#include "level.h"
#include "player.h"

// ---------------------------------------------------------------------------

struct level_t current_level =
{
	.status = LEVEL_LOST,
	.count = 0,
	.frame = 0,
};

extern int speed;

// ---------------------------------------------------------------------------

void level_init()
{
	current_level.status = LEVEL_PLAY;
	current_level.count = 0;
	current_level.frame = 0;
	speed = 0;
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

		// frame start: this is where the action happens...
		handle_player();

		current_level.frame += 1;
		// end of frame
	}
}	

// ***************************************************************************
// end of file
// ***************************************************************************
