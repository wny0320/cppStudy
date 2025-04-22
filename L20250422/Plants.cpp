#include <iostream>
#include "Plants.h"
#include "Bullet.h"

APlants::APlants(float _Hp, float _Atk, float _CoolDown, float _Price, float _AtkRange, float _AtkCount, float _BulletSpeed)
{
	Hp = _Hp;
	Atk = _Atk;
	CoolDown = _CoolDown;
	Price = _Price;
	AtkRange = _AtkRange;
	AtkCount = _AtkCount;
	BulletSpeed = _BulletSpeed;
}

APlants::~APlants()
{
	for (auto Data : MyBulletVector)
	{
		delete Data;
	}
	MyBulletVector.clear();
}

void APlants::Attack()
{
	ABullet* Bullet = new ABullet(this, Atk, BulletSpeed);
	MyBulletVector.push_back(Bullet);
	std::cout << "Plants Attack" << std::endl;
}

void APlants::Move()
{
	std::cout << "Plants Can't Move" << std::endl;
}
