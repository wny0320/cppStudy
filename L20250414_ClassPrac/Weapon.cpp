#include "Weapon.h"
#include <iostream>
#include <time.h>
bool AWeapon::ReinForce(AWeapon* _TargetWeapon)
{
	srand(time(NULL));
	float Chance = _TargetWeapon->ReinForceChance;
	if (rand() % 100 < Chance * 100)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AWeapon::DeleteWeapon(AWeapon* _TargetWeapon)
{
	delete _TargetWeapon;
	_TargetWeapon = nullptr;
}
