cmake_minimum_required(VERSION 3.16)

project(wearable_ui_demo LANGUAGES C CXX)

# Basic project-wide settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build example/demo folders when available" OFF)

#When using the simulator include SDL
if(LV_USE_SDL)
  message(STATUS "Including SDL2 for simulator")
  find_package(SDL2 REQUIRED)
  include_directories(${SDL2_INCLUDE_DIRS})
endif()

# If you have a top-level app/source folder add it here: e.g. src/ or examples/
if(BUILD_EXAMPLES AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/examples/CMakeLists.txt")
  message(STATUS "Adding examples subproject")
  add_subdirectory(examples)
endif()

add_subdirectory(lvgl)
add_subdirectory(widgets)
add_subdirectory(screens)
add_subdirectory(utilities)

add_executable(wearable_ui_demo WearableUI.cpp)
target_link_libraries(wearable_ui_demo lvgl widgets screens utilities ${SDL2_LIBRARIES})

