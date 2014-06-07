#include "Sprites.h"
#include "Game.h"
#include "Misc.h"
#include <sstream>
#include <exception>
#include <vector>
#include <iostream>

using namespace Sprites;
using Misc::MyWindow;

/* BACKGROUND CLASS */

Background::Background() {
	if (!texture.loadFromFile("textures/savanna2_large.jpg", sf::IntRect(0, 0, MyWindow.WIDTH, MyWindow.HEIGHT))) {
		throw std::runtime_error{ "Background: savanna2_large.jpg. " };
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(1.2, 1);
}

/* LOSTGAME CLASS */

LostGame::LostGame() {
	if (!cool.loadFromFile("fonts/INK2SCRI.ttf")) {
		throw std::runtime_error{ "LostGame INK2SCRI.ttf. " };
	}
	endgame.setFont(cool);
	endgame.setString("The End");
	endgame.setCharacterSize(MyWindow.HEIGHT / 3);
	endgame.setPosition(MyWindow.WIDTH / 4, MyWindow.HEIGHT / 4);
	endgame.setRotation(-10);
	endgame.setColor(sf::Color::Red);

	if (!plain.loadFromFile("fonts/corbel.ttf")) {
		throw std::runtime_error{ "LostGame: corbel.ttf. " };
	}
	msg.setFont(plain);
	msg.setString("Press space to play again...");
	msg.setCharacterSize(70);
	msg.setPosition(endgame.getPosition().x, endgame.getPosition().y * 3);
	msg.setRotation(0);
	msg.setColor(sf::Color::White);
}

/* WONGAME CLASS */

WonGame::WonGame() {
	if (!cool.loadFromFile("fonts/INK2SCRI.ttf")) {
		throw std::runtime_error{ "WonGame: INK2SCRI.ttf. " };
	}
	wongame.setFont(cool);
	wongame.setString("Well Done!");
	wongame.setCharacterSize(MyWindow.HEIGHT / 3);
	wongame.setPosition(MyWindow.WIDTH / 4, MyWindow.HEIGHT / 4);
	wongame.setRotation(-10);
	wongame.setColor(sf::Color::Yellow);

	if (!plain.loadFromFile("fonts/corbel.ttf")) {
		throw std::runtime_error{ "WonGame: corbel.ttf." };
	}
	msg.setFont(plain);
	msg.setString("Press space to play again...");
	msg.setCharacterSize(70);
	msg.setPosition(wongame.getPosition().x, wongame.getPosition().y * 3);
	msg.setRotation(0);
	msg.setColor(sf::Color::White);
}

/* TIMER CLASS */

Timer::Timer() {
	if (!plain.loadFromFile("fonts/corbel.ttf")) {
		throw std::runtime_error{ "Timer: corbel.ttf" };
	}
	time.setFont(plain);
	time.setCharacterSize(50);
	time.setPosition(30, 25);
	time.setRotation(0);
	time.setColor(sf::Color::Magenta);

	std::ostringstream s;
	s << seconds_rem;
	time.setString(std::string(s.str()));

	outside.setRadius(50);
	outside.setOrigin(0, 0);
	outside.setPosition(5, 5);
	outside.setFillColor(sf::Color::Transparent);
	outside.setOutlineColor(sf::Color::Magenta);
	outside.setOutlineThickness(5);
}

void Timer::update() {
	sf::Time t = c.getElapsedTime();
	if (t.asMilliseconds() >= 1000) {
		--seconds_rem;

		std::ostringstream s;
		s << seconds_rem;
		time.setString(std::string(s.str()));
		c.restart();
	}

	if (seconds_rem == 0) {
		Game::state = Game::State::LOST;
	}
}

void Timer::reset() {
	c.restart();
	seconds_rem = reset_val;
}

/* PLAYER CLASS */

void Player::reset_movstate() {
	left = false;
	right = false;
	up = false;
	down = false;
}

void Player::reset_pos() {
	sprite.setPosition(sf::Vector2f(30, 200));
}

Player::Player() {
	// load image to texture
	if (!texture.loadFromFile("textures/pumba.png", sf::IntRect(0, 0, width, height))) {
		std::runtime_error{ "Player: pumba.png" };
	}

	// smooth texture
	texture.setSmooth(true);

	// set sprite texture
	sprite.setTexture(texture);

	// set sprite to starting position
	reset_pos();
}

void Player::go_left() {
	left = true;
}

void Player::go_right() {
	right = true;
}
void Player::go_up() {
	up = true;
}
void Player::go_down() {
	down = true;
}

void Player::move() {
	//get current position
	sf::Vector2f curr = sprite.getPosition();

	//check for edge bounce
	if (curr.x <= 0)											left = false;
	if (curr.y <= 0)											up = false;
	/* no need for R because it is allowed to go off to the right (to win the game) */
	if (curr.y >= (Misc::MyWindow.HEIGHT - height))				down = false;

	//move if instructed
	if (left)         curr.x -= MOVE_VAL;
	if (right)        curr.x += MOVE_VAL;
	if (up)           curr.y -= MOVE_VAL;
	if (down)         curr.y += MOVE_VAL;

	sprite.setPosition(curr);

	reset_movstate();
}

/* HYENA CLASS */

void Hyena::reset_pos() {
	sprite.setPosition(start_pos);
}

void Hyena::move() {
	sf::Vector2f P = player.sprite.getPosition();
	sf::Vector2f H = sprite.getPosition();

	float x_middle_P = P.x + (player.width / 2);
	float y_middle_P = P.y + (player.height / 2);
	float x_middle_H = H.x + (width / 2);
	float y_middle_H = H.y + (height / 2);

	if ((x_middle_P < x_middle_H - tol) && (y_middle_P < y_middle_H - tol)) { left = true; up = true; }			// top left
	if ((x_middle_P > x_middle_H + tol) && (y_middle_P < y_middle_H + tol)) { right = true; up = true; }		// top right
	if ((x_middle_P < x_middle_H - tol) && (y_middle_P > y_middle_H - tol)) { left = true; down = true; }		// bottom left
	if ((x_middle_P > x_middle_H + tol) && (y_middle_P > y_middle_H + tol)) { right = true; down = true; }		// bottom right

	if ((x_middle_P > x_middle_H - tol) && (x_middle_P < x_middle_H + tol)) { left = false; right = false; }	// if either directly above or directly below
	if ((y_middle_P > y_middle_H - tol) && (y_middle_P < y_middle_H + tol)) { up = false; down = false; }		// if either directly left or directly right

	if (H.x <= 0)	left = false;
	if (H.y <= 0)	up   = false;
	if (H.x >= Misc::MyWindow.WIDTH - width)		right = false;
	if (H.y >= Misc::MyWindow.HEIGHT - height)		down  = false;

	if (left)	{ sprite.move(0 - moveby_x, 0); }
	if (right)	{ sprite.move(moveby_x, 0); }
	if (up)		{ sprite.move(0, 0 - moveby_y); }
	if (down)	{ sprite.move(0, moveby_y); }

	left = right = up = down = false;
}

Hyena::Hyena() {
#ifndef HYENA_TEX
#define HYENA_TEX
	if (!hyena_tex.loadFromFile("textures/hyena.png", sf::IntRect(0, 0, width, height))) {
		throw std::runtime_error{ "Hyena: hyena.png" };
	}
	hyena_tex.setSmooth(true);
#endif

	sprite.setTexture(hyena_tex);

	start_pos = pos.next_pos();
	reset_pos();
}

/* HYENA OTHER */

sf::Texture Sprites::hyena_tex;

sf::Vector2f HyenaPos::next_pos() {
	return sf::Vector2f(x(gen), y(gen));
}

HyenaPos Sprites::pos;

std::vector<Hyena> Sprites::hyenas{ Hyena() };

void Sprites::reset_hyenas() {
	using Sprites::hyenas;

	for (Hyena& x : hyenas) {
		x.reset_pos();
	}
}

Player Sprites::player;
Background Sprites::background;
LostGame Sprites::lostgame;
WonGame Sprites::wongame;
Timer Sprites::timer;