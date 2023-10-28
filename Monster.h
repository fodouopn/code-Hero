// Monster.h
#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"

class Monster : public Character {
public:
    Monster(int life, int defense,int damage, const std::string& weapon, const std::string& name);
};

#endif
