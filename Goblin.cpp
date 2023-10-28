// Goblin.cpp
#include "Goblin.h"

Goblin::Goblin(int life, int defense, int damage,const std::string& name)
    : Monster(10,4,5, "Gourdin", name) {}

Goblin::Goblin(const std::string& name)
    : Monster(10,4,5, "Gourdin", name) {}
// Implémentez ici les méthodes spécifiques à la classe Goblin.
