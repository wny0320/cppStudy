#pragma once
#include "Character.h"
class AZombie : protected ACharacter
{
protected:
	float MoveSpeed;
	float Defence;
	virtual void Move();
};

