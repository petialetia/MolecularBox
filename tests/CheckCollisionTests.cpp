#include <gtest/gtest.h>

#include <CheckCollision.hpp>

TEST(CheckCollision, Touching)
{
    ObjectStorage object_storage;
    auto first_object_id  = object_storage.AddObject(Circle(20), object_coordinates({0, 0}),  color({255, 255, 255, 255}), 1, speed_type({20, 0}));
    auto second_object_id = object_storage.AddObject(Circle(20), object_coordinates({40, 0}), color({255, 255, 255, 255}), 1, speed_type({0,  0}));

    const auto& first_object  = std::get<Circle>(object_storage.GetObject(first_object_id));
    const auto& second_object = std::get<Circle>(object_storage.GetObject(second_object_id));

    EXPECT_EQ(CheckCollision(ObjectInfo(first_object, first_object_id, object_storage), ObjectInfo(second_object, second_object_id, object_storage)), true);
}

TEST(CheckCollision, Penetration)
{
    ObjectStorage object_storage;
    auto first_object_id  = object_storage.AddObject(Circle(20), object_coordinates({0, 0}),   color({255, 255, 255, 255}), 1, speed_type({0, 0}));
    auto second_object_id = object_storage.AddObject(Circle(20), object_coordinates({20, 0}),  color({255, 255, 255, 255}), 1, speed_type({0, 0}));
    auto third_object_id  = object_storage.AddObject(Circle(20), object_coordinates({10, 10}), color({255, 255, 255, 255}), 1, speed_type({0, 0}));

    const auto& first_object  = std::get<Circle>(object_storage.GetObject(first_object_id));
    const auto& second_object = std::get<Circle>(object_storage.GetObject(second_object_id));
    const auto& third_object  = std::get<Circle>(object_storage.GetObject(third_object_id));

    EXPECT_EQ(CheckCollision(ObjectInfo(first_object, first_object_id, object_storage), ObjectInfo(second_object, second_object_id, object_storage)), true);
    EXPECT_EQ(CheckCollision(ObjectInfo(first_object, first_object_id, object_storage), ObjectInfo(third_object,  third_object_id,  object_storage)), true);
    EXPECT_EQ(CheckCollision(ObjectInfo(third_object, third_object_id, object_storage), ObjectInfo(second_object, second_object_id, object_storage)), true);
}

TEST(CheckCollision, NoCollision1)
{
    ObjectStorage object_storage;
    auto first_object_id  = object_storage.AddObject(Circle(20), object_coordinates({40,  40}), color({255, 255, 255, 255}), 1, speed_type({10, 10}));
    auto second_object_id = object_storage.AddObject(Circle(20), object_coordinates({-40, 40}), color({255, 255, 255, 255}), 1, speed_type({0,  10}));
    auto third_object_id  = object_storage.AddObject(Circle(20), object_coordinates({40, -40}), color({255, 255, 255, 255}), 1, speed_type({0,  0}));

    const auto& first_object  = std::get<Circle>(object_storage.GetObject(first_object_id));
    const auto& second_object = std::get<Circle>(object_storage.GetObject(second_object_id));
    const auto& third_object  = std::get<Circle>(object_storage.GetObject(third_object_id));

    EXPECT_EQ(CheckCollision(ObjectInfo(first_object, first_object_id, object_storage), ObjectInfo(second_object, second_object_id, object_storage)), false);
    EXPECT_EQ(CheckCollision(ObjectInfo(first_object, first_object_id, object_storage), ObjectInfo(third_object,  third_object_id,  object_storage)), false);
    EXPECT_EQ(CheckCollision(ObjectInfo(third_object, third_object_id, object_storage), ObjectInfo(second_object, second_object_id, object_storage)), false);
}

TEST(CheckCollision, NoCollision2)
{
    ObjectStorage object_storage;
    auto first_object_id  = object_storage.AddObject(Circle(10), object_coordinates({0, 0}),  color({255, 255, 255, 255}), 1, speed_type({20,  0}));
    auto second_object_id = object_storage.AddObject(Circle(10), object_coordinates({60, 0}), color({255, 255, 255, 255}), 1, speed_type({-20, 0}));

    const auto& first_object  = std::get<Circle>(object_storage.GetObject(first_object_id));
    const auto& second_object = std::get<Circle>(object_storage.GetObject(second_object_id));

    EXPECT_EQ(CheckCollision(ObjectInfo(first_object, first_object_id, object_storage), ObjectInfo(second_object, second_object_id, object_storage)), false);
}