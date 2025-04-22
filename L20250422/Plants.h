#pragma once
#include <vector>
#include "Character.h"
#include "Bullet.h"

class APlants : protected ACharacter
{
public:
	APlants(float _Hp, float _Atk, float _CoolDown, float _Price, float _AtkRange, float _AtkCount, float _BulletSpeed);
	~APlants();
protected:
	std::vector<ABullet*> MyBulletVector;
	float Price;
	float AtkCount;
	float BulletSpeed;
	virtual void Attack() override;
};

