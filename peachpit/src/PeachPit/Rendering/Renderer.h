#pragma once

#include "PeachPit/Data/VertexArray.h"

namespace Peach
{

	class Renderer
	{

	public:
		static void SetClearColor(float r, float  g, float  b, float  a);
		static void Clear();

		static void DrawIndexed(std::shared_ptr<VertexArray> vao);

	};

}
