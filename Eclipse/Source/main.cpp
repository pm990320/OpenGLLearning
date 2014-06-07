/*
 * main.cpp
 *
 *  Created on: 31 May 2014
 *      Author: Patrick
 */
#include <glm/gtc/matrix_transform.inl>
#include <GL/glew.h>
#include <oglplus/gl.hpp>
#include <oglplus/all.hpp>
#include <oglplus/shader.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <ctime>
#include <iostream>
#include "Camera.h"
#include "Pyramid.h"

using namespace oglplus;
using Camera::camera;

int main() {
	sf::ContextSettings set;
	set.antialiasingLevel = 8;
	sf::Window w(sf::VideoMode(700, 700), "ogl", sf::Style::Default, set);
	glewExperimental = true;
	glewInit();
	Context gl;
	gl.ClearColor(0.0, 0.0, 0.0, 1.0);
	gl.Enable(Capability::DepthTest);
	gl.Enable(Capability::CullFace);
	gl.Enable(Capability::Blend);
	w.setMouseCursorVisible(false);

	Pyramid pyramid { w };

	bool running = true;
	while(running) {
		sf::Event e;
		while(w.pollEvent(e)){
			if(e.type == sf::Event::Closed){ running = false; }
			if(e.type == sf::Event::KeyPressed) {
				switch(e.key.code) {
				case sf::Keyboard::Escape:
					running = false;
					break;
				case sf::Keyboard::W: case sf::Keyboard::Up:
					camera.forward();
					break;
				case sf::Keyboard::A: case sf::Keyboard::Left:
					camera.left();
					break;
				case sf::Keyboard::S: case sf::Keyboard::Down:
					camera.back();
					break;
				case sf::Keyboard::D: case sf::Keyboard::Right:
					camera.right();
					break;
				default:
					break;
				}
				}
			if(e.type == sf::Event::MouseMoved) {
					//idk
			}
		}

		pyramid.update();
		pyramid.draw(gl);
		gl.Clear().ColorBuffer().DepthBuffer();
		w.display();
	}
	return 0;
}
