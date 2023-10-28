// Orc.cpp
#include "Orc.h"

Orc::Orc(int life, int defense,int damage, const std::string& name)
    : Monster(20,6,8,"Hache", name) {}

Orc::Orc(const std::string& name)
    : Monster(20,6,8, "Hache", name) {}
// Implémentez ici les méthodes spécifiques à la classe Orc.
