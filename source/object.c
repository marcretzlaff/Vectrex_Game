// ***************************************************************************
// object
// ***************************************************************************

#include <vectrex.h>
#include "level.h"
#include "object.h"
#include "game.h"
#include "utils/random.h"

// ---------------------------------------------------------------------------
int oldrand = 0;
	
void init_object(struct object_t* p)
{
	long int rand;
	//random new hole to fly through
	rand =  (int) my_random();
	rand = rand % level_const.max_next_pipe_rand;
	rand = oldrand + rand;
	
	if(rand > (120 - level_const.hole_heigth_half))
		p->pos = 120;
	else if(rand < -(120 - level_const.hole_heigth_half))
			p->pos = -(120 - (level_const.hole_heigth_half << 1));
	else
		p->pos = (int)rand + level_const.hole_heigth_half;
	p->x = 127; //appears from right side of screen 110
	p->activ = 1;
}
// ---------------------------------------------------------------------------

void move_object(struct object_t* p)
{
	(p->x)--;
	if( p->x == -90)
		if((current_game.score++ == (current_game.level * 10)) && (current_game.level != current_game.maxlevel)) //advance to next level, start level change 
			level_const.end = 255;	
}

// ---------------------------------------------------------------------------
// obstacles x -> | left border of it
int check_collision(int y0, struct object_t* ob)
{
	int hit = 0;
	
	if( (ob->x < -95) && (ob->x > -105) ) //x-plane violation width 10 
	{
		if(!( ((y0 - 10) >  (ob->pos - (level_const.hole_heigth_half << 1))) && ((y0 + 5) < ob->pos) )) hit = 1; //y-plane violation 
		// -10 bottom +5 top for smoother collison look
	}
	return hit;
}

// ***************************************************************************
// end of file
// ***************************************************************************

