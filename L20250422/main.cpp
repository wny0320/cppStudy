#include <iostream>
#include <vector>
#include "Character.h"
#include "Plants.h"
#include "Zombie.h"
#include "GunZombie.h"
#include "CommonZombie.h"

int main()
{
	std::vector<AZombie*> ZombieVector;
	std::vector<APlants*> PlantsVector;
	APlants* Plant1 = new APlants(100, 20, 1, 5, 50, 1, 10);
	ACommonZombie* Zombie1 = new ACommonZombie(100, 10, 1, 1, 10, 0);
	AGunZombie* Zombie2 = new AGunZombie(200, 20, 3, 1, 30, 0);

	//Plant and Zombie Fight
	for (auto Plant : PlantsVector)
	{
		Plant->Attack();
	}
	for (auto Zombie : ZombieVector)
	{
		Zombie->Move();
		Zombie->Attack();
	}
	//delete
	for (auto Plant : PlantsVector)
	{
		delete Plant;
	}
	for (auto Zombie : ZombieVector)
	{
		delete Zombie;
	}
	PlantsVector.clear();
	ZombieVector.clear();
}