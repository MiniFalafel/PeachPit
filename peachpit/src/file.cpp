#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "file.h"

void doWIndowThing()
{
	// Initialize glfw
	if (!glfwInit())
	{
		std::cout << "GLFW FAILED TO INITIALIZE!\n";
		glfwTerminate();
		return;
	}

	// Window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Window creation
	GLFWwindow* window;

	window = glfwCreateWindow(800, 600, "Window Title", nullptr, nullptr);

	// Check window creation
	if (window == nullptr)
	{
		std::cout << "WINDOW CREATION FAILED!!\n";
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);


	// Initialize API
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD FAILED TO INITIALIZE!\n";
		return;
	}

	bool running = true;

	while (running)
	{
		// Check events
		glfwPollEvents();

		// Check glfwwindowshouldclose
		running = !glfwWindowShouldClose(window);

		// Swap buffers
		glfwSwapBuffers(window);

	}

	glfwTerminate();
}
