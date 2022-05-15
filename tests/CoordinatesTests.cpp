#include <gtest/gtest.h>

#include <Coordinates.hpp>

TEST(Coordinates, CountProjection)
{
    EXPECT_EQ(CountProjection(Coordinates({20.0, 0.0}), Coordinates({20.0, 0.0})), Coordinates({20.0, 0.0}));
    EXPECT_EQ(CountProjection(Coordinates({20.0, 0.0}), Coordinates({1.0, 0.0})), Coordinates({20.0, 0.0}));

    EXPECT_EQ(CountProjection(Coordinates({20.0, 0.0}), Coordinates({-1.0, 0.0})), Coordinates({20.0, 0.0}));
    
    EXPECT_EQ(CountProjection(Coordinates({3.0, 4.0}), Coordinates({3.0, 0.0})), Coordinates({3.0, 0.0}));

    EXPECT_EQ(CountProjection(Coordinates({0.0, 4.0}), Coordinates({3.0, 0.0})), Coordinates({0.0, 0.0}));

    EXPECT_EQ(CountProjection(Coordinates({0.0, 0.0}), Coordinates({3.0, 4.0})), Coordinates({0.0, 0.0}));
}

TEST(Coordinates, IsCodirectional)
{
    EXPECT_EQ(IsCodirectional(Coordinates({20.0, 0.0}), Coordinates({20.0, 0.0})), true);
    EXPECT_EQ(IsCodirectional(Coordinates({20.0, 0.0}), Coordinates({-20.0, 0.0})), false);

    EXPECT_EQ(IsCodirectional(Coordinates({40.0, 0.0}),  Coordinates({20.0, 0.0})), true);
    EXPECT_EQ(IsCodirectional(Coordinates({40.0, 20.0}), Coordinates({20.0, 10.0})), true);

    EXPECT_EQ(IsCodirectional(Coordinates({40.0, 20.0}), Coordinates({20.0, 0.0})), false);

    EXPECT_EQ(IsCodirectional(Coordinates({0.0,  20.0}), Coordinates({20.0, 0.0})),  false);
    EXPECT_EQ(IsCodirectional(Coordinates({20.0, 20.0}), Coordinates({20.0, 0.0})),  false);
    EXPECT_EQ(IsCodirectional(Coordinates({30.0, 20.0}), Coordinates({20.0, 30.0})), false);
}