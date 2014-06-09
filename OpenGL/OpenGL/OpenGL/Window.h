#pragma once

#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <oglplus/all.hpp>
#include <oglplus/gl.hpp>
#include <oglplus/capability.hpp>

class Window {
	/* 
	 *	
	 */
	sf::ContextSettings set;
public:
	sf::Window window{ sf::VideoMode(640, 480), "OpenGL", sf::Style::Default, set };
	oglplus::Context gl;

	Window();
	inline float Width() {
		return window.getSize().x;
	}
	inline float Height() {
		return window.getSize().y;
	}
};