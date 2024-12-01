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