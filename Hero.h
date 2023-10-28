// Hero.h
#ifndef HERO_H
#define HERO_H

#include "Character.h"

class Hero : public Character {
public:
    int specialPowerCooldown;
    bool specialPowerActive;

    Hero(int life, int defense, int damage, const std::string& weapon, const std::string& name);

    void activatePower();
};

#endif
