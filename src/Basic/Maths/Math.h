#ifndef BASIC_MATH_H
#define BASIC_MATH_H

namespace Basic
{

	using Vector2 = glm::vec2;
	using Vector3 = glm::vec3;
	using Vector4 = glm::vec4;

	using Matrix3 = glm::mat3;
	using Matrix4 = glm::mat4;

	struct Transform
	{
		Transform(Vector3 _position = { 0, 0, 0 }, Vector3 _rotation = { 0, 0, 0 }, Vector3 _scale = { 1, 1, 1 });
		Matrix4 CreateMatrix() const;
		Vector3 position, rotation, scale;
	};

}

#endif //BASIC_MATH_H
