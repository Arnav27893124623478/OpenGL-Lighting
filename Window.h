#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

// Window Class
class Window {
public: 
	GLFWwindow* window;
	// Contructors to make the Window
	Window(int witdh, int height, const char* Titel);

	// Function to close the window
	bool WindowShouldClose();
	// Function to SwapBuffers
	void SwapBuffers();
	//Function To PollEvents
	void PollEvents();

	// Decontrutor to Destroy the Window
	~Window();
};