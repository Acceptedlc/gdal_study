project(test_gdal)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# set GDAL PATH
if (APPLE)
    find_package(GDAL REQUIRED)
endif (APPLE)
include_directories(${GDAL_INCLUDE_DIR})

# compile first executable
add_executable(openFile ${CMAKE_CURRENT_SOURCE_DIR}/src/open_file.cc)
target_link_libraries(openFile ${GDAL_LIBRARY})

add_executable(dataInfo ${CMAKE_CURRENT_SOURCE_DIR}/src/get_dataset_info.cc)
target_link_libraries(dataInfo ${GDAL_LIBRARY})

add_executable(geo_pix_transform ${CMAKE_CURRENT_SOURCE_DIR}/src/geo_pix_transform.cc)
target_link_libraries(geo_pix_transform ${GDAL_LIBRARY})