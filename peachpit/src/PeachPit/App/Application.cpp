
#include "Application.h"

#include "PeachPit/Rendering/RenderingAPI.h"

namespace Peach
{

	// initialize static variable for singleton
	Application* Application::s_Instance = nullptr;
	bool Application::s_Running = false;

	// Constructor
	Application::Application()
	{
		// Do singleton stuff
		ASSERT(!s_Instance, "An instance of Application has already been initialized!");

		// Create window
		m_Window = Window(1280, 720, "Window - PeachPit");

		// Initialize the Rendering API
		RenderingAPI::Init();

	}

	void Application::Run()
	{
		// Check if the application is already doing a run loop.
		ASSERT(!s_Running, "An instance of Application is already running! (Application::Run cannot be called twice)");


		// While loop
		s_Running = true;
		while (s_Running)
		{
			// Update running variable
			s_Running = !m_Window.CheckShouldClose();

			// Update the window
			m_Window.SwapPoll(); // swap buffers and poll for events.
		}

	}

}