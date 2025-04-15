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
/// <summary>
/// The Function Money Increase
/// </summary>
/// <param name="_OriginMoney">Origin Money Before Add</param>
/// <param name="_Amount">Amount Of Money Will be Added</param>
/// <returns>Caculated Money</returns>
int IncreaseMoney(int _OriginMoney, int _Amount)
{
	int IncreasedMoney = _OriginMoney + _Amount;
	return IncreasedMoney;
}