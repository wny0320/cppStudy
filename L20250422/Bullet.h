#pragma once
class ABullet
{
	float Damage;
	float Speed;
public:
	ABullet(float _Damage, float _Speed);
protected:
	void BulletMove();
};

