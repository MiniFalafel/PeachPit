-- SANDBOX project

project "sandbox"
	kind "ConsoleApp"
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
	
	-- includes
	includedirs {
		"../peachpit/src"
	}
	
	-- project linking
	links {
		"peachpit"
	}