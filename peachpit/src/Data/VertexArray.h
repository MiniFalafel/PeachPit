#pragma once

#include "Buffers.h"

namespace Peach
{

	class VertexArray
	{
		uint32_t m_ID = 0;

	public:
		VertexArray();
		// Public destructor
		~VertexArray();

		// Creation function (just so the API is consistent)
		static std::shared_ptr<VertexArray> Create();

		void Bind() const;
		void Unbind() const;

		void AttachVertexBuffer(std::shared_ptr<VertexBuffer> VBO);
		void SetIndexBuffer(std::shared_ptr<IndexBuffer> EBO);

	};

}
