#pragma once
class ACharacter
{
public:
	virtual void Attack();
	virtual void Damaged(float _Damage, ACharacter* _Attacker);
protected:
	float Hp;
	float Atk;
	float CoolDown;
	float AtkRange;
};

