-- PEACHPIT project (the engine)

project "peachpit"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	
	-- binaries
	targetdir ("bin/" .. BIN_DIR)
	objdir ("binobj/" .. BIN_DIR)
	
	files {
		"src/**.h",
		"src/**.cpp",
	}