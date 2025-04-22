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

	//모양 없는 Actor가 있을 수도 있는데 이런 경우 때문에 Component 기반 프로그래밍이 나옴
	char Shape;
};

