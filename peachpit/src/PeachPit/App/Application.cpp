
#include "Application.h"

#include "PeachPit/Rendering/RenderingAPI.h"
#include "PeachPit/Rendering/Renderer.h"

namespace Peach
{

	// initialize static variable for singleton
	Application* Application::s_Instance = nullptr;

	// Constructor
	Application::Application()
		: m_Running(false)
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
		ASSERT(!m_Running, "An instance of Application is already running! (Application::Run cannot be called twice)");


		// While loop
		m_Running = true;
		while (m_Running)
		{
			// Update running variable
			m_Running = !m_Window.CheckShouldClose();

			// RENDERING
			// Clear
			Renderer::Clear();

			// Update layers
			for (std::shared_ptr<Layer> layer : m_Layers)
			{
				layer->OnUpdate();
			}

			// Update the window
			m_Window.SwapPoll(); // swap buffers and poll for events.
		}

	}

}