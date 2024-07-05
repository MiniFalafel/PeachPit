#pragma once

#include <stdint.h>
#include <string>
#include <memory>
#include <vector>

namespace Peach
{

	class Shader
	{	// A wrapper for OpenGL Shader Program

		// Shader IDs
		uint32_t m_VertID;
		uint32_t m_FragID;
		// Program ID
		uint32_t m_ID;

		// private setup
		void Shader::SetupShaders(std::vector<std::pair<uint32_t, std::string>> parsedShaders);
		std::vector<std::pair<uint32_t, std::string>> ParseShaderSources(std::string shaderSource);

		// Static shader compiling method
		static uint32_t CompileShader(uint32_t Type, const char* shaderSource);
		static uint32_t ShaderTypeFromToken(const std::string& token);

	public:
		Shader(std::string vertexSource, std::string fragmentSource);
		Shader(std::string filePath);
		~Shader();

		// API creation thing (this is to keep usage consistent because things like framebuffers will heavily rely on this and having it everywhere might make more sense to users).
		static std::shared_ptr<Shader> Create(std::string vertexSource, std::string fragmentSource);
		static std::shared_ptr<Shader> Create(std::string filePath);
	};

}
