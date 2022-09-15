workspace "VEngine"
	architecture "x64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "VEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "VEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "VEngine/vendor/imgui"

include "VEngine/vendor/GLFW"
include "VEngine/vendor/Glad"
include "VEngine/vendor/imgui"


project "VEngine"
	location "VEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vepch.h"
	pchsource "VEngine/src/vepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"VE_PLATFORM_WINDOWS",
			"VE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

		filter "configurations:Debug"
			defines
			{
				"VE_DEBUG"
			} 
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "VE_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "VE_DIST"
			runtime "Release"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"VEngine/vendor/spdlog/include",
		"VEngine/src"
	}

	links
	{
		"VEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "on"
		defines
		{
			"VE_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "VE_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "VE_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "VE_DIST"
			runtime "Release"
			optimize "On"
	