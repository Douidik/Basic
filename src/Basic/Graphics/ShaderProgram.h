#ifndef BASIC_SHADERPROGRAM_H
#define BASIC_SHADERPROGRAM_H

#include "Maths/Math.h"

namespace Basic
{

	class ShaderProgram
	{
	public:
		ShaderProgram(fs::path vertexPath, fs::path fragmentPath);
		~ShaderProgram();

		void Bind() const;
		void UnBind() const;

		/* Uniform setters */
		void SetUnsigned(const std::string &name, unsigned int value);
		void SetInteger(const std::string &name, int value);
		void SetFloat(const std::string &name, float value);

		void SetVector2(const std::string &name, const Vector2 &value);
		void SetVector3(const std::string &name, const Vector3 &value);
		void SetVector4(const std::string &name, const Vector4 &value);

		void SetMatrix3(const std::string &name, const Matrix3 &value, bool transpose = false);
		void SetMatrix4(const std::string &name, const Matrix4 &value, bool transpose = false);

	private:
		/* Program creation */
		std::pair<std::string, std::string> ReadShaders(fs::path &vertexPath, fs::path &fragmentPath);
		GLuint CreateProgram(const std::pair<std::string, std::string> &sources);
		GLuint CreateShader(const std::string &source, GLenum type);

		int GetUniformLocation(const std::string &name);

		GLuint m_RendererID;
		std::unordered_map<std::string, int> m_UniformLocationCache;
	};

}

#endif //BASIC_SHADERPROGRAM_H
