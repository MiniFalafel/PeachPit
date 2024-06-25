-- SANDBOX project

project "sandbox"
	kind "ConsoleApp"
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
	
	-- includes
	includedirs {
		"../peachpit/src"
	}
	
	-- project linking
	links {
		"peachpit"
	}