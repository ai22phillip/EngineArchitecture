#pragma once

#ifdef PW_PLATFORM_WINDOWS

	#ifdef PW_BUILD_DLL
		#define POWER_API __declspec(dllexport)
	#else
		#define POWER_API __declspec(dllimport)
	#endif
#else
#error Power only supports Windows!
#endif

#ifdef PW_ENABLE_ASSERTS
#define PW_ASSERT(x, ...) { if(!(x)) { PW_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define PW_CORE_ASSERT(x, ...) { if(!(x)) { PW_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define PW_ASSERT(x, ...)
#define PW_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)