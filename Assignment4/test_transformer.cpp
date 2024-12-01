/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#include <gtest/gtest.h>
#include "Transformer.h"
#include "Weapon.h"
#include "Scope.h"
#include "Critic.h"
#include "Decepticon.h"
#include <sstream>
#include "Autobot.h"
#include "Minicon.h"


//<< operator
TEST(TransformerTest, WeaponTest) {
  Weapon item("gun", 14);

  std::ostringstream oss;
  oss << item;
  EXPECT_EQ(oss.str(), "power: 14 type: gun");
}
TEST(TransformerTest, DecepticonTest){
  Decepticon item("Name", 12, "blue", 1, "gun", 38, 3, "unluck", "no", "plain", "f52");
  std::ostringstream oss;
  oss<<item;
  EXPECT_EQ(oss.str(), "Name");
}

TEST(TransformerTest, AutobotTest){
  Autobot item("Optimus", 14, "red", 12, "gigacannon", 12, "God", 12);
  std::ostringstream oss;
  oss<<item;
  EXPECT_EQ(oss.str(), "Optimus");
}

TEST(TransformerTest, MiniconTest){
  Minicon item("Minicon", 14, "red", 12, "gigacannon", 12);
  std::ostringstream oss;
  oss<<item;
  EXPECT_EQ(oss.str(), "Minicon");
}

TEST(TransformerTest, operators) {
  Minicon minicon("Minicon", 14, "blue", 42, "tyres", 32);
  Autobot optimus("Optimus", 52, "red", 12, "gigacannon", 12, "God", 12);

  EXPECT_LT(minicon.getEnergyLevel(), optimus.getEnergyLevel());
  EXPECT_GT(optimus.getEnergyLevel(), minicon.getEnergyLevel());
  EXPECT_NE(minicon.getEnergyLevel(), optimus.getEnergyLevel());
  EXPECT_EQ(optimus.getEnergyLevel(), optimus.getEnergyLevel());
  EXPECT_GE(optimus.getEnergyLevel(), minicon.getEnergyLevel());
  EXPECT_LE(minicon.getEnergyLevel(), optimus.getEnergyLevel());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}