#include "Window.h"

#include "Core/Core.h"

#include <GLFW/glfw3.h>

namespace Peach
{
	// Initialize static members
	bool Window::s_GLFWInitialized = false;

	void Window::InitializeGLFW()
	{
		// Check that GLFW hasn't been initialized already
		if (s_GLFWInitialized)
			return;

		// Try initializing GLFW
		int success = glfwInit();
		ASSERT(success, "Failed to initialize GLFW"); // Asserts might be disabled in release mode, so we don't want the actual glfwInit() to not be called in release.
	}

	bool Window::CheckShouldClose()
	{
		return glfwWindowShouldClose((GLFWwindow*)m_Data.NativeWindow);
	}

	void Window::SwapPoll()
	{
		glfwSwapBuffers((GLFWwindow*)m_Data.NativeWindow);
		glfwPollEvents();
	}

	Window::Window(int width, int height, const char* title)
	{
		// Fill data struct
		m_Data.Width = width;
		m_Data.Height = height;
		m_Data.Title = title;

		// Initialize GLFW
		InitializeGLFW(); // static method. only does this once.

		// Set window hints
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Generate the window and update the pointer
		m_Data.NativeWindow = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title, nullptr, nullptr);

		// Check that the window was created
		ASSERT(m_Data.NativeWindow, "Failed to create GLFW window");

		// Make context current
		glfwMakeContextCurrent((GLFWwindow*)m_Data.NativeWindow);
	}

}