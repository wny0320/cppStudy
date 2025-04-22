#include <iostream>
#include <vector>
#include "Character.h"
#include "Plants.h"
#include "Zombie.h"

int main()
{
	APlants* Plant = new APlants(100, 20, 1, 5, 50, 1, 10);
	AZombie* Zombie = new AZombie(100, 10, 1, 1, 10, 0);

	//Plant and Zombie Fight

	delete Plant;
	Plant = nullptr;
	delete Zombie;
	Zombie = nullptr;
}