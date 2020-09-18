#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <iostream>

namespace Basic
{

	std::shared_ptr<spdlog::logger> Log::s_BasicLogger;
	std::shared_ptr<spdlog::logger> Log::s_SandboxLogger;

	void Log::Initialize()
	{
		try
		{
			// Create console sink with colored output
			spdlog::sink_ptr consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
			consoleSink->set_pattern("[%n at %T] %v");

			s_BasicLogger = std::make_shared<spdlog::logger>("Basic-Engine", consoleSink);
			s_SandboxLogger = std::make_shared<spdlog::logger>("Sandbox", consoleSink);

			s_BasicLogger->set_level(spdlog::level::trace);
			s_SandboxLogger->set_level(spdlog::level::trace);
		}
		catch(const spdlog::spdlog_ex &error)
		{
			// Using C++ default logging system for spdlog exception logging
			std::cerr << "SPDLOG - " << error.what() << std::endl;
		}
	}

}
