/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
// TransformerTest.cpp
#include <gtest/gtest.h>
#include "City.h"
#include "Transformer.h"
#include "Advantage.h"
#include "Autobot.h"
#include "Minicon.h"
#include "Decepticon.h"

// Test for the Advantage class
TEST(AdvantageTest, PowerTest)
{
    Advantage advantage(100);
    EXPECT_EQ(advantage.getPower(), 100);

    advantage.setPower(50);
    EXPECT_EQ(advantage.getPower(), 50);
}

// Test for the City class
TEST(CityTest, BuildingManagement)
{
    City city;
    city.setBuildings(10);
    EXPECT_EQ(city.getBuildings(), 10);

    city.setBuildings(15);
    EXPECT_EQ(city.getBuildings(), 15);
}

// Test for the Transformer class
TEST(TransformerTest, TransformerCreation)
{
    Advantage blaster(100);
    Transformer transformer("Optimus Prime", 150, 80, blaster);

    EXPECT_EQ(transformer.getName(), "Optimus Prime");
    EXPECT_EQ(transformer.getPower(), 150);
    EXPECT_EQ(transformer.getSpeed(), 80);
    EXPECT_EQ(transformer.getEquipment().getPower(), 100);
}

TEST(TransformerTest, TransformerSurrender)
{
    Advantage blaster(100);
    Transformer transformer("Optimus Prime", 150, 80, blaster);

    transformer.surrender(transformer);

    EXPECT_EQ(transformer.getName(), "scrap-metal");
    EXPECT_EQ(transformer.getPower(), 0);
    EXPECT_EQ(transformer.getSpeed(), 0);
    EXPECT_EQ(transformer.getEquipment().getPower(), 0);
}

TEST(TransformerTest, TransformerAttack)
{
    Advantage blaster(50);
    Transformer transformer("Bumblebee", 100, 60, blaster);

    City city;
    city.setBuildings(10);

    transformer.attack(city);

    EXPECT_EQ(city.getBuildings(), 110);
}

// Test for the Autobot class
TEST(AutobotTest, AutobotCreation)
{
    Advantage blaster(200);
    Autobot autobot("Jazz", 120, 90, blaster, "Optimus Prime", "Protect humanity");

    EXPECT_EQ(autobot.getName(), "Jazz");
    EXPECT_EQ(autobot.getPower(), 120);
    EXPECT_EQ(autobot.getSpeed(), 90);
    EXPECT_EQ(autobot.getEquipment().getPower(), 200);
    EXPECT_EQ(autobot.getCommander(), "Optimus Prime");
    EXPECT_EQ(autobot.getReasonForKindness(), "Protect humanity");
}

TEST(AutobotTest, CallCommander)
{
    Advantage blaster(200);
    Autobot autobot("Jazz", 120, 90, blaster, "Optimus Prime", "Protect humanity");

    // No assertion, but this ensures the method runs without crashing
    autobot.callComander();
}

// Test Constructor and Getter Methods
TEST(MiniconTest, ConstructorAndGetters)
{
    Advantage advantage(100); // Create Advantage object with power 100
    Minicon minicon("MiniBot", 50, 30, advantage, "Optimus Prime", "Save Earth");

    // Test the name, power, speed, and master
    EXPECT_EQ(minicon.getName(), "MiniBot");
    EXPECT_EQ(minicon.getPower(), 50);
    EXPECT_EQ(minicon.getSpeed(), 30);
    EXPECT_EQ(minicon.getMaster(), "Optimus Prime");
    EXPECT_EQ(minicon.getExistanceObligation(), "Save Earth");

    // Test the advantage power
    EXPECT_EQ(minicon.getEquipment().getPower(), 100);
}

// Test Setters and Modifying Values
TEST(MiniconTest, Setters)
{
    Advantage advantage(100);
    Minicon minicon("MiniBot", 50, 30, advantage, "Optimus Prime", "Save Earth");

    // Modify the values
    minicon.setMaster("Megatron");
    minicon.setExistanceObligation("Destroy Earth");
    minicon.setSpeed(40);
    minicon.setPower(60);

    // Test if values are updated
    EXPECT_EQ(minicon.getMaster(), "Megatron");
    EXPECT_EQ(minicon.getExistanceObligation(), "Destroy Earth");
    EXPECT_EQ(minicon.getSpeed(), 40);
    EXPECT_EQ(minicon.getPower(), 60);
}

// Test the `callMaster` method (printing output)
TEST(MiniconTest, CallMaster)
{
    Advantage advantage(100);
    Minicon minicon("MiniBot", 50, 30, advantage, "Optimus Prime", "Save Earth");

    // Capture the output of `callMaster()`
    testing::internal::CaptureStdout();
    minicon.callMaster();
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the output is as expected
    EXPECT_EQ(output, "Optimus Prime, I'll repair you!!!\n");
}

// Test Constructor and Getter Methods
TEST(DecepticonTest, ConstructorAndGetters)
{
    Advantage advantage(100); // Create Advantage object with power 100
    Decepticon decepticon("Megatron", 200, 150, advantage, "Optimus Prime", "World Domination");

    // Test the name, power, speed, enemy, and reason for evilness
    EXPECT_EQ(decepticon.getName(), "Megatron");
    EXPECT_EQ(decepticon.getPower(), 200);
    EXPECT_EQ(decepticon.getSpeed(), 150);
    EXPECT_EQ(decepticon.getEnemy(), "Optimus Prime");
    EXPECT_EQ(decepticon.getReasonForevilness(), "World Domination");

    // Test the advantage power
    EXPECT_EQ(decepticon.getEquipment().getPower(), 100);
}

// Test Setters and Modifying Values
TEST(DecepticonTest, Setters)
{
    Advantage advantage(100);
    Decepticon decepticon("Megatron", 200, 150, advantage, "Optimus Prime", "World Domination");

    // Modify the values using setter methods
    decepticon.setEnemy("Bumblebee");
    decepticon.setReasonForevilness("Revenge");
    decepticon.setSpeed(180);
    decepticon.setPower(250);

    // Test if values are updated
    EXPECT_EQ(decepticon.getEnemy(), "Bumblebee");
    EXPECT_EQ(decepticon.getReasonForevilness(), "Revenge");
    EXPECT_EQ(decepticon.getSpeed(), 180);
    EXPECT_EQ(decepticon.getPower(), 250);
}

// Test the `threatenTheEnemy` method (printing output)
TEST(DecepticonTest, ThreatenTheEnemy)
{
    Advantage advantage(100);
    Decepticon decepticon("Megatron", 200, 150, advantage, "Optimus Prime", "World Domination");

    // Capture the output of `threatenTheEnemy()`
    testing::internal::CaptureStdout();
    decepticon.threatenTheEnemy();
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the output is as expected
    EXPECT_EQ(output, "Optimus Prime, I'll destroy you!!!\n");
}
