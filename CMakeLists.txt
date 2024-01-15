cmake_minimum_required(VERSION 3.21)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(CommonManth)


if (WIN32)
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED True)
  add_library(${PROJECT_NAME} SHARED
    "source/Complex.cpp"
  )

  target_link_directories(${PROJECT_NAME} PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  )

  add_library(CommonManth::CommonManth ALIAS ${PROJECT_NAME})
  target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

elseif(LINUX)
  message(FATAL_ERROR "Targeting Linux not implemented")
elseif(ANDROID)
  message(FATAL_ERROR "Targeting Android not implemented")
endif()