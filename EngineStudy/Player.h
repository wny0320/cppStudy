#pragma once
#include "Actor.h"
class APlayer : public AActor
{
public:
	APlayer();
	virtual	~APlayer();

	virtual void Tick() override;
	virtual bool CollisionCheck(FVector2D _Direction);
};

