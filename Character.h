// Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
public:
    int life;
    int defense;
    int damage;
    std::string weapon;
    std::string name;

    Character(int life, int defense, int damage, const std::string& weapon, const std::string& name);

    void Attack(Character* target);
};

#endif
