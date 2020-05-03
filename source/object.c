// ***************************************************************************
// object
// ***************************************************************************

#include <vectrex.h>
#include "level.h"
#include "object.h"
#include "game.h"

// ---------------------------------------------------------------------------
int oldrand = 0;
	
void init_object(struct object_t* p)
{
	long int rand;
	//random new hole to fly through
	rand =  (int) Random();
	rand = rand % 50;
	rand = oldrand + rand;
	
	if(rand > 85)
		p->pos = 120;
	else if(rand < -95)
			p->pos = -60;
	else
		p->pos = (int)rand + 35;
	p->x = 120; //appears from right side of screen 110
	p->activ = 1;
}
// ---------------------------------------------------------------------------

void move_object(struct object_t* p)
{
	(p->x)--;
	if( p->x == -90)
		current_game.score++;
}

// ---------------------------------------------------------------------------
// obstacles x -> | left border of it
int check_collision(int y0, struct object_t* ob)
{
	int hit = 0;
	
	if( (ob->x < -95) && (ob->x > -105) ) //x-plane violation width 10 
	{
		if(!( ((y0 - 7) >  (ob->pos - 70)) && ((y0 + 7) < ob->pos) )) hit = 1; //y-plane violation 
	}
	return hit;
}

// ***************************************************************************
// end of file
// ***************************************************************************

