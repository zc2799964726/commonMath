cmake_minimum_required(VERSION 3.21)

project(Tests)

if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Od")
endif()

include(CTest)
include(GoogleTest)
set(BUILD_GMOCK ON)
set(INSTALL_GTEST OFF)
add_subdirectory(googletest-1.14.0)

#execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/../TestData ${ECAD_DEPENDENCIES_DEST}/TestData)

add_executable(Tests
  TestMain.cpp
)

target_include_directories(Tests SYSTEM PRIVATE
  $<TARGET_PROPERTY:gtest,INCLUDE_DIRECTORIES>
  # now this line is saved because CommonManth has itself's target_include_directories()
  #$<TARGET_PROPERTY:CommonManth::CommonManth,INCLUDE_DIRECTORIES>
)

target_link_libraries(Tests
  gtest
  CommonMath::CommonMath
  )

if (WIN32)
  enable_testing()
  gtest_discover_tests(Tests
  )
endif()
