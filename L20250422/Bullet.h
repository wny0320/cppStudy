#pragma once
#include "Character.h"
class ABullet
{
	ACharacter* Owner;
	float Damage;
	float Speed;
public:
	ABullet(ACharacter* _Owner ,float _Damage, float _Speed);
protected:
	void BulletMove();
};

