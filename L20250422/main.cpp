#include <iostream>
#include <vector>
#include "Character.h"
#include "Plants.h"
#include "Zombie.h"
#include "GunZombie.h"
#include "CommonZombie.h"

int main()
{
	std::vector<ACharacter*> CharacterVector;
	APlants* Plant1 = new APlants(100, 20, 1, 5, 50, 1, 10);
	ACommonZombie* Zombie1 = new ACommonZombie(100, 10, 1, 1, 10, 0);
	AGunZombie* Zombie2 = new AGunZombie(200, 20, 3, 1, 30, 0);
	CharacterVector.push_back(Plant1);
	CharacterVector.push_back(Zombie1);
	CharacterVector.push_back(Zombie2);

	//Plant and Zombie Fight
	for (auto Character : CharacterVector)
	{
		Character->Attack();
	}
	//delete
	for (auto Character : CharacterVector)
	{
		delete Character;
	}
	CharacterVector.clear();
}