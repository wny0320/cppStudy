#include <iostream>
#include "Player.h"
#include "World.h"
#include "Goal.h"
#include "Floor.h"
#include "Wall.h"
#include "Monster.h"


int main()
{
	APlayer* Player = new APlayer();

	delete Player;
	Player = nullptr;

	return 0;
}