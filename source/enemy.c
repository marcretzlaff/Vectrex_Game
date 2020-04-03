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

// ---------------------------------------------------------------------------

#undef SF
#define SF 16

#define OBSTACLES_COUNT 6
struct object_t obstacles[OBSTACLES_COUNT];

struct packet_t vectors_top[] =
{
	{DRAW, { -4 * SF, 0 * SF}},
	{DRAW, {  0 * SF, -1 * SF}},
	{DRAW, {  4 * SF,  0 * SF}},
	{STOP, { 0, 0}},
};

struct packet_t vectors_bottom[] =
{
	{DRAW, {  4 * SF,  0 * SF}},
	{DRAW, {  0 * SF, -1 * SF}},
	{DRAW, { -4 * SF,  0 * SF}},
	{STOP, { 0, 0}},
};

// ---------------------------------------------------------------------------

void draw_enemy(struct object_t* p)
{
	Reset0Ref();				// reset beam to center of screen
	//TOP
	dp_VIA_t1_cnt_lo = 0x7f;	// set scaling factor for positioning
	Moveto_d(127, p->x);		// move beam to object coordinates
	dp_VIA_t1_cnt_lo = 0x5E;	// set scalinf factor for drawing
	Draw_VLp(&vectors_top);	// draw vector list
	//BOTTOM
	dp_VIA_t1_cnt_lo = 0x7f;	// set scaling factor for positioning
	Moveto_d(-128, p->x);		// move beam to object coordinates
	Draw_VLp(&vectors_bottom);	// draw vector list
}

// ---------------------------------------------------------------------------

void handle_enemies(void)
{
	static unsigned int iterator = 0;
	unsigned int i = 0;
	
	//create new obstacle if time to do so
	if((current_game.frame % 20) == 0)
	{
		init_object(&obstacles[iterator]);
		if(++iterator > OBSTACLES_COUNT) iterator = 0;
	}
	//handle all obstacles	
	for( i = 0; i<OBSTACLES_COUNT; i++)
	{
		move_object(&obstacles[i]);
		draw_enemy(&obstacles[i]);
		if (check_collision(player.y, &obstacles[i]))
		{
			player.status = DEAD;
		}
	}
}

// ***************************************************************************
// end of file
// ***************************************************************************

