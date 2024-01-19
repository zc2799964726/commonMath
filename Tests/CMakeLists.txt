cmake_minimum_required(VERSION 3.21)

project(Tests)

include(CTest)
include(GoogleTest)
set(BUILD_GMOCK ON)
set(INSTALL_GTEST OFF)
add_subdirectory(googletest-1.14.0)

#execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/../TestData ${ECAD_DEPENDENCIES_DEST}/TestData)

add_executable(Tests
  TestMain.cpp
  TestComplex.cpp
)

target_include_directories(Tests SYSTEM PRIVATE
  $<TARGET_PROPERTY:gtest,INCLUDE_DIRECTORIES>
  # now this line is saved because CommonManth has itself's target_include_directories()
  # $<TARGET_PROPERTY:CommonMath::CommonMath,INCLUDE_DIRECTORIES>
)

target_link_libraries(Tests
  gtest
  CommonMath
  )

gtest_discover_tests(Tests)
