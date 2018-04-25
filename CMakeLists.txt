project(test_gdal)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic -fPIC")

#GDAL
find_package(GDAL REQUIRED)
include_directories(${GDAL_INCLUDE_DIR})


#TEST
add_subdirectory(vendor/googletest)
include_directories(vendor/googletest/googletest/include)
file(GLOB TEST_SRC test/*.cc)
add_executable(unit_test ${TEST_SRC})
target_link_libraries(unit_test gtest_main)