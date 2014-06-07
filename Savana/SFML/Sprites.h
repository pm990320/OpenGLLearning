#ifndef SPRITES_HEADER
#define SPRITES_HEADER

#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
#include "Misc.h"

namespace Sprites {
	class Player {
	private:
		bool left	= false;
		bool right	= false;
		bool up		= false;
		bool down	= false;

		const float MOVE_VAL = 25.0f;
	public:
		sf::Sprite sprite;
		sf::Texture texture;

		const float width	= 308.0f;
		const float height	= 290.0f;

		Player();
		void reset_movstate();
		void reset_pos();
		void move();

		void go_left();
		void go_right();
		void go_up();
		void go_down();
	};

	extern Player player;

	/* ----------------------- */

	class Background {
	private:
		sf::Texture texture;
	public:
		sf::Sprite sprite;
		
		Background();
	};

	extern Background background;
	
	/* ----------------------- */

	class LostGame {
	private:
		sf::Font cool;
		sf::Font plain;
	public:
		sf::Text endgame;
		sf::Text msg;

		LostGame();
	};

	extern LostGame lostgame;

	/* ----------------------- */

	class WonGame {
	private:
		sf::Font cool;
		sf::Font plain;
	public:
		sf::Text wongame;
		sf::Text msg;

		WonGame();
	};

	extern WonGame wongame;

	/* ----------------------- */

	class Timer {
	private:
		const int reset_val = 20;
		int seconds_rem = reset_val;
		sf::Clock c;
		sf::Font plain;
	public:
		sf::Text time;
		sf::CircleShape outside;

		Timer();
		void update();
		void reset();
	};

	extern Timer timer;

	/* ----------------------- */

	extern sf::Texture hyena_tex;

	class Hyena {
	private:
		const short tol = 20;
		const float moveby_x = 1.5f;
		const float moveby_y = 1.5f;

		bool left = false;
		bool right = false;
		bool up = false;
		bool down = false;

		

	public:
		sf::Sprite sprite;
		sf::Vector2f start_pos;

		const float width	= 215.0f;
		const float height	= 235.0f;

		Hyena();
		Hyena operator=(Hyena& hyena) {
			return Hyena(hyena);
		}
		void move();
		void reset_pos();
	};

	class HyenaPos {
	public:
		time_t timer;
		std::default_random_engine gen;
		std::uniform_real_distribution<double> x{ Misc::MyWindow.WIDTH / 2, Misc::MyWindow.WIDTH - 215.0 };
		std::uniform_real_distribution<double> y{ 5.0, Misc::MyWindow.HEIGHT - 235.0 };

		sf::Vector2f next_pos();

		HyenaPos() {
			time(&timer);
			gen.seed(static_cast<double>(timer));
		}
	};
	extern HyenaPos pos;

	extern std::vector<Hyena> hyenas;
	extern void reset_hyenas();
}

#endif
