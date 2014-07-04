#ifndef GAME_HEADER
#define GAME_HEADER

#include <SFML/Graphics.hpp>
#include "Sprites.h"
#include "Misc.h"

namespace Game {
	enum class State { IN_GAME, LOST, WON };

	extern State state;

	extern short LEVEL;

	extern bool won();
	extern bool lost();

	extern void render();

	extern void render_ingame();
	extern void render_lost();
	extern void render_won();

	extern void state_update();

	extern void init();

	extern void state_reset_ingame();
}

#endif