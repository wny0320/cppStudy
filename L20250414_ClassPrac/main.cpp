#include <iostream>
#include "Weapon.h"
int main()
{
	AWeapon* FirstWeapon = new AWeapon();
	FirstWeapon->Level = 1;
	FirstWeapon->Price = 100;
	FirstWeapon->ReinForceChance = 0.9f;

	AWeapon* SecondWeapon = new AWeapon();
	SecondWeapon->Level = 2;
	SecondWeapon->Price = 500;
	SecondWeapon->ReinForceChance = 0.8f;

	AWeapon* NowWeapon = new AWeapon();
	FirstWeapon->NextWeapon = SecondWeapon;

	NowWeapon = FirstWeapon;

	if (NowWeapon->ReinForce(NowWeapon) == true)
	{
		NowWeapon = NowWeapon->NextWeapon;
	}
	else
	{
		NowWeapon->DeleteWeapon(NowWeapon);
	}

	FirstWeapon->WeaponImage.Terminate(FirstWeapon->WeaponImage._Pixel);
	SecondWeapon->WeaponImage.Terminate(SecondWeapon->WeaponImage._Pixel);

	delete FirstWeapon;
	FirstWeapon = nullptr;

	delete SecondWeapon;
	SecondWeapon = nullptr;
}