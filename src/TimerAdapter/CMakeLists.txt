find_package(SDL2 REQUIRED)

add_library(SDL2TimerFunctions      STATIC SDL2TimerFunctions.cpp)
add_library(SDL2TimerImplementation STATIC SDL2TimerImplementation.cpp)

target_include_directories(SDL2TimerFunctions      PRIVATE ${SDL2_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include/TimerAdapter)
target_include_directories(SDL2TimerImplementation PRIVATE ${SDL2_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include/TimerAdapter)

target_link_libraries(SDL2TimerFunctions      ${SDL2_LIBRARIES})
target_link_libraries(SDL2TimerImplementation ${SDL2_LIBRARIES} SDL2TimerFunctions)