project "glad"
	location "glad"
	kind "StaticLib"
	language "C"
	staticruntime "on"
	
	targetdir ("bin/" .. BIN_DIR .. "%{prj.name}")
	objdir ("binobj/" .. BIN_DIR .. "%{prj.name}")
	
	files {
		"%{prj.location}/glad/glad.h",
		"%{prj.location}/glad/KHR/khrplatform.h",
		"%{prj.location}/src/glad.c"
	}
	
	includedirs {
		"%{prj.location}/include"
	}