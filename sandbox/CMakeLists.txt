project("sandbox")

add_executable(sandbox "src/sandbox.cpp" "src/sandbox.h")

target_include_directories(sandbox PRIVATE
	"${CMAKE_SOURCE_DIR}/core/include"
)
target_link_libraries(sandbox PRIVATE neptune_core)