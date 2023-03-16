workspace "PowerEngine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "PowerEngine"
	location "PowerEngine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "pwpch.h"
	pchsource "Power/src/pwpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"PW_PLATFORM_WINDOWS",
			"PW_BUILD_DLL"
		}
		

		
	filter "configurations:Debug"
		defines "PW_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "PW_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "PW_DIST"
		optimize "On"

		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"PowerEngine/vendor/spdlog/include",
		"PowerEngine/src"
	}
	
	links
	{
		"PowerEngine"
	}
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"PW_PLATFORM_WINDOWS"
		}
		
		filter "configurations:Debug"
		defines "PW_DEBUG"
			symbols "On"
			
		filter "configurations:Release"
		defines "PW_RELEASE"
			optimize "On"
		
		filter "configurations:Dist"
		defines "PW_DIST"
			optimize "On"
			