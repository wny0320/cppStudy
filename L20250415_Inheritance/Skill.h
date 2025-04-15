#pragma once
class USkill
{
protected:
	float UseHpAmount;
	float UseMpAmount;
	float Damage;
public:
	float GetUseHpAmount()
	{
		return UseHpAmount;
	}
	float GetUseMpAmount()
	{
		return UseMpAmount;
	}
	float GetDamage()
	{
		return Damage;
	}
	void SetUseHpAmount(float _SetUseHpAmount)
	{
		UseHpAmount = _SetUseHpAmount;
	}
	void SetUseMpAmount(float _SetUseMpAmount)
	{
		UseMpAmount = _SetUseMpAmount;
	}
	void SetDamage(float _SetDamage)
	{
		Damage = _SetDamage;
	}
};

