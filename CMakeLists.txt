project(test_gdal)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic -fPIC")


find_package(GDAL REQUIRED)

include_directories(${GDAL_INCLUDE_DIR})

# compile first executable
add_executable(openFile ${CMAKE_CURRENT_SOURCE_DIR}/src/open_file.cc)
target_link_libraries(openFile ${GDAL_LIBRARY})

add_executable(dataInfo ${CMAKE_CURRENT_SOURCE_DIR}/src/get_dataset_info.cc)
target_link_libraries(dataInfo ${GDAL_LIBRARY})

add_executable(geo_pix_transform ${CMAKE_CURRENT_SOURCE_DIR}/src/geo_pix_transform.cc)
target_link_libraries(geo_pix_transform ${GDAL_LIBRARY})

add_executable(create_dataset_self  src/driver_manager_test.cc)
target_link_libraries(create_dataset_self ${GDAL_LIBRARY})

add_executable(driver_manager src/driver_manager_test.cc)
target_link_libraries(driver_manager ${GDAL_LIBRARY})