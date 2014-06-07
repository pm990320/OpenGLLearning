#include "Camera.h"


Camera::Camera() : viewDirection(0.0f, 0.0f, -1.0f)
{
}


glm::mat4 Camera::getWorldToViewMatrix() const {
	return glm::lookAt(position, position + viewDirection, UP);
}

void Camera::mouseUpdate(const glm::vec2& newMousePosition) {
	glm::vec2 mouseDelta = newMousePosition - oldMousePosition;

	viewDirection = glm::mat3(glm::rotate(mouseDelta.x, UP)) * viewDirection;

	oldMousePosition = newMousePosition;
}
