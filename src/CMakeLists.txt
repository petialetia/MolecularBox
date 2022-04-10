find_package (SDL2 REQUIRED)

include_directories (MolecularBox ${SDL2_INCLUDE_DIRS})

add_library (SDL2GraphicFunctions      SHARED SDL2GraphicFunctions.cpp)
add_library (SDL2GraphicImplementation SHARED SDL2GraphicImplementation.cpp)

add_library (Shape         SHARED Shape.cpp)
add_library (Interaction   SHARED Interaction.cpp)
add_library (ObjectStorage SHARED ObjectStorage.cpp)

add_executable (MolecularBox MolecularBox.cpp)
target_link_libraries (MolecularBox SDL2GraphicFunctions SDL2GraphicImplementation Shape Interaction ObjectStorage ${SDL2_LIBRARIES})