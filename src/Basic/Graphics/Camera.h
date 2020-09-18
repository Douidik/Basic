#ifndef BASIC_CAMERA_H
#define BASIC_CAMERA_H

#include "Maths/Math.h"

namespace Basic
{

	struct CameraConfiguration
	{
		float fieldOfView, zNear, zFar;
	};

	class  Camera : public Transform
	{
	public:
		Camera(CameraConfiguration config);
		Matrix4 CreateProjectionMatrix(float aspectRatio);
		Matrix4 CreateViewMatrix();

	private:
		CameraConfiguration m_Config;

	};

}

#endif //BASIC_CAMERA_H
