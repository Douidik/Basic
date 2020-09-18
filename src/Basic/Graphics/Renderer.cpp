#include "Renderer.h"
#include "ShaderProgram.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Camera.h"

namespace Basic
{

	bool Renderer::s_IsInitialized;

	void Renderer::Initialize()
	{
		s_IsInitialized = true;
		glewExperimental = GL_TRUE;
		BSC_ASSERT(glewInit() == GLEW_OK, "GLEW - Failed to initialize");
	}

	bool Renderer::IsInitialized()
	{
		return s_IsInitialized;
	}

	Renderer::Renderer(ShaderProgram &shaderProgram, Camera &camera)
		: m_ShaderProgram(shaderProgram), m_Camera(camera)
	{
		GLCall(glEnable(GL_DEPTH_TEST));
	}

	void Renderer::Clear()
	{
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	}

	void Renderer::Update(float aspectRatio)
	{
		m_ViewProjection = m_Camera.CreateProjectionMatrix(aspectRatio) * m_Camera.CreateViewMatrix();
	}

	void Renderer::DrawIndexed(Basic::VertexArray &vertexArray, const Transform &transform)
	{
		m_ShaderProgram.Bind();
		m_ShaderProgram.SetMatrix4("u_ViewProjection", m_ViewProjection);
		m_ShaderProgram.SetMatrix4("u_Transform", transform.CreateMatrix());

		vertexArray.Bind();
		const IndexBuffer &indexBuffer = vertexArray.GetIndexBuffer();
		indexBuffer.Bind();

		for(const auto &vertexBuffer : vertexArray.GetVertexBuffers())
		{
			vertexBuffer.get().Bind();
		}

		GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), indexBuffer.GetType(), nullptr));

		indexBuffer.UnBind();
		for(const auto &vertexBuffer : vertexArray.GetVertexBuffers())
		{
			vertexBuffer.get().UnBind();
		}
		vertexArray.UnBind();
	}

}