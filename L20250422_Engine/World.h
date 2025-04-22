#pragma once
#include <vector>
class AActor;
class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void Tick();
	void Render();

protected:
	std::vector<AActor*> Actors;
};

