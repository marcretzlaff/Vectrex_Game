// ***************************************************************************
// player
// ***************************************************************************

#include <vectrex.h>
#include "utils/controller.h"
#include "utils/utils.h"
#include "utils/vector.h"
#include "utils/sound.h"
#include "game.h"
#include "level.h"
#include "player.h"


// ---------------------------------------------------------------------------
const struct sound_music_t bing = 
{
	.adsr_table = (struct sound_adsr_table_t*) &Vec_ADSR_FADE8,
	.twang_table = (struct sound_twang_table_t*) &Vec_TWANG_VIBE0,
	{
		0, 16,
		0, 128
	}
};

struct player_t player =
{
	.status = DEAD,
	.y = 0,
	.x = 0,
	.timeout = 0,
	.jump = 0
};
int speed = 1;

// ---------------------------------------------------------------------------

#undef SF
#define SF 20


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


struct packet_t vectors_player_ram[sizeof(vectors_player) / sizeof(struct packet_t)];

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
	player.x = -90;
	player.timeout = 0;
	player.jump = 0;
	player.player_S = INIT_FALL;
}


// ---------------------------------------------------------------------------

void move_player(void)
{
	const int jumpmp = 6;
	const int jump = 5;
	const int timeout = 5;
	static unsigned int rot = 64;
	
	switch(player.player_S)
	{
		case JUMP:
			if(player.y < (127 - jumpmp)) player.y += jumpmp; //max height
			else player.y = 127;
			//rotating
			if(rot <= (unsigned int)(64-jump)) rot += (unsigned int)jump;
			Rot_VL_Mode(rot,&vectors_player,&vectors_player_ram);
			
			player.jump--;
			if(player.jump == 0) player.player_S = INIT_TIMEOUT;
			break;
			
		case INIT_TIMEOUT:
			player.timeout = timeout;
			player.player_S = TIMEOUT;
			break;	
				
		case TIMEOUT:
			player.timeout--;
			if(!(player.y < -127)) 
			{
				player.y -= 1;
			} else player.status = DEAD;
			if(!player.timeout) player.player_S = INIT_FALL;
			break;
			
		case INIT_FALL:
			speed = 1;
			player.player_S = FALL;
			break;
		
		case FALL:
			if(!((long int)player.y - speed < -128)) 
			{
				player.y -= speed; //gravity, hitting floor -> dead
				if ((current_level.frame % 10) == 0) speed += 1;
			} else player.status = DEAD;
			
			
			//rotating
			if( (current_level.frame % 3) == 0 )
			{
				if(rot > 54) rot -= 1;
				Rot_VL_Mode(rot,&vectors_player,&vectors_player_ram);
			}
			//jump input
			check_joysticks();
			if (joystick_1_up())
			{
				play_music(&bing);
				player.player_S = JUMP;
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
		player.player_S = INIT_FALL;
	}
}

// ***************************************************************************
// end of file
// ***************************************************************************

