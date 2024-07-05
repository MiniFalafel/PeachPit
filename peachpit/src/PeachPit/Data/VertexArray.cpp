#include "VertexArray.h"

#include <glad/glad.h>

namespace Peach
{
    VertexArray::VertexArray()
    {   // Do OpenGL stuff to make the thing.

        // Generate vertex array
        glCreateVertexArrays(1, &m_ID);
    }
    
    VertexArray::~VertexArray()
    {   // Delete gl vertex array
        glDeleteVertexArrays(1, &m_ID);
    }

    // API methods
    std::shared_ptr<VertexArray> VertexArray::Create()
    {
        return std::make_shared<VertexArray>();
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(m_ID);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void VertexArray::AttachVertexBuffer(std::shared_ptr<VertexBuffer> VBO)
    {
        // Bind self
        Bind();

        // Bind the vertex buffer
        VBO->Bind();

        // Get the layout of the vertex buffer
        const VertexLayout& layout = VBO->GetVertexLayout();
        // Loop through the layout elements
        int index = 0;
        for (const VertexLayoutElement& e : layout)
        {   // Set info about vertex data
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, e.GetCount(), GetOpenGLDataType(e.Type),
                e.Normalized ? GL_TRUE : GL_FALSE, layout.GetStride(), (void*)e.Offset);
            // Increment index
            index++;
        }

        // Emplace into m_VBOs
        m_VBOs.emplace_back(VBO);
    }

    void VertexArray::SetIndexBuffer(std::shared_ptr<IndexBuffer> EBO)
    {   // Bind and then bind the index buffer
        Bind();
        EBO->Bind();
        // Set m_EBO
        m_EBO = EBO;
    }
    std::shared_ptr<IndexBuffer> VertexArray::GetIndexBuffer()
    {
        return m_EBO;
    }
}

