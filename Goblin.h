// Goblin.h
#ifndef GOBLIN_H
#define GOBLIN_H

#include "Monster.h"

class Goblin : public Monster {
public:
    Goblin(int life, int defense,int damage, const std::string& name);
     Goblin(const std::string& name);

};

#endif
