#pragma once

#include "PeachPit/App/Core.h"

#include <string>
#include <fstream>

namespace Peach
{

	class FileUtils
	{

	public:

		static std::string GetFileAsString(std::string filePath)
		{
			// Load the contents of the file into a string
			std::ifstream stream(filePath);
			// Check if opening was successful
			if (!stream.is_open())
			{
				LOG_ERROR("Failed to open file: " << filePath);
			}
			// loop through the lines and store them
			std::string fileContents;
			std::string line;
			while (std::getline(stream, line))
			{
				fileContents += line + "\n";
			}
			// close the filestream
			stream.close();

			return fileContents;
		}

	};

}
