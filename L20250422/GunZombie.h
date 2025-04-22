#pragma once
#include "Zombie.h"
class AGunZombie : public AZombie
{
public:
	using AZombie::AZombie;
	void Attack() override;
};

