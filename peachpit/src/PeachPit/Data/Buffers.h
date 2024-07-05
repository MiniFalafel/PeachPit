#pragma once

#include <stdint.h>
#include <memory>

#include "PeachPit/Data/VertexLayout.h"

namespace Peach
{

	class VertexBuffer
	{
		// OPENGL ID
		uint32_t m_ID = 0;

		// Members
		VertexLayout m_Layout;
		uint32_t m_Count;

	public:
		VertexBuffer(float* data, uint32_t count);

		// API Methods
		static std::shared_ptr<VertexBuffer> Create(float* data, uint32_t count);

		// Bind/Unbind
		void Bind() const;
		void Unbind() const;

		// SETTERS
		void SetVertexLayout(VertexLayout& layout);

		// GETTERS
		const VertexLayout& GetVertexLayout() const { return m_Layout; }
		uint32_t GetCount() const { return m_Count; }

	};

	class IndexBuffer
	{
		// OPENGL ID
		uint32_t m_ID = 0;
		
		// Members
		uint32_t m_Count;


	public:
		IndexBuffer(uint32_t* data, uint32_t count);

		// API Methods
		static std::shared_ptr<IndexBuffer> Create(uint32_t* data, uint32_t count);

		// Bind/Unbind
		void Bind() const;
		void Unbind() const;

		// GETTER
		uint32_t GetCount() const { return m_Count; }


	};

}
