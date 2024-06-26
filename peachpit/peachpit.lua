-- INCLUDE SUBMODULES
include "vendor/glfw_proj"
include "vendor/glad_proj"

-- vendor include directories
vendors = {}
vendors["glfw"] = "vendor/glfw/include/"
vendors["glad"] = "vendor/glad/include/"

-- PEACHPIT project (the engine)
project "peachpit"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	-- binaries
	targetdir ("%{wks.location}/bin/" .. BIN_DIR .. "/%{prj.name}")
	objdir ("%{wks.location}/binobj/" .. BIN_DIR .. "/%{prj.name}")
	
	files {
		"src/**.h",
		"src/**.cpp",
	}
	
	-- Vendor Include dirs
	includedirs {
		"src/",
		"%{vendors.glfw}",
		"%{vendors.glad}",
	}
	
	-- Vendor Linking
	links {
		"glfw",
		"glad"
	}