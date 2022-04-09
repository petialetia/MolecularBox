find_package (SDL2 REQUIRED)

add_library (SDL2GraphicAdapter SHARED SDL2GraphicAdapter.cpp)
add_library (Shape              SHARED Shape.cpp)
add_library (Interaction        SHARED Interaction.cpp)
add_library (ObjectStorage      SHARED ObjectStorage.cpp)

add_executable (MolecularBox MolecularBox.cpp)
target_link_libraries (MolecularBox SDL2GraphicAdapter Shape Interaction ObjectStorage ${SDL2_LIBRARIES})