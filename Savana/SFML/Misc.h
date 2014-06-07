#ifndef MISC_HEADER
#define MISC_HEADER

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace Misc {
	class Window {
	private:
		sf::ContextSettings settings;
	public:
		int WIDTH = 1920;
		int HEIGHT = 1080;
		sf::RenderWindow window{ sf::VideoMode(WIDTH, HEIGHT), "Animals Game", sf::Style::Fullscreen, settings };

		Window() {
			window.setFramerateLimit(30);
			window.setMouseCursorVisible(false);
			window.setKeyRepeatEnabled(true);
			window.setVerticalSyncEnabled(true);
		}
	};

	extern Window MyWindow;

	extern void event_handler(sf::Event& e);

	class Audio {
	private:
		sf::Music music;
		sf::SoundBuffer woohoo;
		sf::Sound whoop;
	public:
		Audio();
		void play_music();
		void play_cheer();
	};

	extern Audio audio;
}

#endif