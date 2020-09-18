#include "InputSystem.h"

Basic::InputSystem::InputSystem(GLFWwindow *pGlfwWindow)
	: m_pGlfwWindow(pGlfwWindow)
{ }

bool Basic::InputSystem::IsKeyPressed(Basic::KeyCode keyCode) const
{
	return (glfwGetKey(m_pGlfwWindow, static_cast<int>(keyCode)) == GLFW_PRESS ||
			glfwGetKey(m_pGlfwWindow, static_cast<int>(keyCode)) == GLFW_REPEAT);
}

bool Basic::InputSystem::IsButtonPressed(Basic::ButtonCode buttonCode) const
{
	return (glfwGetMouseButton(m_pGlfwWindow, static_cast<int>(buttonCode)) == GLFW_PRESS);
}

Basic::MousePosition Basic::InputSystem::GetMousePosition() const
{
	MousePosition mousePosition = {0, 0};
	glfwGetCursorPos(m_pGlfwWindow, &mousePosition.x, &mousePosition.y);
	return mousePosition;
}
