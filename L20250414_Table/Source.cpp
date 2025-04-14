#include <iostream>

enum State
{
	Patrol,
	Chase,
	Attack,
	Die
};

class Position
{
	float X;
	float Y;
};

class Monster
{
	int Hp;
	float AttackRange;
	bool IsEnemyFind;

	Position Position;

	State NowState;

	void TransitState();
};

class Player
{
	Position Position;
};
void Monster::TransitState()
{
	{
		switch (NowState)
		{
		case Patrol:
			if (IsEnemyFind == true)
			{
				NowState = Chase;
			}
			break;
		case Chase:
			if (IsEnemyFind == false)
			{
				NowState = Patrol;
			}
			else if(AttackRange)
			break;
		case Attack:
			break;
		case Die:
			break;
		default:
			break;
		}
	}
}
int main()
{

	return 0;
}
