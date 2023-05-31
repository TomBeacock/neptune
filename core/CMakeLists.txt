project("neptune-core")

add_subdirectory("extern")

add_library(neptune_core
	"src/application.h"
	"src/application.cpp"
 "src/window.h" "src/window.cpp")

set_property(TARGET neptune_core PROPERTY CXX_STANDARD 20)

target_include_directories(neptune_core PUBLIC
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/src"
	"${CMAKE_SOURCE_DIR}/extern/glfw/include"
)
target_link_libraries(neptune_core PRIVATE glfw)