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
	Window window;
	//setup
	Cam::Camera camera{ window.window };
	Pyramid pyramid{ window, camera };
	ShapeContainer shapes;
	shapes.addShape(pyramid);

	// main loop
	bool running = true;
	while (running) {
		sf::Event e;
		while (window.window.pollEvent(e)) {
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

		window.gl.Clear().ColorBuffer().DepthBuffer();

		//update
		camera.move_with_mouse();
		shapes.updateShapes();

		//draw
		shapes.drawShapes();
		window.window.display();

		sf::Mouse::setPosition(sf::Vector2i(window.window.getSize().x / 2, window.window.getSize().y / 2), window.window);
	}

	return 0;
}
