cmake_minimum_required(VERSION 3.21)

project(Tests)

include(CTest)
include(GoogleTest)
set(BUILD_GMOCK ON)
set(INSTALL_GTEST OFF)
add_subdirectory(googletest-1.14.0)

add_executable(Tests
  TestMain.cpp
  TestComplex.cpp
)

target_link_libraries(Tests
  gtest
  CommonMath::CommonMath
  )

gtest_discover_tests(Tests)
