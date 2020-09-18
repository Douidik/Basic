#ifndef BASIC_INDEXBUFFER_H
#define BASIC_INDEXBUFFER_H

#include "Buffer.h"

namespace Basic
{

	class IndexBuffer : public Buffer
	{
	public:
		IndexBuffer(const void *data, size_t size, GLenum type, GLenum usage);
		IndexBuffer(GLenum type, GLenum usage);

		void UploadData(const void *data, size_t size) override;

		void Bind() const override;
		void UnBind() const override;

		size_t GetCount() const;
		GLenum GetType() const;

	private:
		size_t m_Count;
		GLenum m_Type;
	};

}

#endif //BASIC_INDEXBUFFER_H