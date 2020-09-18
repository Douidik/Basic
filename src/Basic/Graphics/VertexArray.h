#ifndef BASIC_VERTEXARRAY_H
#define BASIC_VERTEXARRAY_H

#include "VertexBuffer.h"

namespace Basic
{
	class IndexBuffer;

	class VertexArray
	{
	public:
		/// @brief single vertex buffer constructor
		/// @param vertexBuffer Vertex Buffer with initialized data
		VertexArray(VertexBuffer &vertexBuffer, IndexBuffer &indexBuffer);
		VertexArray(std::vector<std::reference_wrapper<VertexBuffer>> vertexBuffers, IndexBuffer &indexBuffer);
		~VertexArray();

		void Bind() const;
		void UnBind() const;

		std::vector<std::reference_wrapper<VertexBuffer>> &GetVertexBuffers();
		IndexBuffer &GetIndexBuffer();

	private:
		void Generate();
		void AddVertexBuffer(VertexBuffer &vertexBuffer);

		std::vector<std::reference_wrapper<VertexBuffer>> m_VertexBuffers;
		IndexBuffer &m_IndexBuffer;

		GLuint m_RendererID;
	};

}

#endif //BASIC_VERTEXARRAY_H
