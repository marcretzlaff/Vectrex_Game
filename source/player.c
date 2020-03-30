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
	.x = -80,
	.timeout = 0,
	.jump = 0
};



typedef enum player_state_t
{
	FALL = 0,
	TIMEOUT,
	JUMP
} player_state;

// ---------------------------------------------------------------------------

#undef SF
#define SF 31


const struct packet_t vectors_player[] =
{
	{MOVE, { -3 * SF, -2 * SF}}, //left board
	{DRAW, {  1 * SF,  0 * SF}}, //left board up
	{DRAW, {  0 * SF,  4 * SF}}, //board bottom
	{MOVE, {  0 * SF, -3 * SF}}, //goto left foot
	{DRAW, {  1 * SF,  1 * SF}}, //left foot
	{DRAW, { -1 * SF,  1 * SF}}, //right foot
	{MOVE, {  1 * SF, -1 * SF}}, //goto waist
	{DRAW, {  3 * SF,  0 * SF}}, //draw waist
	{MOVE, { -2 * SF, -1 * SF}}, //goto left arm
	{DRAW, {  1 * SF,  1 * SF}}, //draw left arm
	{DRAW, { -1 * SF,  1 * SF}}, //draw right arm
	{MOVE, {  2 * SF,  0 * SF}}, //goto right lower head
	{DRAW, {  2 * SF,  0 * SF}}, //draw right
	{DRAW, {  0 * SF, -2 * SF}}, //draw upper
	{DRAW, { -2 * SF,  0 * SF}}, //draw left
	{DRAW, {  0 * SF,  2 * SF}}, //draw lower
	{STOP, { 0, 0}},
};


struct packet_t vectors_player_ram[sizeof(vectors_player)];

// ---------------------------------------------------------------------------

void draw_player(void)
{
	Reset0Ref();					// reset beam to center of screen
	dp_VIA_t1_cnt_lo = 0x7f;		// set scaling factor for positioning
	Moveto_d(player.y, player.x);	// move beam to object coordinates
	dp_VIA_t1_cnt_lo = 0x15;		// set scalinf factor for drawing
	Draw_VLp(&vectors_player_ram);		// draw vector list
}

// ---------------------------------------------------------------------------

void init_player(void)
{
	player.status = ALIVE;
	player.y = 0;
	player.x = -100;
	player.timeout = 0;
	player.jump = 0;
}

// ---------------------------------------------------------------------------

void move_player(void)
{
	const int speed = 1;
	const int jumpmp = 6;
	const int jump = 4;
	const int timeout = 30;
	static unsigned int rot = 64;
	static player_state player_S= FALL;	
	
	switch(player_S)
	{
		case JUMP:
			if(player.y < (127 - jumpmp)) player.y += jumpmp; //max height
			else player.y = 127;
			//rotating
			if(rot <= (unsigned int)(64-jump)) rot += (unsigned int)jump;
			Rot_VL_Mode(rot,&vectors_player,&vectors_player_ram);
			
			player.jump--;
			if(player.jump == 0) player_S = FALL;
			break;
			
		case TIMEOUT:
			if( 0 == player.timeout ) player.timeout = timeout;
			player.timeout--;
			break;
			
		case FALL:
			if(player.y > -127) player.y -= speed; //gravity, hitting floor -> dead
			else player.status = DEAD; 
			//rotating
			if(rot > 54) rot -= 1;
			Rot_VL_Mode(rot,&vectors_player,&vectors_player_ram);
			//jump input
			check_joysticks();
			if (joystick_1_up())
			{
				player_S = JUMP;
				player.jump = jump;
			}
			break;
			
		default:
			break;
	}
}

// ---------------------------------------------------------------------------

void handle_player(void)
{
	move_player();
	draw_player();

	if (player.status == DEAD)
	{
		current_level.status = LEVEL_LOST;
	}
}

// ***************************************************************************
// end of file
// ***************************************************************************

