#ifndef BASIC_TEXTURE2D_H
#define BASIC_TEXTURE2D_H

namespace Basic
{

	class Texture2D
	{
	public:
		Texture2D(fs::path path);
		~Texture2D();

		void UploadData(fs::path path);

		void Bind(int slot = 0);
		void UnBind();

		void SetParameter(int key, int value);
		int GetParameter(int key);

	private:
		void Generate();
		int m_Bpp, m_Width, m_Height;
		GLuint m_RendererID;
	};

}

#endif //BASIC_TEXTURE2D_H
