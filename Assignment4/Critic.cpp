/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#include "Critic.h"

Critic::Critic(const std::string& name, int sarcasm_level)
    : name(name), sarcasm_level(sarcasm_level) {}

std::string Critic::critique() const {
    return name + ": Nice try, really.";
}
