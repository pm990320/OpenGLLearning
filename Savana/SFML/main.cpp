#include <SFML/Graphics.hpp>
#include "Misc.h"
#include "Game.h"
#include "Sprites.h"

#include <iostream>
#include <Windows.h>

int main(int argc, char* argv) {
	// DEBUGGING
	std::cout << argv[1];

	// initialse
	Game::init();

	// game loop
	while (Misc::MyWindow.window.isOpen()){
		// event handling
		sf::Event evt;
		while (Misc::MyWindow.window.pollEvent(evt)) {
			Misc::event_handler(evt);
		}

		//update
		Misc::MyWindow.window.clear(sf::Color::Black);

		Game::state_update();

		Misc::MyWindow.window.display();
	}

	// terminate
	return 0;
}