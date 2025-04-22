#include "Zombie.h"


AZombie::AZombie(float _Hp, float _Atk, float _CoolDown, float _AtkRange, float _MoveSpeed, float _Defence)
{
	Hp = _Hp;
	Atk = _Atk;
	CoolDown = _CoolDown;
	AtkRange = _AtkRange;
	MoveSpeed = _MoveSpeed;
	Defence = _Defence;
}

void AZombie::Move()
{
	//Move by My Speed per delta seconds
}
