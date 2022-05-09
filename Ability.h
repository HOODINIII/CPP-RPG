#pragma once
#include <string>
enum class Targetability {SELF, ALLY, ENEMY };
struct Ability
{	
	Ability(std::string name, int cost, int cooldown, Targetability targ, int HPA) :
	Name(name), Cost(cost), Cooldown(cooldown), target(targ), HP_Ability(HPA) {}
	std::string Name = "noname";
	int Cost = 0; // either uses mana or energy
	int Cooldown = 2; // number of rounds before used again
	Targetability target = Targetability::ENEMY;
	int HP_Ability = 10;
	
}; 

	
