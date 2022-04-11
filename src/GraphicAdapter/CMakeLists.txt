find_package (SDL2 REQUIRED)

add_library (SDL2GraphicFunctions      STATIC SDL2GraphicFunctions.cpp)
add_library (SDL2GraphicImplementation STATIC SDL2GraphicImplementation.cpp)

target_include_directories (SDL2GraphicFunctions      PRIVATE ${SDL2_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include/GraphicAdapter)
target_include_directories (SDL2GraphicImplementation PRIVATE ${SDL2_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include/GraphicAdapter)

target_link_libraries(SDL2GraphicFunctions      ${SDL2_LIBRARIES})
target_link_libraries(SDL2GraphicImplementation ${SDL2_LIBRARIES})