#include "Shader.h"

#include <glad/glad.h>

#include <fstream>
#include <algorithm>
#include <vector>

#include "PeachPit/App/Core.h"
#include "PeachPit/Utils/FileUtils.h"

namespace Peach
{
	uint32_t Shader::CompileShader(uint32_t glShadertype, const char* shaderSource)
	{	// Create GL shader
		uint32_t shader = glCreateShader(glShadertype);
		glShaderSource(shader, 1, &shaderSource, nullptr); // Attach shader source code
		glCompileShader(shader); // Compile the shader

		// Error checking
		int success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			LOG_ERROR("Shader compilation failed!\n" << infoLog);
		}

		return  shader;
	}

	uint32_t Shader::ShaderTypeFromToken(const std::string& token)
	{
		if (token == "VERTEX")
			return GL_VERTEX_SHADER;
		else if (token == "FRAGMENT")
			return GL_FRAGMENT_SHADER;
		
		LOG_ERROR("Shader token error: Shader Type '" << token << "' not recognized.");
		return 0;
	}

	void Shader::SetupShaders(std::vector<std::pair<uint32_t, std::string>> parsedShaders)
	{	// Create GL Shader Program
		m_ID = glCreateProgram();

		// Compile OpenGL shaders
		for (auto& p : parsedShaders)
		{
			switch (p.first)
			{
			case (GL_VERTEX_SHADER):
				m_VertID = CompileShader(GL_VERTEX_SHADER, p.second.c_str());
				glAttachShader(m_ID, m_VertID);
				break;

			case (GL_FRAGMENT_SHADER):
				m_FragID = CompileShader(GL_FRAGMENT_SHADER, p.second.c_str());
				glAttachShader(m_ID, m_FragID);
				break;
			}
		}

		// Link and check for errors
		glLinkProgram(m_ID);

		int success;
		char infoLog[512];
		glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(m_ID, 512, nullptr, infoLog);
			LOG_ERROR("Shader program linking failed!\n" << infoLog);
		}

		// Delete shaders
		glDeleteShader(m_VertID);
		glDeleteShader(m_FragID);

	}

	std::vector<std::pair<uint32_t, std::string>> Shader::ParseShaderSources(std::string shaderSource)
	{

		std::vector<std::pair<GLenum, std::string>> sources;

		// Delimiters for finding shader type tokens
		std::string del = "${";
		std::string delEnd = "}";

		// Loop through loaded file
		size_t pos = shaderSource.find(del);
		while (pos != std::string::npos)
		{
			pos += del.length(); // account for the size of the delimiter
			// Find end of line
			size_t lineEnd = shaderSource.find("\n", pos);
			if (lineEnd == std::string::npos)
			{
				LOG_ERROR("Shader parsing SyntaxError: Unexpected EOF after shader type token");
			}
			// Find end of token
			size_t tEndPos = shaderSource.find(delEnd, pos);
			// Check that the end token was findable and also that it wasn't on a different line.
			if (tEndPos == std::string::npos || tEndPos > lineEnd)
			{	// SYNTAX ERROR
				LOG_ERROR("Shader parsing SyntaxError: '" << del << "' has no matching '" << delEnd << "'.");
			}
			// Store token and convert to uppercase
			std::string token(tEndPos - pos, (char)0); // allocate
			std::transform(shaderSource.begin() + pos, shaderSource.begin() + tEndPos, token.begin(), ::toupper);

			// Look for next token
			pos = shaderSource.find(del, pos);

			// Store sub string in sources
			std::string shaderCode = shaderSource.substr(lineEnd, pos - lineEnd);
			sources.push_back({ ShaderTypeFromToken(token),shaderCode });
		}

		return sources;
	}

	Shader::Shader(std::string vertexSource, std::string fragmentSource)
	{	// Wrapper for the private setup method
		std::vector<std::pair<uint32_t, std::string>> sources = {
			{GL_VERTEX_SHADER, vertexSource},
			{GL_FRAGMENT_SHADER, fragmentSource},
		};
		SetupShaders(sources);
	}

	Shader::Shader(std::string filePath)
	{
		// Load the file contents into a string
		std::string shaderSource = FileUtils::GetFileAsString(filePath);
		// Parse
		std::vector<std::pair<uint32_t, std::string>> sourcesParsed = ParseShaderSources(shaderSource);

		// Use existing constructor to do the rest
		SetupShaders(sourcesParsed);
	}

	Shader::~Shader()
	{	// Delete GL shader program
		glDeleteProgram(m_ID);
	}

	// API CREATE
	std::shared_ptr<Shader> Shader::Create(std::string vertexSource, std::string fragmentSource)
	{
		return std::make_shared<Shader>(vertexSource, fragmentSource);
	}

	std::shared_ptr<Shader> Shader::Create(std::string filePath)
	{
		return std::make_shared<Shader>(filePath);
	}

}

