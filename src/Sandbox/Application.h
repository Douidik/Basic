#ifndef SANDBOX_APPLICATION_H
#define SANDBOX_APPLICATION_H

#include "Basic.h"
#include "Graphics/Graphics.h"
#include "Events/InputSystem.h"

class Application
{
public:
	Application(const std::string &name, int width, int height);
	void Run();

private:
	double m_DeltaTime, m_LastTime;
	Basic::Context m_Context;
	Basic::InputSystem m_InputSystem;
};

#endif //SANDBOX_APPLICATION_H
