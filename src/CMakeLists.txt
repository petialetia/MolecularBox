find_package (SDL2 REQUIRED)

add_subdirectory (GraphicAdapter)
add_subdirectory (TimerAdapter)

add_library (Shape         SHARED Shape.cpp)
add_library (Interaction   SHARED Interaction.cpp)
add_library (ObjectStorage SHARED ObjectStorage.cpp)

add_executable (MolecularBox MolecularBox.cpp)
target_link_libraries (MolecularBox SDL2GraphicFunctions SDL2GraphicImplementation)
target_link_libraries (MolecularBox SDL2TimerFunctions   SDL2TimerImplementation)
target_link_libraries (MolecularBox Shape Interaction ObjectStorage)
target_link_libraries (MolecularBox ${SDL2_LIBRARIES})