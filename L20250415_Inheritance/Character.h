#pragma once

#include "Image.h"

class ACharacter
{
protected:
	float Hp;
	float Mp;
	float Damage;
	UImage CharacterImage;
	void Move()
	{

	}
	void Attack(ACharacter* _TargetCharacter, float _Damage)
	{
		_TargetCharacter->GetDamage(_Damage);
	}
	void GetDamage(float _Amount)
	{
		Hp -= _Amount;
	}
};

