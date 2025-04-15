#pragma once

#include<vector>
#include "Monster.h"

class APlayer;
class ASlime;
class AGoblin;
class ABoar;

class UWorld
{
public:
	UWorld();
	~UWorld();
	std::vector<APlayer*> Player;
	std::vector<ASlime*> Slime;
	std::vector<AGoblin*> Goblin;
	std::vector<ABoar*> Boar;

	void Initialize();
	void Terminate();
	void SpawnMonster(std::vector<AMonster*>* _MonsterVector, int _Amount = 0);
};

