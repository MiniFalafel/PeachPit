#pragma once

#include <PeachPit/PeachPit.h>

class CoolLayer : public Peach::Layer
{

	std::shared_ptr<Peach::VertexArray> m_VAO;

	std::shared_ptr<Peach::Shader> m_Shader;

public:

	void OnAttach() override
	{
		// Load assets
		m_Shader = Peach::Shader::Create("res/test.glsl");

		// Triangle vertex data
		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f,
		};
		uint32_t indices[] = {
			0, 1, 2
		};
		// vertex and element buffers
		std::shared_ptr<Peach::VertexBuffer> vBuffer = Peach::VertexBuffer::Create(vertices, sizeof(vertices) / sizeof(float));
		std::shared_ptr<Peach::IndexBuffer> iBuffer = Peach::IndexBuffer::Create(indices, 3);
		// Set vertex layout
		vBuffer->SetVertexLayout(Peach::VertexLayout({
			{ "aPosition", Peach::DataType::Vec3 },
		}));
		// Attach buffers to vertex array
		m_VAO = Peach::VertexArray::Create();
		m_VAO->AttachVertexBuffer(vBuffer);
		m_VAO->SetIndexBuffer(iBuffer);

		// Clear color
		Peach::Renderer::SetClearColor(0.1, 0.2, 0.2, 0.0);

	}

	void OnDetach() override
	{

	}

	void OnUpdate() override
	{
		m_Shader->Use();

		// Tell the renderer to draw our VAO
		Peach::Renderer::DrawIndexed(m_VAO);
	}

};
