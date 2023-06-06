#pragma once

#include <string>
#include <iostream>

#ifdef NEPTUNE_ENABLE_LOGGING
	#define LOG_INFO(message) std::cout << "\x1B[37m" << message << "\x1B[0m" << std::endl
	#define LOG_WARNING(message) std::cout << "\x1B[33m" << message << "\x1B[0m" << std::endl
	#define LOG_ERROR(message) std::cout << "\x1B[31m" << message << "\x1B[0m" << std::endl
#else
	#define LOG_INFO(...)
	#define LOG_WARNING(...)
	#define LOG_ERROR(...)
#endif
