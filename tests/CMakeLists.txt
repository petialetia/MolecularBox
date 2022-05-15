find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(Tests MainTests.cpp CoordinatesTests.cpp CheckCollisionTests.cpp ProcessCollisionTests.cpp)
target_link_libraries (Tests ${GTEST_LIBRARIES} Threads::Threads ProcessCollision CheckCollision ObjectStorage Shape)