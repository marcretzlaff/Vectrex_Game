// ***************************************************************************
// random - simple pseudo random number generator (rng)
// ***************************************************************************

#include <vectrex.h>
#include "random.h"

// ---------------------------------------------------------------------------

struct rng_t my_rng = { .a = 0, .b = 0, .c = 0, .x = 0 };

// ---------------------------------------------------------------------------
 
void init_my_rng(unsigned int seed_1,unsigned int seed_2, unsigned int seed_3)
{
	//XOR new entropy into key state
	my_rng.a = 0 ^ seed_1;
	my_rng.b = 0 ^ seed_2;
	my_rng.c = 0 ^ seed_3;

	my_rng.x = 1;
	my_rng.a = (my_rng.a ^ my_rng.c ^ my_rng.x);
	my_rng.b = (my_rng.b + my_rng.a);
	my_rng.c = ((my_rng.c + (my_rng.b >> 1)) ^ my_rng.a);
}

// ---------------------------------------------------------------------------

unsigned int my_random(void)
{
	my_rng.x++;               								//x is incremented every round and is not affected by any other variable
	my_rng.a = (my_rng.a ^ my_rng.c ^ my_rng.x);			//note the mix of addition and XOR
	my_rng.b = (my_rng.b + my_rng.a);         				//and the use of very few instructions
	my_rng.c = ((my_rng.c + (my_rng.b >> 1)) ^ my_rng.a);	//the right shift is to ensure that high-order bits from b can affect  
	return my_rng.c;          								//low order bits of other variables
}

// ***************************************************************************
// end of file
// ***************************************************************************
