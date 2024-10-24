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

// Main function for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
