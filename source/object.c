// ***************************************************************************
// object
// ***************************************************************************

#include <vectrex.h>
#include "level.h"
#include "object.h"

// ---------------------------------------------------------------------------

void init_object(struct object_t* p)
{
	int rand;
	//random new hole to fly through
	rand = (int) (Random() & 0b01111111);
	if(rand > 100 )p->top = 127;
	if(rand < -100 )p->bottom = -128;else p->bottom = rand - 25;
	p->bottom = rand - 25;
	p->x = 120; //appears from right side of screen
}
// ---------------------------------------------------------------------------

void move_object(struct object_t* p)
{
	if (current_level.frame != 0)
	{
		(p->x)--;
	}
}

// ---------------------------------------------------------------------------
// obstacles x -> | left border of it
int check_collision(int y0, struct object_t* ob)
{
	int hit = 0;
	
	if( (ob->x < -95) && (ob->x > -105) ) //x-plane violation
	{
		if( ((y0 + 7) < ob->top) && ((y0 - 7) > ob->bottom) ) hit = 1; //y-plane violation 
	}
	return (int)hit;
}

// ***************************************************************************
// end of file
// ***************************************************************************

