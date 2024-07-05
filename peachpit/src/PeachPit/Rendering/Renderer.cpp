#include "Renderer.h"

#include <glad/glad.h>

namespace Peach
{

	void Renderer::SetClearColor(float  r, float  g, float  b, float  a)
	{
		glClearColor(r, g, b, a);
	}

	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void Renderer::DrawIndexed(std::shared_ptr<VertexArray> vao)
	{
		// Bind the VAO
		vao->Bind();
		glDrawElements(GL_TRIANGLES, vao->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);
	}

}

