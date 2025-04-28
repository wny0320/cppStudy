#include <fstream>
#include <iostream>

#include "World.h"
#include "Actor.h"

#include "Player.h"
#include "Wall.h"
#include "Monster.h"
#include "Goal.h"
#include "Land.h"

UWorld::UWorld()
{
	//SpawnActor(new APlayer());
	//SpawnActor(new AWall());

	//AWall* NewWall = new AWall();
	//NewWall->Location.X = 1;
	//NewWall->Location.Y = 0;
	//SpawnActor(NewWall);

	//NewWall = new AWall();
	//NewWall->Location.X = 2;
	//NewWall->Location.Y = 0;
	//SpawnActor(NewWall);
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	//system("cls");
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}

void UWorld::Load(std::string filename)
{
	//구현
	//map 파일 읽어서 만들기
	//text
	//한줄씩 읽어서 객체 생성하게 만듬
	//while(한줄읽기), ifstream,
	//{
	//	한칸 내용 확인
	//	액터 생성
	//}
	std::ifstream ReadFile;
	ReadFile.open(filename);
	if (ReadFile.is_open())
	{
		int x = 0;
		int y = 0;
		while (!ReadFile.eof())
		{
			char Lines[256];
			for (int i = 0; i < 256; i++)
			{
				Lines[i] = ' ';
			}
			ReadFile.getline(Lines, 256);
			for (int i = 0; i < 256; i++)
			{
				if (Lines[i] == '*')
				{
					AWall* Wall = new AWall();
					Wall->Shape = Lines[i];
					Wall->Location = FVector2D(x,y);
					SpawnActor(Wall);
				}
				else if (Lines[i] == 'P')
				{
					APlayer* Player = new APlayer();
					Player->Shape = Lines[i];
					Player->Location = FVector2D(x, y);
					SpawnActor(Player);
				}
				else if (Lines[i] == 'G')
				{
					AGoal* Goal = new AGoal();
					Goal->Shape = Lines[i];
					Goal->Location = FVector2D(x, y);
					SpawnActor(Goal);
				}
				else if (Lines[i] == 'M')
				{
					AMonster* Monster = new AMonster();
					Monster->Shape = Lines[i];
					Monster->Location = FVector2D(x, y);
					SpawnActor(Monster);
				}
				else if (Lines[i] == ' ')
				{
					ALand* Land = new ALand();
					Land->Shape = Lines[i];
					Land->Location = FVector2D(x, y);
					SpawnActor(Land);
				}
				else
				{
					//pass
				}
				std::cout << Lines[i];
				x++;
			}
			std::cout << std::endl;
			x = 0;
			y++;
		}
	}
	ReadFile.close();
}

void UWorld::SpawnActor(AActor* NewActor)
{
	NewActor->MyWorld = this;
	Actors.push_back(NewActor);
}

void UWorld::DestoryActor(AActor* DestroyedActor)
{
	Actors.erase(find(Actors.begin(), Actors.end(), DestroyedActor));
}

AActor* UWorld::GetPositionActor(FVector2D _TargetPosition)
{
	for (auto Actor : Actors)
	{
		if (Actor->Location == _TargetPosition)
		{
			return Actor;
		}
	}
	return nullptr;
}

std::vector<AActor*>& UWorld::GetAllActors()
{
	return Actors;
}

