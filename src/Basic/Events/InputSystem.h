#ifndef BASIC_INPUTSYSTEM_H
#define BASIC_INPUTSYSTEM_H

namespace Basic
{
	struct MousePosition
	{
		double x, y;
	};

	// This class manages all the inputs received for a given window
	// The input system should only be called in the main thread !
	class InputSystem
	{
	public:
		InputSystem() = default;
		InputSystem(GLFWwindow *pGlfwWindow);

		bool IsKeyPressed(KeyCode keyCode) const;
		bool IsButtonPressed(ButtonCode buttonCode) const;

		MousePosition GetMousePosition() const;

	private:
		GLFWwindow *m_pGlfwWindow;
	};

}

#endif //BASIC_INPUTSYSTEM_H
