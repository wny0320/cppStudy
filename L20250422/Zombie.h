#pragma once
#include "Character.h"
class AZombie : public ACharacter
{
public:
	AZombie(float _Hp, float _Atk, float _CoolDown, float _AtkRange, float _MoveSpeed, float _Defence);
	virtual void Move();
protected:
	float MoveSpeed;
	float Defence;
};

