#include "Actor.h"

AActor::AActor()
{
}

AActor::~AActor()
{
}

void AActor::AddActorWorldOffset(FVector2D offset)
{
	//���Ŀ� ������ �����ε� �� ����
	Location.X += offset.X;
	Location.Y += offset.Y;
}

void AActor::Tick()
{
}

void AActor::Render()
{
}
