#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Texture.h"
#include "Camera.h"
#include "Object.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "ShaderClass.h"
#include "Cube.h"
#include "ShaderClass.h"


// Main function of the Main File(C++)
int main(){
	// Window
	int window_witdh = 1920;
	int window_height = 1080;
	Window window(window_witdh, window_height, "First Person Shooter");
	Camera camera;
	
	camera.Postion = glm::vec3(0.0f, 0.0f, 2.0f);

	glfwSetInputMode(window.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// Load Glad
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0,0, window_witdh, window_height);
	glEnable(GL_DEPTH_TEST);

	// Create the Object + the Light Sorce
	Object cube(CubeVertices, CubeVerticesSize, CubeIndiecs,CubeIndiecsSize , "default.vert", "default.frag");
	Object light_sorce1(CubeVertices,CubeVerticesSize , CubeIndiecs, CubeIndiecsSize, "light.vert", "light.frag");
	Texture texture("Texture's/brick.png");


	// Set The Position and the scale of the Light Sorce and the color for the cube
	cube.Color = glm::vec3(1.0f, 0.5f, 0.31f);
	cube.Position = glm::vec3(0.0f, 0.0f, 0.0f);
	cube.Scale = glm::vec3(1.0f);


	light_sorce1.Position = glm::vec3(4.0f, 2.4f, 1.2f);
	light_sorce1.Color = glm::vec3(1.0f, 1.0f, 1.0f);
	light_sorce1.Scale = glm::vec3(0.5f);


	// While Loop
	while (!window.WindowShouldClose()) {
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		double xpos, ypos;
		glfwGetCursorPos(window.window, &xpos, &ypos);

		// Runs the game in 60 FPS(I hope so)
		float currentTime = (float)glfwGetTime();
		camera.deltaTime = currentTime - camera.LastTime;
		camera.LastTime = currentTime;

		// Keybourd + the mosude Movements functions
		camera.ProssecInput(window.window);
		camera.Mouse_CallBack(window.window, xpos, ypos);

		// Set the settings for The View Matrix(Camera Matrix)
		glm::mat4 view = glm::lookAt(camera.Postion, camera.Postion + camera.Forward, camera.Up);
		

		// Set the settings for the Projeection Matrix
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)(window_witdh / (float)window_height), 0.1f, 100.0f);

		// Unbind Texture


		// Draw the Cube a the Lightr Sorce in the screen
		cube.Draw(view, projection, light_sorce1.Color, light_sorce1.Position, camera.Postion);
		light_sorce1.Draw(view, projection, light_sorce1.Color, light_sorce1.Position, camera.Postion);

	
		// The Swap Buffer
		window.SwapBuffers();
		// The PollEevnts
		window.PollEvents();
	}


	// Return 0 of the Int main Function
	return 0;
}