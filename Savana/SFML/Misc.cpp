#include "Misc.h"
#include "Sprites.h"
#include "Game.h"
using namespace Misc;

Window Misc::MyWindow;

void Misc::event_handler(sf::Event& e){
	switch (e.type) {
		// close if close action detected
	case sf::Event::Closed:
		Misc::MyWindow.window.close();
		break;

		//handle key events
	case sf::Event::KeyPressed:
		switch (e.key.code) {
		case sf::Keyboard::Escape: case sf::Keyboard::Q:
			Misc::MyWindow.window.close();
			break;
		case sf::Keyboard::Space:
			Game::state_reset_ingame();
			break;
		case sf::Keyboard::Right: case sf::Keyboard::D: case sf::Keyboard::Numpad6:  case sf::Keyboard::Num6:
			Sprites::player.go_right();
			break;
		case sf::Keyboard::Left: case sf::Keyboard::A:  case sf::Keyboard::Numpad4:  case sf::Keyboard::Num4:
			Sprites::player.go_left();
			break;
		case sf::Keyboard::Up: case sf::Keyboard::W:  case sf::Keyboard::Numpad8:  case sf::Keyboard::Num8:
			Sprites::player.go_up();
			break;
		case sf::Keyboard::Down: case sf::Keyboard::S:  case sf::Keyboard::Numpad2:  case sf::Keyboard::Num2:
			Sprites::player.go_down();
			break;
		case sf::Keyboard::Numpad7: case sf::Keyboard::Num7:
			Sprites::player.go_up();
			Sprites::player.go_left();
			break;
		case sf::Keyboard::Numpad9: case sf::Keyboard::Num9:
			Sprites::player.go_up();
			Sprites::player.go_right();
			break;
		case sf::Keyboard::Numpad1: case sf::Keyboard::Num1:
			Sprites::player.go_down();
			Sprites::player.go_left();
			break;
		case sf::Keyboard::Numpad3: case sf::Keyboard::Num3:
			Sprites::player.go_down();
			Sprites::player.go_right();
			break;
		}
	}
}

Audio::Audio() {
	if (!music.openFromFile("sounds/lionking_it.wav")) {
		throw std::runtime_error{ "Audio: lionking_it.wav (music)" };
	}
	music.setAttenuation(60);
	music.setLoop(true);
	music.setMinDistance(10);
	music.setPlayingOffset(sf::seconds(17));
	music.setVolume(100);

	music.play();

	if (!woohoo.loadFromFile("sounds/trumpet.wav")) {
		throw std::runtime_error{ "Audio: trumpet.wav (soundbuffer)" };
	}
	whoop.setBuffer(woohoo);
	whoop.setLoop(false);
	whoop.setAttenuation(100);
	whoop.setPosition(0, 0, -100);
	whoop.setVolume(80);
	whoop.setRelativeToListener(true);
}

void Audio::play_music() {
	music.play();
}

void Audio::play_cheer() {
	whoop.play();
}

Audio Misc::audio;