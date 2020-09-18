#include "VertexArray.h"

namespace Basic
{

	VertexArray::VertexArray(VertexBuffer &vertexBuffer, IndexBuffer &indexBuffer)
		: m_IndexBuffer(indexBuffer)
	{
		Generate();

		AddVertexBuffer(vertexBuffer);
	}

	VertexArray::VertexArray(std::vector<std::reference_wrapper<VertexBuffer>> vertexBuffers, IndexBuffer &indexBuffer)
		: m_IndexBuffer(indexBuffer)
	{
		Generate();

		for (auto &vertexBuffer : vertexBuffers)
		{
			AddVertexBuffer(vertexBuffer);
		}
	}

	VertexArray::~VertexArray()
	{
		GLCall(glDeleteVertexArrays(1, &m_RendererID));
	}

	void VertexArray::Generate()
	{
		GLCall(glGenVertexArrays(1, &m_RendererID));
	}

	void VertexArray::AddVertexBuffer(VertexBuffer &vertexBuffer)
	{
		GLCall(glBindVertexArray(m_RendererID));
		vertexBuffer.Bind();

		Layout &layout = vertexBuffer.GetLayout();

		for (const auto &attribute : layout.GetAttributes())
		{
			switch (attribute.type)
			{
			case GL_BYTE:
			case GL_UNSIGNED_BYTE:
			case GL_SHORT:
			case GL_UNSIGNED_SHORT:
			case GL_INT:
			case GL_UNSIGNED_INT:
			{
				GLCall(glVertexAttribIPointer(attribute.index,
											  attribute.count,
											  attribute.type,
											  layout.GetStride(),
											  (const void *)attribute.offset));
				break;
			}
			case GL_DOUBLE:
			{
				GLCall(glVertexAttribLPointer(attribute.index,
											  attribute.count,
											  attribute.type,
											  layout.GetStride(),
											  (const void *)attribute.offset));
				break;
			}
			default:
			{
				GLCall(glVertexAttribPointer(attribute.index,
											 attribute.count,
											 attribute.type,
											 attribute.normalized,
											 layout.GetStride(),
											 (const void *)attribute.offset));
				break;
			}
			}
		}

		m_VertexBuffers.emplace_back(vertexBuffer);

		// TODO: check if the appended vertex buffer is the original
	}

	void VertexArray::Bind() const
	{
		GLCall(glBindVertexArray(m_RendererID));
	}

	void VertexArray::UnBind() const
	{
		GLCall(glBindVertexArray(0));
	}

	std::vector<std::reference_wrapper<VertexBuffer>> &VertexArray::GetVertexBuffers()
	{
		return m_VertexBuffers;
	}

	IndexBuffer &VertexArray::GetIndexBuffer()
	{
		return m_IndexBuffer;
	}

}