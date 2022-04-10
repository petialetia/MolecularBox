cmake_minimum_required (VERSION 3.7)

project (MolecularBox)

set (CMAKE_CXX_STANDARD 20)

include_directories (${PROJECT_SOURCE_DIR}/include)

set (CMAKE_EXECUTABLE_SUFFIX ".out")
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set (CMAKE_SHARED_LIBRARY_PREFIX "")
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory (src)