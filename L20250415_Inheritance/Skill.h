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
	void SetUseHpAmount(int _SetUseHpAmount)
	{
		UseHpAmount = _SetUseHpAmount;
	}
	void SetUseMpAmount(int _SetUseMpAmount)
	{
		UseMpAmount = _SetUseMpAmount;
	}
	void SetUseHpAmount(int _SetDamage)
	{
		Damage = _SetDamage;
	}
};

