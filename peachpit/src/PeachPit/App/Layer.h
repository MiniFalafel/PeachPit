#pragma once

namespace Peach
{

	class Layer
	{	// These will be attached to an application so that event handling and gametick functions can be handled by the user.
	public:
		// NO CONSTRUCTOR

		// Attach/detach
		virtual void OnAttach() {}
		virtual void OnDetach() {}

		// Game loop
		virtual void OnUpdate() {}

	};

}
