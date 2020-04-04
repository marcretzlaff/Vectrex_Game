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

#define OBSTACLES_COUNT 3
struct object_t obstacles[OBSTACLES_COUNT];

struct packet_t vectors_obstacles[] =
{
	{DRAW, { -4 * SF, 0 * SF}},
	{DRAW, {  0 * SF, 10 * SF}}, //width
	{DRAW, {  4 * SF,  0 * SF}},
	{STOP, { 0, 0}},
};

// ---------------------------------------------------------------------------

void draw_enemy(struct object_t* p)
{		
	int temp = 0;
	Reset0Ref();				// reset beam to center of screen
	//TOP
	dp_VIA_t1_cnt_lo = 0x7f;	// set scaling factor for positioning
	Moveto_d(127, p->x);		// move beam to object coordinates
	dp_VIA_t1_cnt_lo = DRAWING_SPEED;	// set scalinf factor for drawing
	//calculate vectors
	temp = (127 - p->top) >> 1; // /2 due max 127 range of line -> 127 full screen heigth
	vectors_obstacles[0] = (struct packet_t){DRAW, { -temp * SF, 0}}; //left top corner
	vectors_obstacles[2] = (struct packet_t){DRAW,{ temp * SF, 0}};
	Draw_VLp(&vectors_obstacles);	// draw vector list
	
	//BOTTOM
	Reset0Ref();				// reset beam to center of screen
	dp_VIA_t1_cnt_lo = 0x7f;	// set scaling factor for positioning
	Moveto_d(-128, p->x);		// move beam to object coordinates
	dp_VIA_t1_cnt_lo = DRAWING_SPEED;	// set scalinf factor for drawing
	//calculate vectors
	temp = (p->top + 77) >> 1; //-50 + 127
	vectors_obstacles[0] = (struct packet_t){DRAW, { temp * SF, 0}}; //left top corner
	vectors_obstacles[2] = (struct packet_t){DRAW,{ -temp * SF, 0}};
	Draw_VLp(&vectors_obstacles);	// draw vector list
}

// ---------------------------------------------------------------------------

void handle_enemies(void)
{
	static unsigned int iterator = 0;
	
	//create new obstacle if time to do so
	if((current_level.frame % 70) == 0)
	{
		init_object(&obstacles[iterator]);
		if(--iterator == 0) iterator = OBSTACLES_COUNT - 1;
	}
	//handle all obstacles	
	for( i = 0; i<OBSTACLES_COUNT; i++)
	{
		if(obstacles[i].activ)
		{
			move_object(&obstacles[i]);
			draw_enemy(&obstacles[i]);

			if (check_collision(player.y, &obstacles[i]))
			{
				player.status = DEAD;
			}
		}
	}
	*/
}

// ***************************************************************************
// end of file
// ***************************************************************************

