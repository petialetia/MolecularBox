#include <gtest/gtest.h>

#include <CheckCollision.hpp>

TEST(CheckCollision, Accuracy)
{
    ObjectStorage object_storage;
    auto first_object_id  = object_storage.AddObject(Circle(20), object_coordinates({0, 0}),  color({255, 255, 255, 255}), 1, speed_type({20, 0}));
    auto second_object_id = object_storage.AddObject(Circle(20), object_coordinates({40, 0}), color({255, 255, 255, 255}), 1, speed_type({0,  0}));

    const auto& first_object  = std::get<Circle>(object_storage.GetObject(first_object_id));
    const auto& second_object = std::get<Circle>(object_storage.GetObject(second_object_id));

    EXPECT_EQ(CheckCollision(ObjectInfo(first_object,  first_object_id,  object_storage), ObjectInfo(second_object, second_object_id, object_storage)), true);
}