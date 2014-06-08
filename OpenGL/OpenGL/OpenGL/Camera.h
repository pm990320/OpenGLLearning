/*
 * Camera.h
 *
 *  Created on: 1 Jun 2014
 *      Author: Patrick
 */

#pragma once

#include <GL/glew.h>
#include <oglplus/all.hpp>
#include <oglplus/gl.hpp>
#include <SFML/Window.hpp>
#include "Window.h"
using namespace oglplus;

namespace Cam {
class Camera {
	Vec3f position;
	Vec3f viewDirection;
	Vec2f oldMousePosition;
	sf::Window& window;
public:
	Camera(sf::Window& w);
	Mat4f getWorldToViewMatrix();
	Mat4f getProjectionMatrix();
	void move_with_mouse();
	void forward();
	void back();
	void left();
	void right();
};
}
