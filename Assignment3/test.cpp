#include <gtest/gtest.h>
#include "Transformer.h"
#include "Weapon.h"

// Test for Transformer class
TEST(TransformerTest, CreationAndGetters) {
    Transformer transformer("Blazing Nova", 120, "Crimson", 150, "Plasma Cannon", 90);
    
    EXPECT_EQ(transformer.getName(), "Blazing Nova");
    EXPECT_EQ(transformer.getEnergyLevel(), 120);
    EXPECT_EQ(transformer.getColor(), "Crimson");
    EXPECT_EQ(transformer.getSpeed(), 150);
    EXPECT_EQ(transformer.getWeapon()->getType(), "Plasma Cannon");
    EXPECT_EQ(transformer.getWeapon()->getPower(), 90);
}

TEST(TransformerTest, Setters) {
    Transformer transformer("Stormbreaker", 80, "Electric Blue", 130, "Thunder Blaster", 75);

    transformer.setName("Lightning Striker");
    transformer.setEnergyLevel(100);
    transformer.setColor("Neon Green");
    transformer.setSpeed(140);

    EXPECT_EQ(transformer.getName(), "Lightning Striker");
    EXPECT_EQ(transformer.getEnergyLevel(), 100);
    EXPECT_EQ(transformer.getColor(), "Neon Green");
    EXPECT_EQ(transformer.getSpeed(), 140);
}

// Test for displayInfo method (output capturing)
TEST(TransformerTest, DisplayInfo) {
    Transformer transformer("Shadow Phantom", 90, "Midnight Black", 110, "Void Ray", 85);
    
    testing::internal::CaptureStdout();
    transformer.displayInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Transformer: Shadow Phantom") != std::string::npos);
    EXPECT_TRUE(output.find("Energy Level: 90") != std::string::npos);
    EXPECT_TRUE(output.find("Color: Midnight Black") != std::string::npos);
    EXPECT_TRUE(output.find("Speed: 110 km/h") != std::string::npos);
}

// Main function for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
