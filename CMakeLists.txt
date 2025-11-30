cmake_minimum_required(VERSION 3.10)
project(Voxel-3d-editor)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/lib/imgui)
set(BACKENDS_DIR ${CMAKE_SOURCE_DIR}/backends)
set(TOOLS_DIR ${CMAKE_SOURCE_DIR}/src/editor/tools)
set(DEBUG_DIR ${CMAKE_SOURCE_DIR}/src/editor/tools/debug)
set(CORE_DIR ${CMAKE_SOURCE_DIR}/src/core)

set(SOURCES
        ${SOURCE_DIR}/main.cpp
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${BACKENDS_DIR}/imgui_impl_glfw.cpp
        ${BACKENDS_DIR}/imgui_impl_opengl3.cpp
        ${TOOLS_DIR}/canvas.cpp
        ${DEBUG_DIR}/debug.cpp
        ${CORE_DIR}/application.cpp
        src/editor/tools/TreeDir.cpp
        src/editor/tools/TreeDir.h
)

add_executable(Voxel-3d-editor ${SOURCES})

target_include_directories(Voxel-3d-editor PRIVATE
        ${IMGUI_DIR}
        ${BACKENDS_DIR}
        ${TOOLS_DIR}
        ${CORE_DIR}
        ${DEBUG_DIR}
)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/glfw)

if (APPLE)
    target_link_libraries(Voxel-3d-editor
            "-framework OpenGL"
            "-framework Cocoa"
            "-framework IOKit"
            "-framework CoreVideo"
            glfw
    )
elseif (UNIX)
    target_link_libraries(Voxel-3d-editor glfw GL)
elseif (WIN32)
    target_link_libraries(Voxel-3d-editor glfw gdi32 opengl32 imm32)
endif ()