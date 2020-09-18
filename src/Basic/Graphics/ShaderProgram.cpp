#include "ShaderProgram.h"

#define ERROR_LOG_LENGTH 4096

namespace Basic
{

	ShaderProgram::ShaderProgram(fs::path vertexPath, fs::path fragmentPath)
	{
		const auto sources = ReadShaders(vertexPath, fragmentPath);
		m_RendererID = CreateProgram(sources);
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(m_RendererID);
	}

	void ShaderProgram::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void ShaderProgram::UnBind() const
	{
		glUseProgram(0);
	}

	std::pair<std::string, std::string> ShaderProgram::ReadShaders(fs::path &vertexPath, fs::path &fragmentPath)
	{
		std::ifstream vertexStream(vertexPath), fragmentStream(fragmentPath);
		/* Asserting that streams are valid */
		BSC_ASSERT(vertexStream, "Failed to read vertex shader from: {}", vertexPath.string());
		BSC_ASSERT(fragmentStream, "Failed to read fragment shader from: {}", fragmentPath.string());

		/* Reading sources */
		std::stringstream vertexSstr, fragmentSstr;
		vertexSstr << vertexStream.rdbuf();
		fragmentSstr << fragmentStream.rdbuf();

		return { vertexSstr.str(), fragmentSstr.str() };
	}

	GLuint ShaderProgram::CreateProgram(const std::pair<std::string, std::string> &sources)
	{
		GLuint vertexID = CreateShader(sources.first, GL_VERTEX_SHADER);
		GLuint fragmentID = CreateShader(sources.second, GL_FRAGMENT_SHADER);

		GLuint programID = glCreateProgram();

		GLCall(GLCall(glAttachShader(programID, vertexID)));
		GLCall(GLCall(glAttachShader(programID, fragmentID)));

		GLCall(glLinkProgram(programID));

		GLint linkStatus;
		GLCall(glGetProgramiv(programID, GL_LINK_STATUS, &linkStatus));

		if (!linkStatus) // The program throws an error on linkage
		{
			GLchar glLog[ERROR_LOG_LENGTH]; // Program error in the OpenGL format
			GLCall(glGetProgramInfoLog(programID, 2048, nullptr, &glLog[0]));

			std::string log(glLog); // Converting the log for our format
			BSC_ERROR(log);
		}

		/* Detaching and deleting shaders */
		GLCall(glDetachShader(programID, vertexID));
		GLCall(glDetachShader(programID, fragmentID));

		GLCall(glDeleteShader(vertexID));
		GLCall(glDeleteShader(fragmentID));

		return programID;
	}

	GLuint ShaderProgram::CreateShader(const std::string &source, GLenum type)
	{
		GLuint id = glCreateShader(type);
		// Convert the shader source for OpenGL
		const GLchar *glSource = source.c_str();
		GLCall(glShaderSource(id, 1, &glSource, nullptr));
		GLCall(glCompileShader(id));
		return id;
	}

	int ShaderProgram::GetUniformLocation(const std::string &name)
	{
		if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		{
			return m_UniformLocationCache[name];
		}

		int location = glGetUniformLocation(m_RendererID, name.c_str());

		if (location == -1) // Uniform Location not found ?
		{
			BSC_LOG_WARN("Failed to find uniform location of: {}", name);
		}

		m_UniformLocationCache[name] = location;
		return location;
	}

	void ShaderProgram::SetUnsigned(const std::string &name, unsigned int value)
	{
		GLCall(glUniform1ui(GetUniformLocation(name), value));
	}

	void ShaderProgram::SetInteger(const std::string &name, int value)
	{
		GLCall(glUniform1i(GetUniformLocation(name), value));
	}

	void ShaderProgram::SetFloat(const std::string &name, float value)
	{
		GLCall(glUniform1f(GetUniformLocation(name), value));
	}

	void ShaderProgram::SetVector2(const std::string &name, const Vector2 &value)
	{
		GLCall(glUniform2f(GetUniformLocation(name), value.x, value.y));
	}

	void ShaderProgram::SetVector3(const std::string &name, const Vector3 &value)
	{
		GLCall(glUniform3f(GetUniformLocation(name), value.x, value.y, value.z));
	}

	void ShaderProgram::SetVector4(const std::string &name, const Vector4 &value)
	{
		GLCall(glUniform4f(GetUniformLocation(name), value.x, value.y, value.z, value.w));
	}

	void ShaderProgram::SetMatrix3(const std::string &name, const Matrix3 &value, bool transpose)
	{
		GLCall(glUniformMatrix3fv(GetUniformLocation(name), 1, transpose, glm::value_ptr(value)));
	}

	void ShaderProgram::SetMatrix4(const std::string &name, const Matrix4 &value, bool transpose)
	{
		GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, transpose, glm::value_ptr(value)));
	}

}