#pragma once
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
class Camera {
public:
	glm::vec3 Postion;
	glm::vec3 Up      =	glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 Forward = glm::vec3(0.0f, 0.0f, -1.0f);

	float deltaTime = 0.0f;
	float LastTime = 0.0f;

	float Yaw = -90.0f;
	float Pitch = 0.0f;

	float LastX = 1920 / 2;
	float LastY = 1080 / 2;
	bool firstmouse = true;
	void ProssecInput(GLFWwindow* window);
	void Mouse_CallBack(GLFWwindow* window, double xpos, double ypos);
};