#pragma once
#include "Image.h"

class AWeapon
{
public:
	int Level;
	int Price;
	Image WeaponImage;
	float ReinForceChance;
	AWeapon* NextWeapon;

	bool ReinForce(AWeapon* _TargetWeapon);
	void DeleteWeapon(AWeapon* _TargetWeapon);
};

