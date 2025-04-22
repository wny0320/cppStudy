#include "Actor.h"

AActor::AActor()
{
}

AActor::~AActor()
{
}

void AActor::AddActorWorldOffset(FVector2D offset)
{
	//차후에 연산자 오버로딩 할 것임
	Location.X += offset.X;
	Location.Y += offset.Y;
}

void AActor::Tick()
{
}

void AActor::Render()
{
}
