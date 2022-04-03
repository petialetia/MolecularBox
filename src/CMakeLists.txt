add_library (Object SHARED Object.cpp)
add_library (Interaction SHARED Interaction.cpp)

add_executable (MolecularBox MolecularBox.cpp)
target_link_libraries (MolecularBox Object Interaction)