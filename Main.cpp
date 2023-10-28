#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Character.h"
#include "Hero.h"
#include "Monster.h"
#include "Ninja.h"
#include "Knight.h"
#include "Cleric.h"
#include "Orc.h"
#include "Goblin.h"

int main() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(nullptr));

    // Création d'une équipe de 4 héros
    std::vector<Hero> heroes;
    for (int i = 0; i < 4; i++) {
        std::string name;
        std::cout << "Entrez le nom du Hero " << i + 1 << " : ";
        std::cin >> name;

        int heroType = rand() % 3;
        if (heroType == 0) {
            heroes.push_back(Ninja(name));
        } else if (heroType == 1) {
            heroes.push_back(Knight(name));
        } else {
            heroes.push_back(Cleric(name));
        }
    }

    // Création d'une équipe de 6 monstres 
    std::vector<Monster> monsters;
    int orcCount = 0;
    int goblinCount = 0;

    for (int i = 0; i < 6; i++) {
        int monsterType = rand() % 2;
        if (monsterType == 0) {
            monsters.push_back(Orc("Orc " + std::to_string(++orcCount)));
        } else {
            monsters.push_back(Goblin("Goblin " + std::to_string(++goblinCount)));
        }
    }

    // Boucle de jeu
    int turn = 1;
    while (!heroes.empty() && !monsters.empty()) {
        std::cout << "****************************************";
        std::cout << "Tour " << turn << std::endl;

        // Tour des héros
        for (Hero& hero : heroes) {
            if (hero.life > 0) {
                std::cout << "C'est au tour de " << hero.name << "." << std::endl;
                hero.specialPowerCooldown = std::max(0, hero.specialPowerCooldown - 1);

                if (hero.specialPowerActive) {
                    std::cout << hero.name << " active son pouvoir special !" << std::endl;
                    hero.activatePower();
                    hero.specialPowerActive = false;
                }

                // Affichage des options et permettre au joueur de choisir une action
                int choice;
                std::cout << "Choisissez une action :\n1. Attaquer\n2. Defendre\n3. Utiliser le pouvoir special\n";
                std::cin >> choice;

                if (choice == 1) {
                    if (!monsters.empty()) {
                        hero.Attack(&monsters[0]);
                        std::cout << hero.name << " attaque " << monsters[0].name << " pour " << hero.damage << " degats." << std::endl;
                        if (monsters[0].life <= 0) {
                            monsters.erase(monsters.begin());
                        }
                    }
                } else if (choice == 2) {
                    hero.defense += hero.defense * 0.75;
                    std::cout << hero.name << " se defend pour ce tour." << std::endl;
                } else if (choice == 3) {
                    hero.activatePower();
                    std::cout << hero.name << " se prepare a utiliser son pouvoir special au tour suivant." << std::endl;
                }
            }
        }

        // Tour des monstres
        for (Monster& monster : monsters) {
            if (monster.life > 0) {
                if (!heroes.empty()) {
                    Hero& targetHero = heroes[rand() % heroes.size()];
                    monster.Attack(&targetHero);
                    std::cout << monster.name << " attaque " << targetHero.name << " pour " << monster.damage << " degats." << std::endl;
                    if (targetHero.life <= 0) {
                        heroes.erase(std::remove_if(heroes.begin(), heroes.end(),
                            [](const Hero& h) { return h.life <= 0; }), heroes.end());
                    }
                }
            }
        }

        // Afficher l'état actuel de la bataille
        std::cout << "Heros :\n";
        for (const Hero& hero : heroes) {
            std::cout << hero.name << " - Health : " << hero.life << ", Defense : " << hero.defense << std::endl;
        }

        std::cout << "Monstres :\n";
        for (const Monster& monster : monsters) {
            std::cout << monster.name << " - Health : " << monster.life << ", Defense : " << monster.defense << std::endl;
        }

        // Attendre que l'utilisateur appuie sur une touche pour continuer le jeu
        std::cout << "Appuyez sur Entree pour continuer...";
        std::cin.ignore();
        std::cin.get();

        turn++;
    }

    // Fin du jeu
    if (heroes.empty()) {
        std::cout << "Les monstres gagnent !" << std::endl;
    } else {
        std::cout << "Les heros gagnent !" << std::endl;
    }

    return 0;
}
