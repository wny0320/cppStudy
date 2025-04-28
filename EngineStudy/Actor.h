#pragma once
#include "Vector2D.h"
#include "World.h"
class AActor
{
public:
	AActor();
	virtual ~AActor();

	void AddActorWorldOffset(FVector2D offset);
	FVector2D Location;

	virtual void Tick();
	virtual void Render();

	char Shape;
	UWorld* MyWorld;
	bool Collision;
};

//Actor has a Fvector2D
