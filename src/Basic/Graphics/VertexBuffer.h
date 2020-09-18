#ifndef BASIC_VERTEXBUFFER_H
#define BASIC_VERTEXBUFFER_H

#include "Buffer.h"
#include "Layout.h"

namespace Basic
{

	class VertexBuffer : public Buffer
	{
	public:
		VertexBuffer() = default;
		VertexBuffer(const void *data, size_t size, GLenum usage, Layout layout);
		VertexBuffer(GLenum usage, Layout layout);

		void Bind() const override;
		void UnBind() const override;

		inline Layout &GetLayout()
		{
			return m_Layout;
		}

	private:
		Layout m_Layout;
	};

}

#endif //BASIC_VERTEXBUFFER_H
