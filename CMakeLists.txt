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
	GIT_TAG		   may2026 		
)

FetchContent_Declare(
	DirectX-Headers
	GIT_REPOSITORY https://github.com/microsoft/DirectX-Headers.git
	GIT_TAG		   v1.619.1 		
)


FetchContent_MakeAvailable(fmt DirectXMath DirectXTK12 DirectX-Headers)
 
add_executable(Engine WIN32 "src/Engine.h" "src/Engine.cpp")
target_link_libraries(Engine PUBLIC d3d12 dxcompiler dxgi dxguid)

target_link_libraries(Engine PUBLIC fmt::fmt)
target_link_libraries(Engine PUBLIC DirectXMath)
target_link_libraries(Engine PUBLIC DirectXTK12)