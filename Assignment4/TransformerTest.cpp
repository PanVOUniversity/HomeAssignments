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

TEST(MiniconTest, OperatorOverloading)
{
    Minicon minicon("MiniBot", 50, 30, 100, "Optimus Prime", "Save Earth");

    std::stringstream ss;
    ss << minicon;

    std::string expected_output = "Name MiniBot, power 50, Advantage power: 100, Speed 30, existanse obligation: Save Earth, master: Optimus Prime";
    EXPECT_EQ(ss.str(), expected_output);
}


TEST(TransformerTest, OperatorOverloading)
{
    City city;
    city.setBuildings(10);
    Transformer transformer("Optimus Prime", 150, 80, 100, &city);

    std::stringstream ss;
    ss << transformer;

    std::string expected_output = "Name Optimus Prime, power 150, Advantage power: 100, Speed 80";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(DecepticonTest, OperatorOverloading)
{
    Decepticon decepticon("Megatron", 200, 150, 100, "Optimus Prime", "World Domination");

    std::stringstream ss;
    ss << decepticon;

    std::string expected_output = "Name Megatron, power 200, Advantage power: 100, Speed 150, reason for evilness: World Domination, enemyOptimus Prime";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(AutobotTest, OperatorOverloading)
{

    Autobot autobot("Jazz", 120, 90, 100, "Optimus Prime", "Protect humanity");

    std::stringstream ss;
    ss << autobot;

    std::string expected_output = "Name Jazz, power 120, Advantage power: 100, Speed 90, reason for kindness: Protect humanity, commander: Optimus Prime";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(TransformerOperatorOverloading, ComparisonAndAssignment)
{
    Transformer t1("Optimus Prime", 150, 80, 100);
    Transformer t2("Megatron", 200, 70, 120);
    Transformer t3("Bumblebee", 100, 90, 80);
    Transformer t4("Gigatron", 150, 80, 100);

    EXPECT_TRUE(t1 < t2);
    EXPECT_TRUE(t2 > t1);
    EXPECT_FALSE(t1 > t2);
    EXPECT_FALSE(t3 > t1);

    EXPECT_TRUE(t1 == t4);
    EXPECT_EQ(t1.getName(), "Optimus Prime");
    EXPECT_EQ(t1.getPower(), 150);
    EXPECT_EQ(t1.getSpeed(), 80);
    EXPECT_EQ(t1.getEquipment().getPower(), 100);
}

TEST(MiniconTests, DefaultConstructor)
{
    Minicon defaultMinicon;


    EXPECT_EQ(defaultMinicon.getName(), "Default Minicon");
    EXPECT_EQ(defaultMinicon.getPower(), 0u);
    EXPECT_EQ(defaultMinicon.getSpeed(), 0u);
    EXPECT_EQ(defaultMinicon.getEquipment().getPower(), 0);
    EXPECT_EQ(defaultMinicon.getMaster(), "Default Master");
    EXPECT_EQ(defaultMinicon.getExistanceObligation(), "Default Existence Obligation");
}

TEST(DecepticonTests, DefaultConstructor)
{
    Decepticon defaultDecepticon;


    EXPECT_EQ(defaultDecepticon.getName(), "Default Decepticon");
    EXPECT_EQ(defaultDecepticon.getPower(), 0u);
    EXPECT_EQ(defaultDecepticon.getSpeed(), 0u);
    EXPECT_EQ(defaultDecepticon.getEquipment().getPower(), 0);
    EXPECT_EQ(defaultDecepticon.getEnemy(), "Default Enemy");
    EXPECT_EQ(defaultDecepticon.getReasonForevilness(), "Default Reason for Evilness");
}