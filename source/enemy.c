// ***************************************************************************
// enemy
// ***************************************************************************

#include <vectrex.h>
#include "utils/sound.h"
#include "utils/utils.h"
#include "utils/vector.h"
#include "enemy.h"
#include "player.h"
#include "game.h"
#include "object.h"
#include "level.h"
#include "utils/math.h"

// ---------------------------------------------------------------------------

#undef SF
#define SF 1

#define DRAWING_SPEED 0x7f

struct object_t obstacles[OBSTACLES_COUNT];

struct packet_t vectors_obstacles[] =
{
	{DRAW, { -4 * SF, 0 * SF}},
	{MOVE, { 0, 0}},
	{DRAW, {  0 * SF, 10 * SF}}, //width
	{DRAW, {  4 * SF,  0 * SF}},
	{MOVE, { 0, 0}},
	{STOP, { 0, 0}},
};

// ---------------------------------------------------------------------------

void draw_enemy(struct object_t* p)
{		
	long int temp = 0;
	Reset0Ref();				// reset beam to center of screen
	//TOP
	dp_VIA_t1_cnt_lo = 0x7f;	// set scaling factor for positioning
	Moveto_d(127, p->x);		// move beam to object coordinates
	dp_VIA_t1_cnt_lo = DRAWING_SPEED;	// set scalinf factor for drawing
	//calculate vectors
	temp = (127 - (long int)p->pos);
	if(temp > 127)
	{
		temp -= 127;
		vectors_obstacles[1] = (struct packet_t){DRAW,{ -(int)(temp) * SF, 0}};
		vectors_obstacles[4] = (struct packet_t){DRAW,{ (int)(temp) * SF, 0}};
		temp = 127;
	}
	else 
	{
		vectors_obstacles[1] = (struct packet_t) {MOVE, { 0, 0}};
		vectors_obstacles[4] = (struct packet_t) {MOVE, { 0, 0}};
	}
	vectors_obstacles[0] = (struct packet_t){DRAW, { -(int)temp * SF, 0}}; //left top corner
	vectors_obstacles[3] = (struct packet_t){DRAW,{ (int)temp * SF, 0}};
	Draw_VLp(&vectors_obstacles);	// draw vector list
	
	//BOTTOM
	Reset0Ref();				// reset beam to center of screen
	dp_VIA_t1_cnt_lo = 0x7f;	// set scaling factor for positioning
	Moveto_d(-128, p->x);		// move beam to object coordinates
	dp_VIA_t1_cnt_lo = DRAWING_SPEED;	// set scalinf factor for drawing
	//calculate vectors
	temp = ((long int)p->pos + (127 - (level_const.hole_heigth_half << 1)));
	if(temp > 127)
	{
		temp -= 127;
		vectors_obstacles[1] = (struct packet_t){DRAW,{ (int)(temp) * SF, 0}};
		vectors_obstacles[4] = (struct packet_t){DRAW,{ -(int)(temp) * SF, 0}};
		temp = 127;
	}
	else 
	{
		vectors_obstacles[1] = (struct packet_t) {MOVE, { 0, 0}};
		vectors_obstacles[4] = (struct packet_t) {MOVE, { 0, 0}};
	}
	vectors_obstacles[0] = (struct packet_t){DRAW,{ (int)temp * SF, 0}}; //left top corner
	vectors_obstacles[3] = (struct packet_t){DRAW,{ -(int)temp * SF, 0}};
	Draw_VLp(&vectors_obstacles);	// draw vector list
}

// ---------------------------------------------------------------------------

void handle_enemies(void)
{
	int i;
	//create new obstacle if time to do so
	if(level_const.pipe_space_count-- == 0)
	{
		level_const.pipe_space_count = level_const.pipe_space;
		if(level_const.end != 0)
		{
			obstacles[level_const.obstacles_iterator].activ = 0;
			if(level_const.obstacles_iterator-- == 0) level_const.obstacles_iterator = level_const.obstacles_count - 1;			
		}
		else
		{
			init_object(&obstacles[level_const.obstacles_iterator]);
			if(level_const.obstacles_iterator-- == 0) level_const.obstacles_iterator = level_const.obstacles_count - 1;
		}
	}
			
	//handle all obstacles	
	for( i = 0; i < level_const.obstacles_count; i++)
	{ 
		if(obstacles[i].activ)
		{
			move_object(&obstacles[i]);
			draw_enemy(&obstacles[i]);
			if (check_collision(player.y, &obstacles[i]))
			{
			    play_explosion(&bang);
				player.status = DEAD;
			}
		}
	}
}

// ***************************************************************************
// end of file
// ***************************************************************************

