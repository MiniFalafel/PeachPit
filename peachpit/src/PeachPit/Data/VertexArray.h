#pragma once

#include "PeachPit/Data/Buffers.h"

namespace Peach
{

	class VertexArray
	{
		// GL ID
		uint32_t m_ID = 0;
		// Buffers
		std::vector<std::shared_ptr<VertexBuffer>> m_VBOs;
		std::shared_ptr<IndexBuffer> m_EBO;

	public:
		VertexArray();
		// Public destructor
		~VertexArray();

		// Creation function (just so the API is consistent)
		static std::shared_ptr<VertexArray> Create();

		void Bind() const;
		void Unbind() const;

		// SETTERS
		void AttachVertexBuffer(std::shared_ptr<VertexBuffer> VBO);
		void SetIndexBuffer(std::shared_ptr<IndexBuffer> EBO);

		// GETTERS
		std::shared_ptr<IndexBuffer> GetIndexBuffer();

	};

}
