//#include <GL\glew.h>
#include <SFML/Window.hpp>
#include <oglplus/gl.hpp>
#include <oglplus/all.hpp>
#include <oglplus/site_config.hpp>
#include "Camera.h"
#include "Pyramid.h"
using namespace oglplus;

int main() {
	// initialise context
	sf::ContextSettings set;
	sf::Window window{ sf::VideoMode(640, 480), "OpenGL", sf::Style::Fullscreen, set};
	glewInit();
	Context gl;

	//setup
	Pyramid pyramid { window };

	// main loop
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			switch (e.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (e.key.code) {
				case sf::Keyboard::Escape:
					window.close();
				}
			}
		}

		//update
		pyramid.update();

		//draw
		pyramid.draw(gl);
		window.display();
	}


	return 0;
}