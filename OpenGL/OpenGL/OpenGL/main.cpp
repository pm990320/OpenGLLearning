#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <oglplus/gl.hpp>
#include <oglplus/all.hpp>
#include <oglplus/site_config.hpp>
#include "Camera.h"
#include "Pyramid.h"
#include "Window.h"
using namespace oglplus;

int main() {
	// initialise context
	sf::ContextSettings set;
	sf::Window window{ sf::VideoMode(640, 480), "OpenGL", sf::Style::Default, set};
	glewExperimental = true;
	glewInit();

	//setup
	Cam::Camera camera{ window };
	Pyramid pyramid { window, camera };

	// main loop
	bool running = true;
	while (running) {
		sf::Event e;
		while (window.pollEvent(e)) {
			switch (e.type) {
			case sf::Event::Closed:
				running = false;
				break;
			case sf::Event::KeyPressed:
				switch (e.key.code) {
				case sf::Keyboard::Escape:
					running = false;
					break;
				case sf::Keyboard::Left:
					camera.left();
					break;
				case sf::Keyboard::Up:
					camera.forward();
					break;
				case sf::Keyboard::Right:
					camera.right();
					break;
				case sf::Keyboard::Down:
					camera.back();
					break;
				}
			}
		}

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);

		//update
		camera.move_with_mouse();
		pyramid.update();

		//draw
		pyramid.draw();
		window.display();

		sf::Mouse::setPosition(sf::Vector2i( window.getSize().x / 2, window.getSize().y / 2), window);
	}

	return 0;
}