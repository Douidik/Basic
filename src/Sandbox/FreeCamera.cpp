#include "FreeCamera.h"

FreeCamera::FreeCamera(Basic::CameraConfiguration config, float speed, float sensitivity)
	: Basic::Camera(config), m_Speed(speed), m_Sensitivity(sensitivity), m_LastMousePosition({0, 0})
{ }

void FreeCamera::Update(const Basic::InputSystem &inputSys, float dt)
{
	Move(inputSys, dt);
	Look(inputSys, dt);
}

void FreeCamera::Move(const Basic::InputSystem &inputSys, float dt)
{
	Basic::Vector3 _movement(0.0f);

	if(inputSys.IsKeyPressed(BSC_KEY_W))
	{
		_movement.x -= glm::cos(glm::radians(rotation.y + 90));
		_movement.z -= glm::sin(glm::radians(rotation.y + 90));
	}
	if (inputSys.IsKeyPressed(BSC_KEY_S))
	{
		_movement.x += glm::cos(glm::radians(rotation.y + 90));
		_movement.z += glm::sin(glm::radians(rotation.y + 90));
	}
	if (inputSys.IsKeyPressed(BSC_KEY_D))
	{
		_movement.x += glm::cos(glm::radians(rotation.y));
		_movement.z += glm::sin(glm::radians(rotation.y));
	}
	if (inputSys.IsKeyPressed(BSC_KEY_A))
	{
		_movement.x -= glm::cos(glm::radians(rotation.y));
		_movement.z -= glm::sin(glm::radians(rotation.y));
	}

	Basic::Vector3 movement = _movement;
	// Normalizing the movement vector
	if(movement != Basic::Vector3(0.0f)) // If the movement is not null
	{
		float length = glm::sqrt(movement.x * movement.x + movement.y * movement.y + movement.z * movement.z);
		movement /= length;
	}

	position += movement * m_Speed * dt;
}

void FreeCamera::Look(const Basic::InputSystem &inputSys, float dt)
{
	Basic::MousePosition mousePosition = inputSys.GetMousePosition();
	Basic::Vector3 delta = { mousePosition.y - m_LastMousePosition.y, mousePosition.x - m_LastMousePosition.x, 0.0f };
	rotation += delta * m_Sensitivity * dt;
	m_LastMousePosition = mousePosition;

	rotation.x = std::clamp(rotation.x, -85.0f, 85.0f);
	if(rotation.y > 360.0f)
		rotation.y = 0.0f;
	else if(rotation.y < 0.0f)
		rotation.y = 360.0f;
}