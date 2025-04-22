#pragma once
#include "Vector2D.h"
class AActor
{
public:
	AActor();
	virtual ~AActor();

	//이동해주는 함수
	void AddActorWorldOffset(const FVector2D& offset);
	//형태를 알아야하므로 전방선언이 안됨
	FVector2D Location;

	virtual void Tick();
	virtual void Render();
};

