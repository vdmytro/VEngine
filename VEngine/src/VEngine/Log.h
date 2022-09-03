#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace VEngine {

	class VE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};

}

// Core log macros
#define VE_CORE_ERROR(...)		::VEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VE_CORE_TRACE(...)		::VEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VE_CORE_INFO(...)		::VEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VE_CORE_WARN(...)		::VEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VE_CORE_FATAL(...)		::VEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client log macros
#define VE_ERROR(...)			::VEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define VE_TRACE(...)			::VEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VE_INFO(...)			::VEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define VE_WARN(...)			::VEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VE_FATAL(...)			::VEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
