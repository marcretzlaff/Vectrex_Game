// ***************************************************************************
// level
// ***************************************************************************

#pragma once

// ---------------------------------------------------------------------------
#define OBSTACLES_COUNT 6 //max or screen size, used for allocation, only obstacles_count will be used

struct s_level_const 
{
	//player.c
	int jumpmp;
	int jump;
	int timeout;
	int speed;
	int count_fall;
	int count_rot;
	
	//enemy.c
	unsigned int pipe_space;
	unsigned int pipe_space_count;
	int obstacles_iterator;
	int obstacles_count;


	//object.c
	int hole_heigth_half;
	int max_next_pipe_rand;
	
	//level change
	unsigned int end;
};

// ---------------------------------------------------------------------------

enum level_status_t
{
	LEVEL_PLAY,
	LEVEL_LOST,
	LEVEL_WON,
};

// ---------------------------------------------------------------------------

struct level_t
{
	enum level_status_t status;
};

// ---------------------------------------------------------------------------

extern struct level_t current_level;
extern struct s_level_const level_const;

// ---------------------------------------------------------------------------

void level_init(void);
void level_play(void);

// ***************************************************************************
// end of file
// ***************************************************************************
