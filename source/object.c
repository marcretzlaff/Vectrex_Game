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
	rand = (int) Random();
	if(rand > 85)
		p->top = 120;
	else if(rand < -95)
			p->top = -60;
	else
		p->top = rand + 35;
	p->x = 120; //appears from right side of screen 110
	p->activ = 1;
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
	
	if( (ob->x < -95) && (ob->x > -105) ) //x-plane violation width 10
	{
		if( ((y0 + 7) < ob->top) && ((y0 - 7) > (ob->top - 50)) ) hit = 1; //y-plane violation 
	}
	return (int)hit;
}

// ***************************************************************************
// end of file
// ***************************************************************************

