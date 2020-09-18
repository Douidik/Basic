#include "IndexBuffer.h"
#include "Utility/Utility.h"

namespace Basic
{

	IndexBuffer::IndexBuffer(const void *data, size_t size, GLenum type, GLenum usage)
		: Buffer(GL_ELEMENT_ARRAY_BUFFER, usage), m_Type(type)
	{
		UploadData(data, size);
	}

	IndexBuffer::IndexBuffer(GLenum type, GLenum usage)
		: Buffer(GL_ELEMENT_ARRAY_BUFFER, usage), m_Type(type)
	{ }

	void IndexBuffer::Bind() const
	{
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
	}

	void IndexBuffer::UnBind() const
	{
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

	void IndexBuffer::UploadData(const void *data, size_t size)
	{
		m_Count = size / SizeOfGLType(m_Type);
		Buffer::UploadData(data, size);
	}

	size_t IndexBuffer::GetCount() const
	{
		return m_Count;
	}

	GLenum IndexBuffer::GetType() const
	{
		return m_Type;
	}

}