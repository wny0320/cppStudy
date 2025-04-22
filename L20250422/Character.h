#pragma once
class ACharacter
{
protected:
	float Hp;
	virtual void Attack();
	virtual void Damaged(float _Damage, ACharacter* _Attacker);
};

