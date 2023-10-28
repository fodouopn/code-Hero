// Hero.cpp
#include "Hero.h"

Hero::Hero(int life, int defense, int damage, const std::string& weapon, const std::string& name)
    : Character(life, defense, damage, weapon, name), specialPowerCooldown(0), specialPowerActive(false) {}

void Hero::activatePower() {
    if (specialPowerCooldown == 0) {
        specialPowerCooldown = 3;
        specialPowerActive = true;
    }
}
