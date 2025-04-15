#pragma once

#include "Image.h"

class ACharacter
{
protected:
	int Hp;
	int Mp;
	int Damage;
	UImage CharacterImage;
	void Move()
	{

	}
	void Attack(ACharacter* _TargetCharacter, int _Damage)
	{
		_TargetCharacter->GetDamage(_Damage);
	}
	void GetDamage(int _Amount)
	{
		Hp -= _Amount;
	}
};

