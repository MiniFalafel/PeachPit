#pragma once

#include "App/Core.h"
#include "Window.h"

namespace Peach
{
	// Singleton class
	class Application
	{

		static Application* s_Instance;
		static bool s_Running;

		// Window
		Window m_Window;

	public:
		Application();
		~Application() {}

		// Run loop
		void Run();

	};

}
