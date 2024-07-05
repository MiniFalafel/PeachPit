#pragma once

#include <vector>
#include <memory>

#include "PeachPit/App/Core.h"
#include "PeachPit/App/Window.h"
#include "PeachPit/App/Layer.h"

namespace Peach
{
	// Singleton class
	class Application
	{
		// State information
		static Application* s_Instance;
		bool m_Running;

		// App Objects
		// Window
		Window m_Window;
		// Layers
		std::vector<std::shared_ptr<Layer>> m_Layers;

	public:
		Application();
		~Application() {}

		// LAYER ATTACH AND DETACH METHODS
		void PushLayer(std::shared_ptr<Layer> layer)
		{	// Run Attach method
			layer->OnAttach();
			// Emplace
			m_Layers.emplace_back(layer);
		}
		void PopLayer(std::shared_ptr<Layer> layer)
		{	// Find the layer to remove and remove it
			std::vector<std::shared_ptr<Layer>>::iterator it = std::find(m_Layers.begin(), m_Layers.end(), layer);
			// Check if it was found
			if (it != m_Layers.end())
			{	// Detach
				layer->OnDetach();
				// Remove it
				m_Layers.erase(it);
			}
		}

		// Run loop
		void Run();

	};

}
