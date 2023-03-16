#pragma once



#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Power {

	class POWER_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
	

	

}

// Core log macros
#define PW_CORE_ERROR(...)    ::Power::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PW_CORE_WARN(...)     ::Power::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PW_CORE_INFO(...)     ::Power::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PW_CORE_FATAL(...)    ::Power::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define PW_CORE_TRACE(...)    ::Power::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define PW_ERROR(...)         ::Power::Log::GetClientLogger()->error(__VA_ARGS__)
#define PW_WARN(...)          ::Power::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PW_INFO(...)          ::Power::Log::GetClientLogger()->info(__VA_ARGS__)
#define PW_FATAL(...)         ::Power::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define PW_TRACE(...)         ::Power::Log::GetClientLogger()->trace(__VA_ARGS__)
