#include "Buffer.h"

namespace Basic
{

	Buffer::Buffer(GLenum target, GLenum usage)
		: m_Target(target), m_Usage(usage)
	{
		Generate();
	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void Buffer::UploadData(const void *data, size_t size)
	{
		GLCall(glBindBuffer(m_Target, m_RendererID));
		GLCall(glBufferData(m_Target, size, data, m_Usage));
	}

	void Buffer::Generate()
	{
		GLCall(glGenBuffers(1, &m_RendererID));
		GLCall(glBindBuffer(m_Target, m_RendererID));
	}

	int Buffer::GetParameter(GLenum parameter) const
	{
		int value;
		glBindBuffer(m_Target, m_RendererID);
		glGetBufferParameteriv(m_Target, parameter, &value);

		return value;
	}

}