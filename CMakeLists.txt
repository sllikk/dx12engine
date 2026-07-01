cmake_minimum_required(VERSION 4.2.7)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Engine)

include(FetchContent) 

FetchContent_Declare(
	fmt
	GIT_REPOSITORY https://github.com/fmtlib/fmt.git
	GIT_TAG		   12.0.0 		
)

FetchContent_Declare(
	DirectXMath
	GIT_REPOSITORY https://github.com/microsoft/DirectXMath.git
	GIT_TAG		   may2026 		
)

FetchContent_Declare(
	DirectXTK12
	GIT_REPOSITORY https://github.com/microsoft/DirectXTK12.git
	GIT_TAG		   oct2025 		
)

FetchContent_Declare(
	DirectX-Headers
	GIT_REPOSITORY https://github.com/microsoft/DirectX-Headers.git
	GIT_TAG		   v1.616.0		
)

FetchContent_Declare(
	EASTL
	GIT_REPOSITORY https://github.com/electronicarts/EASTL.git
	GIT_TAG		   3.27.01 		
)


FetchContent_MakeAvailable(fmt DirectXMath DirectXTK12 DirectX-Headers EASTL)

set(PROJECT_SRC_FILES 
"src/engine.h" 
"src/engine.cpp" 
"src/utils.hpp" 
"src/timer.h" 
"src/render_utils.hpp" 
"src/eastl_mem.cpp" 
"src/dx12render.h" "src/timer.cpp"
"src/dx12render.cpp")
 
add_executable(Engine WIN32 ${PROJECT_SRC_FILES})

target_link_libraries(Engine PUBLIC d3d12 dxcompiler d3dcompiler dxgi dxguid d3dcompiler)
target_link_libraries(Engine PUBLIC fmt::fmt)
target_link_libraries(Engine PUBLIC DirectXMath)
target_link_libraries(Engine PUBLIC DirectXTK12)
target_link_libraries(Engine PUBLIC EASTL)
target_link_libraries(Engine PUBLIC DirectX-Headers)