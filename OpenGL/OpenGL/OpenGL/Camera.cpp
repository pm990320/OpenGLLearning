/*
 *  Camera.cpp
 *
 *  Created on: 1 Jun 2014
 *      Author: Patrick
 */

#include "Camera.h"
using namespace oglplus;
using namespace Cam;

Camera::Camera(Window& w) : window{ w }, position{ 0, 0, 2 }, viewDirection{ 0, 0, 0 }, oldMousePosition{ (float)w.Width() / 2, (float)w.Height() / 2 }
{ 

}

Mat4f Camera::getWorldToViewMatrix() {
	return CamMatrixf::LookingAt(position, viewDirection, Vec3f(0, 1, 0));
}

Mat4f Camera::getProjectionMatrix() {
	return CamMatrixf::PerspectiveY(Degrees(60), (float)window.Width() / window.Height(), 0.2f, 100.0f);
}

void Camera::move_with_mouse(){
	Vec2f newPos{ (float)sf::Mouse::getPosition(window.window).x, -(float)sf::Mouse::getPosition(window.window).y };
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


