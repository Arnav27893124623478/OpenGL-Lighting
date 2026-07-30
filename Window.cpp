#include "Window.h"
#include <GLFW/glfw3.h>

// Function to create the Window
Window::Window(int witdh, int height, const char* titel){
	glfwInit();

	// Window Hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// TO create the window
	window = glfwCreateWindow(witdh, height, titel, NULL, NULL);
	// Make context Current Of the Window
	glfwMakeContextCurrent(window);



	// The View Port
	

}

// Function to close the Window(While Loop)
bool Window::WindowShouldClose() {
	return glfwWindowShouldClose(window);
}

// Function to Swap Buffers
void Window::SwapBuffers() {
	glfwSwapBuffers(window);
}

// Function to PollEvents
void Window::PollEvents() {
	glfwPollEvents();
}
// Dectroctor of the Window
Window::~Window() {
	glfwDestroyWindow(window);
	glfwTerminate();
}