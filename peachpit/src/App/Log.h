// This is so stupid for now, but maybe we can add something better in the future?
#pragma once

#include <iostream>

#define LOG_LEVEL 4 // 1: just errors, 2: 1 + warnings, 3: 2 + info, 4: 3 + notes

#define LOG_ERROR(msg) std::cout << "[ERROR]: " << msg << "\n"; __debugbreak();
#define LOG_WARN(msg)  if (LOG_LEVEL > 1) { std::cout << "[WARNING]: " << msg << "\n"; }
#define LOG_INFO(msg)  if (LOG_LEVEL > 2) { std::cout << "[INFO]: " << msg << "\n"; }
#define LOG_NOTE(msg)  if (LOG_LEVEL > 3) { std::cout << "[NOTE]: " << msg << "\n"; }

