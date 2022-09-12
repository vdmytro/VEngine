#pragma once

#ifdef VE_PLATFORM_WINDOWS
	#ifdef VE_BUILD_DLL
		#define VE_API __declspec(dllexport)
	#else
		#define VE_API __declspec(dllimport)
	#endif // VE_BUILD_DLL

#else
	#error VEngine only supports Windows!

#endif // VE_PLATFORM_WINDOWS

#ifdef VE_DEBUG
	#define VE_ENABLE_ASSERTS
#endif 


#ifdef VE_ENABLE_ASSERTS
	#define VE_ASSERT(x,...) { if(!(x)){ VE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
	#define VE_CORE_ASSERT(x,...) { if(!(x)){ VE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
#else
	#define VE_ASSERT(x,...)
	#define VE_CORE_ASSERT(x,...)
#endif // VE_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define VE_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)