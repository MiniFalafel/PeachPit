#pragma once

#include "PeachPit/App/Core.h"
#include "PeachPit/App/Window.h"

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
