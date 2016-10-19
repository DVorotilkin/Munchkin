#include <QCoreApplication>
#include "../MunchkinLib/Entities/player.h"
#include "gtest/gtest.h"

TEST(CardTest, ClassTest)
{
    QJsonObject a;
    a["test"] = 1;
    QJsonObject b;
    b["test"] = "test";
    Class c1(1, "Test", "TestClassCard", Classes::Thief, a, b);
    QJsonObject json = c1.toJson();
    Class c2;
    c2.fromJson(json);
    EXPECT_EQ(c1.id(), c2.id());
    EXPECT_EQ(c1.name(), c2.name());
    EXPECT_EQ(c1.description(), c2.description());
    EXPECT_EQ(c1.type(), c2.type());
    EXPECT_EQ(c1.getClass(), c2.getClass());
    EXPECT_EQ(c1.ability1(), c2.ability1());
    EXPECT_EQ(c1.ability2(), c2.ability2());
    EXPECT_EQ(c1, c2);
    EXPECT_EQ(c1.toByteArray(), c2.toByteArray());
}

TEST(CardTest, RaceTest)
{
    QJsonObject b;
    b["test"] = "test";
    Race c1(1, "Test", "TestRaceCard", Races::Elf, b);
    QJsonObject json = c1.toJson();
    Race c2;
    c2.fromJson(json);
    EXPECT_EQ(c1.id(), c2.id());
    EXPECT_EQ(c1.name(), c2.name());
    EXPECT_EQ(c1.description(), c2.description());
    EXPECT_EQ(c1.type(), c2.type());
    EXPECT_EQ(c1.race(), c2.race());
    EXPECT_EQ(c1.ability(), c2.ability());
    EXPECT_EQ(c1, c2);
    EXPECT_EQ(c1.toByteArray(), c2.toByteArray());
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
