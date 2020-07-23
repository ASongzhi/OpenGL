#include"Camera.h"
#define GLEW_STATIC

Camera::Camera(glm::vec3 camPos, glm::vec3 camFront, glm::vec3 worldUp)
{
	position = camPos;
	front = camFront;
	Camera::worldUp = worldUp;
	target = glm::normalize(position + front);
	right = glm::normalize(glm::cross(front,Camera::worldUp));
	up = glm::normalize(glm::cross(right, front));
	speed = 2.5f;
}

Camera::Camera(glm::vec3 camPos, float yaw, float pitch, glm::vec3 worldUp)
{
	position = camPos;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	Camera::yaw = yaw;
	Camera::pitch = pitch;
	Camera::worldUp = worldUp;
	target = glm::normalize(position + front);
	right = glm::normalize(glm::cross(front, Camera::worldUp));
	up = glm::normalize(glm::cross(right, front));
	speed = 2.5f;
}

glm::mat4 Camera::getViewMatrix()
{
	return glm::lookAt(position, position+front,up);
}

void Camera::posUpdate(glm::vec3 move)
{
	position += move;
}

void Camera::dirUpdate(float xoffset, float yoffset)
{
	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	front = glm::normalize(front);
}
