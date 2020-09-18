#include "Context.h"
#include "Graphics/Renderer.h"

namespace Basic
{

	void GlfwCatchError(int, const char *error)
	{
		BSC_ERROR("GLFW - {}", error);
	}

	void Context::Initialize()
	{
		// Setting up custom error catching function
		glfwSetErrorCallback(&GlfwCatchError);

		glfwInit();
	}

	void Context::Release()
	{
		glfwTerminate();
	}

	Context::Context(const std::string &windowTitle, int windowWidth, int windowHeight)
	{
		CreateWindow(windowTitle, windowWidth, windowHeight);
	}

	Context::~Context()
	{
		glfwDestroyWindow(m_pGlfwWindow);
	}

	void Context::CreateWindow(const std::string &title, int width, int height)
	{
		m_pGlfwWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		BSC_ASSERT(m_pGlfwWindow, "Failed to create the GLFW window");
		glfwMakeContextCurrent(m_pGlfwWindow);

		/* When the framebuffer resize (so when the window gets resized) we resize the OpenGL window */
		glfwSetFramebufferSizeCallback(m_pGlfwWindow, [](GLFWwindow *pGlfwWindow, int width, int height)
		{
			glViewport(0, 0, width, height);
		});

		/* OpenGL have a valid context, we need to initialize it */
		if(!Renderer::IsInitialized())
		{
			Renderer::Initialize();
		}
	}

	void Context::Update()
	{
		glfwPollEvents();
	}

	void Context::RefreshWindow()
	{
		glfwSwapBuffers(m_pGlfwWindow);
	}

	bool Context::ShouldClose()
	{
		return glfwWindowShouldClose(m_pGlfwWindow);
	}

	int Context::GetWidth() const
	{
		int width = 0;
		glfwGetWindowSize(m_pGlfwWindow, &width, nullptr);
		return width;
	}

	int Context::GetHeight() const
	{
		int height = 0;
		glfwGetWindowSize(m_pGlfwWindow, nullptr, &height);
		return height;
	}

	float Context::GetAspectRatio() const
	{
		return (float)GetWidth() / (float)GetHeight();
	}

	GLFWwindow *Context::GetGlfwWindow() const
	{
		return m_pGlfwWindow;
	}

}
