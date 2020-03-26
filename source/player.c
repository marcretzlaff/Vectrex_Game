// ***************************************************************************
// player
// ***************************************************************************

#include <vectrex.h>
#include "utils/controller.h"
#include "utils/utils.h"
#include "utils/vector.h"
#include "game.h"
#include "level.h"
#include "player.h"

// ---------------------------------------------------------------------------

struct player_t player =
{
	.status = DEAD,
	.y = 0,
	.x = 0,
};

// ---------------------------------------------------------------------------

#undef SF
#define SF 32


const struct packet_t vectors_player[] =
{
	{MOVE, {  1 * SF, -1 * SF}},
	{DRAW, {  0 * SF,  2 * SF}},
	{DRAW, { -2 * SF,  0 * SF}},
	{DRAW, {  0 * SF, -2 * SF}},
	{DRAW, {  2 * SF,  0 * SF}},
	{STOP, { 0, 0}},
};






// ---------------------------------------------------------------------------

void draw_player(void)
{
	Reset0Ref();					// reset beam to center of screen
	dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
	Moveto_d(player.y, player.x);	// move beam to object coordinates
	dp_VIA_t1_cnt_lo = 0x22;		// set scalinf factor for drawing
	Draw_VLp(&vectors_player);		// draw vector list
}

// ---------------------------------------------------------------------------

void init_player(void)
{
	player.status = ALIVE;
	player.y = 0;
	player.x = 0;
}

// ---------------------------------------------------------------------------

void move_player(void)
{
	const int speed = 1;

	check_joysticks();
	
	if (joystick_1_down())
	{
		player.y -= speed;
	}
	else if (joystick_1_up())
	{
		player.y += speed;
	}

	if (joystick_1_left())
	{
		player.x -= speed;
	}
	else if (joystick_1_right())
	{
		player.x += speed;
	}
}

// ---------------------------------------------------------------------------

void handle_player(void)
{
	//move_player();
	draw_player();

	if (player.status == DEAD)
	{
		current_level.status = LEVEL_LOST;
	}
}

// ***************************************************************************
// end of file
// ***************************************************************************

