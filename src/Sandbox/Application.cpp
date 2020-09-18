#include "Application.h"
#include "FreeCamera.h"

Application::Application(const std::string &name, int width, int height)
	: m_Context(name, width, height),
	  m_DeltaTime(0.0),
	  m_LastTime(0.0),
	  m_InputSystem(m_Context.GetGlfwWindow())
{ }

constexpr GLfloat VertexData[] =
{
  -0.5f, -0.5f, 0.0f,
   0.5f, -0.5f, 0.0f,
   0.5f,  0.5f, 0.0f,
  -0.5f,  0.5f, 0.0f
};

constexpr GLfloat TextureCoordsData[] =
{
	0.0f, 1.0f,
	1.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 0.0f
};

constexpr GLuint IndexData[] =
{
	0, 1, 2,
	2, 3, 0
};

void Application::Run()
{
	Basic::VertexBuffer vertexBuffer(VertexData, sizeof(VertexData), GL_STATIC_DRAW, { {0 , 3, GL_FLOAT} });
	Basic::VertexBuffer textureCoordsBuffer(TextureCoordsData, sizeof(TextureCoordsData), GL_STATIC_DRAW, {{ 1 , 2, GL_FLOAT} });
	Basic::IndexBuffer indexBuffer(IndexData, sizeof(IndexData), GL_UNSIGNED_INT, GL_STATIC_DRAW);
	Basic::VertexArray vertexArray({ vertexBuffer, textureCoordsBuffer }, indexBuffer);
	Basic::Texture2D texture("assets/checkerboard.png");

	Basic::ShaderProgram shaderProgram("assets/debug.vs", "assets/debug.fs");
	FreeCamera camera({85.0f, 0.1f, 100.0f}, 2.0f, 20.0f);
	Basic::Renderer renderer(shaderProgram, camera);
	Basic::Transform transform({0, 0, -1});

	while(!m_Context.ShouldClose())
	{
		double time = glfwGetTime();
		m_DeltaTime = time - m_LastTime;
		m_LastTime = time;

		m_Context.Update();
		camera.Update(m_InputSystem, (float)m_DeltaTime);

		renderer.Update(m_Context.GetAspectRatio());
		renderer.Clear();

		texture.Bind();
		shaderProgram.SetInteger("u_DiffuseTexture", 0);
		renderer.DrawIndexed(vertexArray, transform);

		m_Context.RefreshWindow();
	}
}
