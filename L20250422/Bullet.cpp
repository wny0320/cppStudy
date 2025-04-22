#include "Bullet.h"
ABullet::ABullet(ACharacter* _Owner, float _Damage, float _Speed)
{
	Owner = _Owner;
	Damage = _Damage;
	Speed = _Speed;
}

void ABullet::BulletMove()
{
	//Move by My Speed per delta seconds
}
