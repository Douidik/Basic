#include "VertexBuffer.h"

namespace Basic
{
	VertexBuffer::VertexBuffer(const void *data, size_t size, GLenum usage, Layout layout)
		: Buffer(GL_ARRAY_BUFFER, usage), m_Layout(layout)
	{
		UploadData(data, size);
	}

	VertexBuffer::VertexBuffer(GLenum usage, Layout layout)
		: Buffer(GL_ARRAY_BUFFER, usage), m_Layout(layout)
	{ }

	void VertexBuffer::Bind() const
	{
		m_Layout.Bind();
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	}

	void VertexBuffer::UnBind() const
	{
		m_Layout.UnBind();
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}
}