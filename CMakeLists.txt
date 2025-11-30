cmake_minimum_required(VERSION 3.10)
project(voxel)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/lib/imgui)
set(BACKENDS_DIR ${CMAKE_SOURCE_DIR}/backends)

set(SOURCES
        ${SOURCE_DIR}/main.cpp
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${BACKENDS_DIR}/imgui_impl_glfw.cpp
        ${BACKENDS_DIR}/imgui_impl_opengl3.cpp
)


add_executable(voxel ${SOURCES})

target_include_directories(voxel PRIVATE
        ${IMGUI_DIR}
        ${BACKENDS_DIR}
)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/glfw)

if (APPLE)
    target_link_libraries(voxel
            "-framework OpenGL"
            "-framework Cocoa"
            "-framework IOKit"
            "-framework CoreVideo"
            glfw
    )
elseif (UNIX)
    target_link_libraries(voxel glfw GL)
elseif (WIN32)
    target_link_libraries(voxel glfw gdi32 opengl32 imm32)
endif ()