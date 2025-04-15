#include "World.h"
#include <time.h>
#include "Monster.h"
#include <vector>

UWorld::UWorld()
{
	Initialize();
}

UWorld::~UWorld()
{
	Terminate();
}

void UWorld::Initialize()
{
	srand(time(NULL));
	//SpawnRandomMonster();
}

void UWorld::Terminate()
{
}

void UWorld::SpawnMonster(std::vector<AMonster*>* _MonsterVector, int _Amount)
{

}

//void UWorld::Terminate()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		delete Slimes[i];
//	}
//	Slimes.clear();
//	for (auto Goblin : Goblins)
//	{
//		delete Goblin;
//	}
//	Goblins.clear();
//}
