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

	AWeapon* ThirdWeapon = new AWeapon();
	ThirdWeapon->Level = 3;
	ThirdWeapon->Price = 1000;
	ThirdWeapon->ReinForceChance = 0.7f;

	AWeapon* ForthWeapon = new AWeapon();
	ForthWeapon->Level = 4;
	ForthWeapon->Price = 3000;
	ForthWeapon->ReinForceChance = 0.6f;

	AWeapon* NowWeapon = new AWeapon();
	FirstWeapon->NextWeapon = SecondWeapon;
	SecondWeapon->NextWeapon = ThirdWeapon;
	ThirdWeapon->NextWeapon = ForthWeapon;


	NowWeapon = FirstWeapon;

	while (true)
	{
		if (NowWeapon->ReinForce(NowWeapon) == true)
		{
			std::cout << "강화성공" << std::endl;
			NowWeapon = NowWeapon->NextWeapon;
		}
		else
		{
			std::cout << "강화실패" << std::endl;
			NowWeapon->DeleteWeapon(NowWeapon);
			break;
		}
	}
	FirstWeapon->WeaponImage.Terminate(FirstWeapon->WeaponImage._Pixel);
	SecondWeapon->WeaponImage.Terminate(SecondWeapon->WeaponImage._Pixel);

	delete FirstWeapon;
	FirstWeapon = nullptr;

	delete SecondWeapon;
	SecondWeapon = nullptr;
}