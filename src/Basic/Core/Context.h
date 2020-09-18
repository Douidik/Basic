#ifndef BASIC_CONTEXT_H
#define BASIC_CONTEXT_H

namespace Basic
{

	class Context
	{
	public:
		static void Initialize();
		static void Release();

		Context() = default;
		Context(const std::string &windowTitle, int windowWidth, int windowHeight);
		~Context();

		void Update();
		void RefreshWindow();
		bool ShouldClose();

		GLFWwindow *GetGlfwWindow() const;
		int GetWidth() const;
		int GetHeight() const;
		float GetAspectRatio() const;

	private:
		void CreateWindow(const std::string &title, int width, int height);

		GLFWwindow *m_pGlfwWindow;
	};

}

#endif //BASIC_CONTEXT_H
