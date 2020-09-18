#include "Camera.h"

namespace Basic
{

	Camera::Camera(CameraConfiguration config)
		: m_Config(config)
	{ }

	Matrix4 Camera::CreateProjectionMatrix(float aspectRatio)
	{
		return glm::perspective(glm::radians(m_Config.fieldOfView),
								aspectRatio,
								m_Config.zNear,
								m_Config.zFar);
	}

	Matrix4 Camera::CreateViewMatrix()
	{
		// Converting the model space coordinates to view space coordinates
		Transform viewTransform(-position, rotation, scale);
		return viewTransform.CreateMatrix();
	}
}