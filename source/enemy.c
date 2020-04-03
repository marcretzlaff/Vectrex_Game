// ***************************************************************************
// enemy
// ***************************************************************************

#include <vectrex.h>
#include "utils/collision.h"
#include "utils/sound.h"
#include "utils/utils.h"
#include "utils/vector.h"
#include "enemy.h"
#include "player.h"

// ---------------------------------------------------------------------------

struct object_t enemies[] =
{
	{ .status = INACTIVE, .y = 0, .x = 0, .dy = 0, .dx = 0},
	{ .status = INACTIVE, .y = 0, .x = 0, .dy = 0, .dx = 0},
};

// ---------------------------------------------------------------------------

#undef SF
#define SF 16

const struct packet_t vectors_enemy[] =
{
	{MOVE, {  1 * SF, -1 * SF}},
	{DRAW, {  2 * SF,  1 * SF}},
	{DRAW, { -2 * SF,  1 * SF}},
	{DRAW, { -1 * SF,  2 * SF}},
	{DRAW, { -1 * SF, -2 * SF}},
	{DRAW, { -2 * SF, -1 * SF}},
	{DRAW, {  2 * SF, -1 * SF}},
	{DRAW, {  1 * SF, -2 * SF}},
	{DRAW, {  1 * SF,  2 * SF}},
	{STOP, { 0, 0}},
};

// ---------------------------------------------------------------------------

void draw_enemy(struct object_t* p)
{
	Reset0Ref();				// reset beam to center of screen
	dp_VIA_t1_cnt_lo = 0x7f;	// set scaling factor for positioning
	Moveto_d(p->y, p->x);		// move beam to object coordinates
	dp_VIA_t1_cnt_lo = 0x22;	// set scalinf factor for drawing
	Draw_VLp(&vectors_enemy);	// draw vector list
}

// ---------------------------------------------------------------------------

void check_enemy(struct object_t* p)
{
	if (check_collision(player.y, player.x, p->y, p->x, 8, 8))
	{
		player.status = DEAD;
	}
	p->status = DEAD;
}

// ---------------------------------------------------------------------------

void init_enemies(void)
{
	for (unsigned int i = 0; i < MAX_ENEMIES; ++i)
	{
		init_object(&enemies[i]);
	}
}
// ---------------------------------------------------------------------------

void handle_enemies(void)
{
	for (unsigned int i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i].status == ACTIVE)
		{
			move_object(&enemies[i]);
			draw_enemy(&enemies[i]);
			check_enemy(&enemies[i]);
		}
	}
}

// ***************************************************************************
// end of file
// ***************************************************************************

