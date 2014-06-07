/*
 *  Camera.cpp
 *
 *  Created on: 1 Jun 2014
 *      Author: Patrick
 */

#include "Camera.h"

namespace Camera {

Camera::Camera() : position{Vec3f(0, 0, 2)}, viewDirection{ Vec3f(0, 0, 0) },
	oldMousePosition{ Vec2f(700.0/2, 700.0/2) }
{}

Mat4f Camera::getWorldToViewMatrix() {
	return CamMatrixf::LookingAt(position, viewDirection, Vec3f(0, 1, 0));
}

void Camera::move_with_mouse(sf::Window& w){
	Vec2f newPos{ sf::Mouse::getPosition(w).x, -sf::Mouse::getPosition(w).y };
	Vec2f dPos = oldMousePosition - newPos;

	viewDirection = Rotate(
			Quaternion<float>(Vec3f(0, 1, 0), Degrees(dPos.x())),
			viewDirection);

	viewDirection = Rotate(
			Quaternion<float>(Vec3f(1, 0, 0), Degrees(dPos.y())),
			viewDirection);
	oldMousePosition = newPos;
}

void Camera::forward(){
	position += Vec3f(0, 0, -0.25);
	viewDirection += Vec3f(0, 0, -0.25);
}

void Camera::back(){
	position += Vec3f(0.0, 0.0, 0.25);
	viewDirection += Vec3f(0.0, 0.0, 0.25);
}

void Camera::left(){
	position += Vec3f(-0.25, 0.0, 0.0);
	viewDirection += Vec3f(-0.25, 0.0, 0.0);
}

void Camera::right(){
	position += Vec3f(0.25, 0.0, 0.0);
	viewDirection += Vec3f(0.25, 0.0, 0.0);
}

Camera camera;
}


