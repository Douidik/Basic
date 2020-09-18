#ifndef BASIC_LOG_H
#define BASIC_LOG_H

#include <memory>
#include <spdlog/spdlog.h>

namespace Basic
{
	class Log
	{
	public:
		static void Initialize();

		inline static std::shared_ptr<spdlog::logger> GetBasicLogger()
		{
			return s_BasicLogger;
		}

		inline static std::shared_ptr<spdlog::logger> GetSandboxLogger()
		{
			return s_SandboxLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_BasicLogger;
		static std::shared_ptr<spdlog::logger> s_SandboxLogger;
	};
}

/* Logging macros */

// Basic Engine logging macros
#define BSC_LOG_TRACE(...) ::Basic::Log::GetBasicLogger()->trace(__VA_ARGS__)
#define BSC_LOG_DEBUG(...) ::Basic::Log::GetBasicLogger()->debug(__VA_ARGS__)
#define BSC_LOG_INFO(...)  ::Basic::Log::GetBasicLogger()->info (__VA_ARGS__)
#define BSC_LOG_WARN(...)  ::Basic::Log::GetBasicLogger()->warn (__VA_ARGS__)
#define BSC_LOG_ERROR(...) ::Basic::Log::GetBasicLogger()->error(__VA_ARGS__)

// Sandbox logging macros
#define SBX_LOG_TRACE(...) ::Basic::Log::GetSandboxLogger()->trace(__VA_ARGS__)
#define SBX_LOG_DEBUG(...) ::Basic::Log::GetSandboxLogger()->debug(__VA_ARGS__)
#define SBX_LOG_INFO(...)  ::Basic::Log::GetSandboxLogger()->info (__VA_ARGS__)
#define SBX_LOG_WARN(...)  ::Basic::Log::GetSandboxLogger()->warn (__VA_ARGS__)
#define SBX_LOG_ERROR(...) ::Basic::Log::GetSandboxLogger()->error(__VA_ARGS__)

#endif //BASIC_LOG_H
