#pragma once
#include <vector>
class AMilk;
class ASweetFish;
class AHerb;
class ABranch;
class AItem;

class AInventory
{
public:
	AInventory();
	virtual ~AInventory();

	std::vector<AItem*> GetAllItem()
	{
		return Items;
	}
	//AMilk* AMilks[10];
	//ASweetFish* ASweetFish[10];
	//AHerb* AHerb[10];
	//ABranch* ABranch[10];
protected:
	std::vector<AItem*> Items;
};

