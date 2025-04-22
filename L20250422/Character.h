#pragma once
class ACharacter
{
protected:
	float Hp;
	float Atk;
	float CoolDown;
	float AtkRange;
	virtual void Attack();
	virtual void Damaged(float _Damage, ACharacter* _Attacker);
};

