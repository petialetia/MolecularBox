cmake_minimum_required (VERSION 3.2)

project (MolecularBox)

set (CMAKE_CXX_STANDARD 20)

set (CMAKE_SHARED_LIBRARY_PREFIX "")
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set (EXECUTABLE_OUTPUT_PATH, ${PROJECT_SOURCE_DIR}/bin)

add_executable (MolecularBox src/MolecularBox.cpp)