#ifndef SANDBOX_FREECAMERA_H
#define SANDBOX_FREECAMERA_H

#include "Graphics/Camera.h"
#include "Events/InputSystem.h"

class FreeCamera : public Basic::Camera
{
public:
	FreeCamera() = default;
	FreeCamera(Basic::CameraConfiguration config, float speed, float sensitivity);
	void Update(const Basic::InputSystem &inputSys, float dt);

private:
	void Move(const Basic::InputSystem &inputSys, float dt);
	void Look(const Basic::InputSystem &inputSys, float dt);

	float m_Speed, m_Sensitivity;
	Basic::MousePosition m_LastMousePosition;
};

#endif //SANDBOX_FREECAMERA_H
