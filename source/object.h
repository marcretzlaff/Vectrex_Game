// ***************************************************************************
// object
// ***************************************************************************

#pragma once
#include <vectrex.h>

// ---------------------------------------------------------------------------

struct object_t
{
	int x;					// x coordinate byte
	int top;					// delta y byte
	int bottom;					// delta x byte
};

// ---------------------------------------------------------------------------
//player y, obstacle pointer
int check_collision(int y0, struct object_t* ob);
void init_object(struct object_t* p);
void move_object(struct object_t* p);

// ***************************************************************************
// end of file
// ***************************************************************************
