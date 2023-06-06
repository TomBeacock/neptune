# Core
project("neptune-core")

add_library(neptune_core
	"src/application.h"
	"src/application.cpp"
	"src/window.h"
	"src/window.cpp" "src/assert.h" "src/log.h" )

set_property(TARGET neptune_core PROPERTY CXX_STANDARD 20)

target_include_directories(neptune_core PUBLIC
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/src"
)

string(TOLOWER ${CMAKE_BUILD_TYPE} build_type)
# Enable/disable logging
if(build_type STREQUAL debug OR build_type STREQUAL relwithdebinfo)
	target_compile_definitions(neptune_core PRIVATE NEPTUNE_ENABLE_LOGGING)
endif()

# Enable/disable assert
if(build_type STREQUAL debug)
	target_compile_definitions(neptune_core PRIVATE NEPTUNE_ENABLE_ASSERTS)
endif()

# GLFW
add_subdirectory("external/glfw")
target_link_libraries(neptune_core PRIVATE glfw)
target_include_directories(neptune_core PRIVATE "${CMAKE_SOURCE_DIR}/extern/glfw/include")

# Vulkan
find_package(Vulkan REQUIRED)
if (NOT Vulkan_FOUND)
	message(FATAL_ERROR "Vulkan not found")
else()
	message(STATUS "Vulkan found at: ${Vulkan_LIBRARIES}")
endif()

target_link_libraries(neptune_core PRIVATE "${Vulkan_LIBRARIES}")
target_include_directories(neptune_core PRIVATE "${Vulkan_INCLUDE_DIR}")