// Character.cpp
#include "Character.h"

Character::Character(int life, int defense, int damage, const std::string& weapon, const std::string& name)
    : life(life), defense(defense), damage(damage), weapon(weapon), name(name) {}

void Character::Attack(Character* target) {
    int damageDealt = damage - target->defense;
    if (damageDealt > 0) {
        target->life -= damageDealt;
    }
}
