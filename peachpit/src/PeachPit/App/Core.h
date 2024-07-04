#pragma once

#include "PeachPit/App/Log.h"

// Assertions
#define ASSERT(x, msg) if(!(x)) { LOG_ERROR(msg) }
