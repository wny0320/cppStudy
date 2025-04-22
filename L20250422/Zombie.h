#pragma once
#include "Character.h"
class AZombie : protected ACharacter
{
public:
	AZombie(float _Hp, float _Atk, float _CoolDown, float _AtkRange, float _MoveSpeed, float _Defence);
protected:
	float MoveSpeed;
	float Defence;
	virtual void Move();
};

