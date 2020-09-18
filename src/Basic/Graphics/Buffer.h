#ifndef BASIC_BUFFER_H
#define BASIC_BUFFER_H

namespace Basic
{

	class Buffer
	{
	public:
		Buffer(GLenum target, GLenum usage);
		virtual ~Buffer();

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void UploadData(const void *data, size_t size);

		int GetParameter(GLenum parameter) const;

	protected:
		GLenum m_Target, m_Usage;
		GLuint m_RendererID;

	private:
		void Generate();
	};

}

#endif //BASIC_BUFFER_H
