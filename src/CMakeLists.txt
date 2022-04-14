add_subdirectory(GraphicAdapter)
add_subdirectory(TimerAdapter)

add_library(Shape         STATIC Shape.cpp)
add_library(Interaction   STATIC Interaction.cpp)
add_library(ObjectStorage STATIC ObjectStorage.cpp)

add_executable(MolecularBox MolecularBox.cpp)
target_link_libraries(MolecularBox SDL2GraphicFunctions SDL2GraphicImplementation)
target_link_libraries(MolecularBox SDL2TimerFunctions   SDL2TimerImplementation)
target_link_libraries(MolecularBox Shape Interaction ObjectStorage)