#pragma once
#include "Character.h"
#include "Skill.h"
class APlayer : public ACharacter
{
protected:
	int Gold;
	USkill MySkill[2];
public:
	void IncreaseGold(int _Amount)
	{
		Gold += _Amount;
	}
	void DecreaseGold(int _Amount)
	{
		Gold -= _Amount;
	}
	void UseSkill(USkill* _TargetSkill)
	{
		Hp -= _TargetSkill->GetUseHpAmount();
		Mp -= _TargetSkill->GetUseHpAmount();
	}
};

