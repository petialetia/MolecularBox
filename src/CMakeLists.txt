add_library (Shape SHARED Shape.cpp)
add_library (Interaction SHARED Interaction.cpp)

add_executable (MolecularBox MolecularBox.cpp)
target_link_libraries (MolecularBox Shape Interaction)