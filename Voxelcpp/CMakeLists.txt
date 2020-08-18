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

set(project_sources main.cpp WindowRender.cpp RenderTriangle.cpp)
set(project_headers WindowRender.h RenderTriangle.h)

add_executable(voxelcpp 
    ${project_sources}
    ${project_headers}
)

target_link_libraries(voxelcpp PUBLIC Glad::GLAD GLFW::GLFW3)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
