#include "Camera.h"

// If Press ESC close Window
void Camera::ProssecInput(GLFWwindow* window) {
	float cameraspeed = 2.5f * deltaTime;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		Postion += Forward * cameraspeed;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		Postion -= Forward * cameraspeed;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		Postion -= glm::normalize(glm::cross(Forward, Up)) * cameraspeed;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		Postion += glm::normalize(glm::cross(Forward, Up)) * cameraspeed;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		Postion += Up * cameraspeed;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		Postion -= Up * cameraspeed;
	}
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void Camera::Mouse_CallBack(GLFWwindow* window, double xpos, double ypos) {
	if (firstmouse)
	{
		LastX = xpos;
		LastY = ypos;
		firstmouse = false;
	}

	float xoffset = xpos - LastX;
	float yoffset = LastY - ypos;
	LastX = xpos;
	LastY = ypos;

	float sensitivity = 0.05f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	Yaw += xoffset;
	Pitch += yoffset;

	if (Pitch > 89.0f)
		Pitch = 89.0f;
	if (Pitch < -89.0f)
		Pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	direction.y = sin(glm::radians(Pitch));
	direction.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Forward = glm::normalize(direction);
}

