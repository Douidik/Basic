#include "Texture2D.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace Basic
{
	Texture2D::Texture2D(fs::path path)
	{
		Generate();

		SetParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
		SetParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
		SetParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		SetParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		UploadData(path);
	}

	Texture2D::~Texture2D()
	{
		GLCall(glDeleteTextures(1, &m_RendererID));
	}

	void Texture2D::UploadData(fs::path path)
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));

		stbi_set_flip_vertically_on_load(true);
		// We always want the image to have 4 channels
		ubyte *data = stbi_load(path.c_str(), &m_Width, &m_Height, &m_Bpp, 4);
		BSC_ASSERT(data, "Failed to load image from: {}", path.string());

		GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));
		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data));

		stbi_image_free(data);
	}

	void Texture2D::Bind(int slot)
	{
		GLCall(glActiveTexture(GL_TEXTURE0 + slot));
		GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));
	}

	void Texture2D::UnBind()
	{
		GLCall(glActiveTexture(GL_TEXTURE0));
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	}

	void Texture2D::Generate()
	{
		GLCall(glGenTextures(1, &m_RendererID));
	}

	void Texture2D::SetParameter(int key, int value)
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));
		glTexParameteri(GL_TEXTURE_2D, key, value);
	}

	int Texture2D::GetParameter(int key)
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));
		int value = 0;
		glGetTexParameteriv(GL_TEXTURE_2D, key, &value);
		return value;
	}
}