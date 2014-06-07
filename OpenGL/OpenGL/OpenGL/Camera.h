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
using namespace oglplus;

namespace Camera {
class Camera {
	Vec3f position;
	Vec3f viewDirection;
	Vec2f oldMousePosition;
public:
	Camera();
	Mat4f getWorldToViewMatrix();
	void move_with_mouse(sf::Window& w);
	void forward();
	void back();
	void left();
	void right();
};
}

extern Camera::Camera camera;