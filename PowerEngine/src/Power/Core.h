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

#define BIT(x) (1 << x)