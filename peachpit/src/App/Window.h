#pragma once

#include "App/Core.h"

namespace Peach
{

	class Window
	{
		// Private Members
		struct WindowData
		{
			void* NativeWindow;
			int Width, Height;
			const char* Title;
		};

		WindowData m_Data;

		// GLFW Initialization
		static bool s_GLFWInitialized;
		static void InitializeGLFW();

	public:
		Window() {}
		Window(int width, int height, const char* title);
		~Window() {}

		bool CheckShouldClose();

		void SwapPoll();

	};

}
