#pragma once

#include "log.h"

#ifdef NEPTUNE_ENABLE_ASSERTS
	#define ASSERT(check, message) { if(check) { LOG_ERROR(message); } }
#else
	#define ASSERT(...)
#endif