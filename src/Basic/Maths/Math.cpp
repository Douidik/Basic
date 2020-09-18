#include "Math.h"

namespace Basic
{

	Transform::Transform(Vector3 _position, Vector3 _rotation, Vector3 _scale)
		: position(_position), rotation(_rotation), scale(_scale)
	{
	}

	Matrix4 Transform::CreateMatrix() const
	{
		Matrix4 matrix(1.0f);

		matrix = glm::scale(matrix, scale);

		matrix = glm::rotate(matrix, glm::radians(rotation.x), { 1,0,0 });
		matrix = glm::rotate(matrix, glm::radians(rotation.y), { 0,1,0 });
		matrix = glm::rotate(matrix, glm::radians(rotation.z), { 0,0,1 });

		matrix = glm::translate(matrix, position);

		return matrix;
	}

}