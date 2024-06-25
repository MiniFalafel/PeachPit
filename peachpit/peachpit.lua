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
	targetdir ("bin/" .. BIN_DIR .. "%{prj.name}")
	objdir ("binobj/" .. BIN_DIR .. "%{prj.name}")
	
	files {
		"src/**.h",
		"src/**.cpp",
	}
	
	-- Vendor Include dirs
	includedirs {
		"%{vendors.glfw}",
		"%{vendors.glad}",
	}
	
	-- Vendor Linking
	links {
		"glfw",
		"glad"
	}