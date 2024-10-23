#include <gtest/gtest.h>
#include "transformer.h"  // Include your class implementation file

// Test case for the Transformer class
TEST(TransformerTest, ConstructorAndGetters) {
    Transformer transformer("Optimus Prime", 100, "Red", 120);

    EXPECT_EQ(transformer.getName(), "Optimus Prime");
    EXPECT_EQ(transformer.getEnergyLevel(), 100);
    EXPECT_EQ(transformer.getColor(), "Red");
    EXPECT_EQ(transformer.getSpeed(), 120);
}

TEST(TransformerTest, Setters) {
    Transformer transformer("Optimus Prime", 100, "Red", 120);
    transformer.setName("Bumblebee");
    transformer.setEnergyLevel(90);
    transformer.setColor("Yellow");
    transformer.setSpeed(130);

    EXPECT_EQ(transformer.getName(), "Bumblebee");
    EXPECT_EQ(transformer.getEnergyLevel(), 90);
    EXPECT_EQ(transformer.getColor(), "Yellow");
    EXPECT_EQ(transformer.getSpeed(), 130);
}

// Test case for the Autobot class
TEST(AutobotTest, ConstructorAndGetters) {
    Autobot autobot("Optimus Prime", 100, "Red", 120, "Ultra Magnus", 50);

    EXPECT_EQ(autobot.getName(), "Optimus Prime");
    EXPECT_EQ(autobot.getEnergyLevel(), 100);
    EXPECT_EQ(autobot.getCommanderName(), "Ultra Magnus");
    EXPECT_EQ(autobot.getMissionCount(), 50);
}

TEST(AutobotTest, Setters) {
    Autobot autobot("Optimus Prime", 100, "Red", 120, "Ultra Magnus", 50);
    autobot.setCommanderName("Bumblebee");
    autobot.setMissionCount(75);

    EXPECT_EQ(autobot.getCommanderName(), "Bumblebee");
    EXPECT_EQ(autobot.getMissionCount(), 75);
}

// Test case for the Decepticon class
TEST(DecepticonTest, ConstructorAndGetters) {
    Decepticon decepticon("Megatron", 90, "Gray", 90, 75, "The WiFi signal was weak", "Because world domination is a hobby!");

    EXPECT_EQ(decepticon.getName(), "Megatron");
    EXPECT_EQ(decepticon.getEnergyLevel(), 90);
    EXPECT_EQ(decepticon.getAnnoyanceLevel(), 75);
    EXPECT_EQ(decepticon.getPreferredExcuse(), "The WiFi signal was weak");
}

TEST(DecepticonTest, Setters) {
    Decepticon decepticon("Megatron", 90, "Gray", 90, 75, "The WiFi signal was weak", "Because world domination is a hobby!");
    decepticon.setPreferredExcuse("I've just exersised");
    decepticon.setAnnoyanceLevel(85);

    EXPECT_EQ(decepticon.getPreferredExcuse(), "I've just exersised");
    EXPECT_EQ(decepticon.getAnnoyanceLevel(), 85);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
