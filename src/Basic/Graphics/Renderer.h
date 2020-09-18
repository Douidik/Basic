#ifndef BASIC_RENDERER_H
#define BASIC_RENDERER_H

#include "Maths/Math.h"

namespace Basic
{

	class ShaderProgram;
	class VertexArray;
	class Camera;

	class Renderer
	{
	public:
		static void Initialize();
		static bool IsInitialized();

		Renderer(ShaderProgram &shaderProgram, Camera &camera);
		void Clear();
		void Update(float aspectRatio);
		void DrawIndexed(VertexArray &vertexArray, const Transform &transform);

	private:
		ShaderProgram &m_ShaderProgram;
		Camera &m_Camera;
		Matrix4 m_ViewProjection;

		static bool s_IsInitialized;
	};

}

#endif //BASIC_RENDERER_H
