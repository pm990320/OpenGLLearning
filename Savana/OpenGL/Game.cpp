#include "Game.h"
using namespace Sprites;
using namespace Game;

Game::State Game::state = Game::State::IN_GAME;
short Game::LEVEL = 1;

bool Game::won() {
	if (state == State::IN_GAME) {
		if (player.sprite.getPosition().x >= Misc::MyWindow.WIDTH) {
			return true;
		}
	}
	if (state == State::WON) { 
		return true;
	}
	return false;
}

bool Game::lost() {
	if (state == State::IN_GAME) {
		for (auto& hyena : hyenas){
			sf::Vector2f h = hyena.sprite.getPosition();
			sf::Vector2f p = player.sprite.getPosition();

			if ((p.x > h.x - player.width) && (p.x < h.x + hyena.width) && (p.y > h.y - player.height) && (p.y < h.y + hyena.height)) { return true; }
		}
	}
	if (state == State::LOST) return true;
	return false;
}

void Game::render_ingame() {
	using Misc::MyWindow;
	MyWindow.window.draw(background.sprite);
	MyWindow.window.draw(player.sprite);
	for (auto& x : hyenas) {
		MyWindow.window.draw(x.sprite);
	}
	MyWindow.window.draw(timer.time);
	MyWindow.window.draw(timer.outside);
}

void Game::render_lost() {
	using Misc::MyWindow;
	MyWindow.window.draw(background.sprite);
	MyWindow.window.draw(lostgame.endgame);
	MyWindow.window.draw(lostgame.msg);
}


void Game::render_won() {
	using Misc::MyWindow;
	MyWindow.window.draw(background.sprite);
	MyWindow.window.draw(wongame.wongame);
	MyWindow.window.draw(wongame.msg);
}

void Game::render() {
	switch (state) {
		case State::IN_GAME:
			render_ingame();
			break;
		case State::WON:
			render_won();
			break;
		case State::LOST:
			render_lost();
	}
}

void Game::state_update() {
	player.move();
	for (auto& x : hyenas) {
		x.move();
	}
	timer.update();

	if (lost()) {
		state = State::LOST;
	}
	if (won()) {
		state = State::WON;
		LEVEL += 1;
	}

	render();
}

void Game::state_reset_ingame(){
	if (state != State::IN_GAME) { 
		if (state == State::WON && Game::LEVEL > hyenas.size()) {
			hyenas.push_back(Hyena());
		}
		reset_hyenas();
		player.reset_pos();
		player.reset_movstate();
		timer.reset();
		
		state = State::IN_GAME;
	}
}

void Game::init() {
	reset_hyenas();
}