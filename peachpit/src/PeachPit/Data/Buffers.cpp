#include "Buffers.h"

#include <glad/glad.h>

namespace Peach
{

    // VERTEX BUFFER
    VertexBuffer::VertexBuffer(float* data, uint32_t count)
        : m_Count(count)
    {
        // Generate Buffer
        glCreateBuffers(1, &m_ID);

        // Upload the data to the GPU
        Bind();
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, data, GL_STATIC_DRAW);
    }

    // API Methods
    std::shared_ptr<VertexBuffer> VertexBuffer::Create(float* data, uint32_t count)
    {
        return std::make_shared<VertexBuffer>(data, count);
    }

    void VertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_ID);
    }

    void VertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBuffer::SetVertexLayout(VertexLayout& layout)
    {
        m_Layout = layout;
    }

    // INDEX BUFFER
    IndexBuffer::IndexBuffer(uint32_t* data, uint32_t count)
        : m_Count(count)
    {
        // Generate Buffer
        glCreateBuffers(1, &m_ID);

        // Upload the data to the GPU
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * count, data, GL_STATIC_DRAW);
    }

    // API Methods
    std::shared_ptr<IndexBuffer> IndexBuffer::Create(uint32_t* data, uint32_t count)
    {
        return std::make_shared<IndexBuffer>(data, count);
    }

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
    }

    void IndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

}

