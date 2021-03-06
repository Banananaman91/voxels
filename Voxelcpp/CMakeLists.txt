cmake_minimum_required(VERSION 3.0.0)
project(voxelcpp VERSION 0.1.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(CTest)
enable_testing()

find_package(glad 0.1.30 REQUIRED
  COMPONENTS
    REPRODUCIBLE
    SPEC gl
    PROFILE core
    API gl=4.0,gles2=3.0
)

find_package(GLFW 3.2.1 REQUIRED)

set(project_sources ProjectMain/main.cpp ProjectMain/WindowRender.cpp FReader/FileReader.cpp Renderer/RenderCube.cpp Renderer/Shader.cpp ProjectMain/Camera.cpp)
set(project_headers ProjectMain/MainHeader.h ProjectMain/WindowRender.h FReader/FileReader.h Renderer/RenderCube.h Renderer/Shader.h ProjectMain/Camera.h Renderer/Vertex.h)

add_executable(voxelcpp 
    ${project_sources}
    ${project_headers}
)

add_subdirectory(Shaders)

target_link_libraries(voxelcpp PUBLIC Glad::GLAD GLFW::GLFW3)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_custom_command(
  TARGET voxelcpp POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    $<TARGET_FILE_DIR:Shaders>
    $<TARGET_FILE_DIR:voxelcpp>/Shaders
)