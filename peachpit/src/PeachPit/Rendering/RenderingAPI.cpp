#include "RenderingAPI.h"

#include "PeachPit/App/Core.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Peach
{

	void RenderingAPI::Init()
	{
		// Initialize GLAD
		int success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ASSERT(success, "Failed to initialize GLAD!");
	}

}
