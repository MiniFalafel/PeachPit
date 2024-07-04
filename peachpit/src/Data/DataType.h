#pragma once

#include <stdint.h>

#include "App/Core.h"

namespace Peach
{

	enum class DataType : uint32_t
	{
		None = 0,
		Float, Int, Bool,
		Vec2, Vec3, Vec4,
		iVec2, iVec3, iVec4,
		Mat3, Mat4
	};

	inline uint32_t DataTypeSizeof(const DataType& type) {
		switch (type) {
		case DataType::None:
			ASSERT(false, "DataType None is not valid!");
			return 0;
		case DataType::Float:	return 4;
		case DataType::Int:		return 4;
		case DataType::Bool:	return 1;
		case DataType::Vec2:	return 8;
		case DataType::Vec3:	return 12;
		case DataType::Vec4:	return 16;
		case DataType::iVec2:	return 8;
		case DataType::iVec3:	return 12;
		case DataType::iVec4:	return 16;
		case DataType::Mat3:	return 36;
		case DataType::Mat4:	return 64;
		}
		ASSERT(false, "Unknown DataType!");
		return 0;
	}

	inline unsigned int GetOpenGLDataType(const DataType& type) {
		switch (type) {
		case DataType::None:
			ASSERT(false, "DataType None is not valid!");
			return 0;
		case DataType::Float:	return 0x1406; // These values are taken directly from the GL.h header file in glad. Didn't want to include glad in a header file.
		case DataType::Int:		return 0x1404;
		case DataType::Bool:	return 0x1404;
		case DataType::Vec2:	return 0x1406;
		case DataType::Vec3:	return 0x1406;
		case DataType::Vec4:	return 0x1406;
		case DataType::iVec2:	return 0x1404;
		case DataType::iVec3:	return 0x1404;
		case DataType::iVec4:	return 0x1404;
		case DataType::Mat3:	return 0x1406;
		case DataType::Mat4:	return 0x1406;
		}
		ASSERT(false, "Unknown DataType!");
		return 0;
	}

	inline const uint32_t DataTypeElementCount(const DataType& type) {
		switch (type) {
		case DataType::None:
			ASSERT(false, "DataType None is not valid!");
			return 0;
		case DataType::Float:	return 1;
		case DataType::Int:		return 1;
		case DataType::Bool:	return 1;
		case DataType::Vec2:	return 2;
		case DataType::Vec3:	return 3;
		case DataType::Vec4:	return 4;
		case DataType::iVec2:	return 2;
		case DataType::iVec3:	return 3;
		case DataType::iVec4:	return 4;
		case DataType::Mat3:	return 9;
		case DataType::Mat4:	return 16;
		}
		ASSERT(false, "Unknown DataType!");
		return 0;
	}

}
