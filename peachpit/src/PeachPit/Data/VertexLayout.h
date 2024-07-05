#pragma once

#include <vector>
#include <string>

#include "PeachPit/Data/DataType.h"

namespace Peach
{

	struct VertexLayoutElement
	{
		std::string Name; // The name is really more for debug purposes.
		DataType Type;
		bool Normalized;
		uint32_t Size;
		uint32_t Offset;

		VertexLayoutElement(std::string name, DataType type, bool normalized = false)
			: Name(name), Type(type), Normalized(normalized), Size(DataTypeSizeof(Type)), Offset(0) {}

		uint32_t GetCount() const
		{
			return DataTypeElementCount(Type);
		}
	};

	class VertexLayout
	{
		uint32_t m_Stride;
		std::vector<VertexLayoutElement> m_Elements;

	public:
		VertexLayout() : m_Stride(0) {}
		// Initializer List constructor
		VertexLayout(std::initializer_list<VertexLayoutElement> elements)
			: m_Elements(elements)
		{
			// Process the initializer list
			m_Stride = 0;
			// Loop through layout elements
			for (VertexLayoutElement& e : m_Elements)
			{	// Set offset and add to the stride
				e.Offset = m_Stride;
				m_Stride += DataTypeSizeof(e.Type);
			}
		}

		// Wrapper functions to make this iterable using std algorithm functions.
		std::vector<VertexLayoutElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<VertexLayoutElement>::iterator end() { return m_Elements.end(); }
		// const versions
		std::vector<VertexLayoutElement>::const_iterator begin() const { return m_Elements.begin(); }
		std::vector<VertexLayoutElement>::const_iterator end() const { return m_Elements.end(); }

		// GETTERS
		const uint32_t GetStride() const { return m_Stride; }

	};

}
