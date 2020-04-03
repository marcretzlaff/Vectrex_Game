// ***************************************************************************
// game
// ***************************************************************************

#pragma once

// ---------------------------------------------------------------------------

struct game_t
{
	unsigned int option_players;
	unsigned int option_mode;
	unsigned int lives;
	unsigned int level;
	unsigned int score;
	unsigned int player;
	unsigned int frame;
};

// ---------------------------------------------------------------------------

extern struct game_t current_game;

// ---------------------------------------------------------------------------

int game(void);

void game_init(void);
void game_play(void);
void game_over(void);

// ***************************************************************************
// end of file
// ***************************************************************************
