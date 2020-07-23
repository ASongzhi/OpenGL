#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:

	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up);
	Camera(glm::vec3 camPos, float yaw, float pitch, glm::vec3 worldUp);

	glm::mat4 getViewMatrix();
	void posUpdate(glm::vec3 move);
	void dirUpdate(float xoffset,float yoffset);
	
	glm::vec3 position;
	glm::vec3 target;
	glm::vec3 worldUp;
	glm::vec3 front;
	glm::vec3 right;
	glm::vec3 up;

	float yaw;
	float pitch;

	float speed;



private:
	
};

