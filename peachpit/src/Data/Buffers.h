#pragma once

#include <stdint.h>
#include <memory>

#include "VertexLayout.h"

namespace Peach
{

	class VertexBuffer
	{
		// OPENGL ID
		uint32_t m_ID = 0;

		// Stored VertexLayout
		VertexLayout m_Layout;


	public:
		VertexBuffer(float* data, uint32_t size);

		// API Methods
		static std::shared_ptr<VertexBuffer> Create(float* data, uint32_t size);

		// Bind/Unbind
		void Bind() const;
		void Unbind() const;

		// SETTERS
		void SetVertexLayout(VertexLayout& layout);

		// GETTERS
		const VertexLayout& GetVertexLayout() const { return m_Layout; }

	};

	class IndexBuffer
	{
		// OPENGL ID
		uint32_t m_ID = 0;


	public:
		IndexBuffer(uint32_t* data, uint32_t size);

		// API Methods
		static std::shared_ptr<IndexBuffer> Create(uint32_t* data, uint32_t size);

		// Bind/Unbind
		void Bind() const;
		void Unbind() const;


	};

}
