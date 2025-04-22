#pragma once
#include "Zombie.h"
class ACommonZombie : public AZombie
{
public:
	using AZombie::AZombie;
	void Attack() override;
};

