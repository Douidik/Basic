#include "Core.h"
#include "Context.h"
#include "Graphics/Renderer.h"

namespace Basic
{

	void Core::Initialize()
	{
		Log::Initialize();
		Context::Initialize();
	}

	void Core::Release()
	{
		Context::Release();
	}

}