/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#include <gtest/gtest.h>
#include "Transformer.h"
#include "Weapon.h"
#include "Scope.h"
#include "Critic.h"
#include "Decepticon.h"

TEST(TransformerTest, CreationAndGetters) {
    Transformer transformer("Blazing Nova", 120, "Crimson", 150, "Plasma Cannon", 90);
    EXPECT_EQ(transformer.getName(), "Blazing Nova");
    EXPECT_EQ(transformer.getEnergyLevel(), 120);
    EXPECT_EQ(transformer.getColor(), "Crimson");
    EXPECT_EQ(transformer.getSpeed(), 150);
    EXPECT_EQ(transformer.getWeapon()->getType(), "Plasma Cannon");
    EXPECT_EQ(transformer.getWeapon()->getPower(), 90);
}

TEST(ScopeTest, CreationAndGetters) {
    Scope scope("sniper", 10, 4);  
    EXPECT_EQ(scope.getPower(), 10);
    EXPECT_EQ(scope.getType(), "Scope with zoom level 4x");
}

TEST(CriticTest, CreationAndCritique) {
    Critic critic("John Doe", 5);
    EXPECT_EQ(critic.critique(), "John Doe: Nice try, really.");
}

TEST(DecepticonTest, CreationAndGettersSetters) {
    Decepticon decepticon("Megatron", 100, "Silver", 120, "Laser Sword", 80, 90, "Bad Hair", "World Domination", "Jet", "F-22 Raptor");
    
    EXPECT_EQ(decepticon.getName(), "Megatron");
    EXPECT_EQ(decepticon.getAnnoyanceLevel(), 90);
    EXPECT_EQ(decepticon.getPreferredExcuse(), "Bad Hair");
    EXPECT_EQ(decepticon.getReasonForEvil(), "World Domination");
    EXPECT_EQ(decepticon.getVehicle().getType(), "Jet");
    EXPECT_EQ(decepticon.getVehicle().getModel(), "F-22 Raptor");

    decepticon.setAnnoyanceLevel(95);
    EXPECT_EQ(decepticon.getAnnoyanceLevel(), 95);
    decepticon.setPreferredExcuse("Traffic");
    EXPECT_EQ(decepticon.getPreferredExcuse(), "Traffic");
    decepticon.setReasonForEvil("Personal Vendetta");
    EXPECT_EQ(decepticon.getReasonForEvil(), "Personal Vendetta");
}

TEST(DecepticonTest, DisplayInfoWithVehicle) {
    Decepticon decepticon("Starscream", 80, "Gray", 100, "Thunder Blast", 70, 60, "Low Battery", "Revenge Plot", "Tank", "T-90");

    testing::internal::CaptureStdout();
    decepticon.displayInfo();
    
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Annoyance Level: 60/100") != std::string::npos);
    EXPECT_TRUE(output.find("Preferred Excuse for Losing: Low Battery") != std::string::npos);
    EXPECT_TRUE(output.find("Reason for Evilness: Revenge Plot") != std::string::npos);
    EXPECT_TRUE(output.find("Vehicle: Tank T-90") != std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
