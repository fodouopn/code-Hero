// Orc.h
#ifndef ORC_H
#define ORC_H

#include "Monster.h"

class Orc : public Monster {
public:
    Orc(int life, int defense,int damage, const std::string& name);
    Orc(const std::string& name);
};

#endif
 