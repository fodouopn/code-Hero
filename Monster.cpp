// Monster.cpp
#include "Monster.h"

Monster::Monster(int life, int defense,int damage, const std::string& weapon, const std::string& name)
       : Character(life, defense, damage, weapon, name) {}
