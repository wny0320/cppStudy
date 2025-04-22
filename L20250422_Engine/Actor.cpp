#include <iostream>
#include "Windows.h"

#include "Actor.h"
AActor::AActor()
{
	Shape = ' ';
}

AActor::~AActor()
{
}

void AActor::AddActorWorldOffset(const FVector2D& offset)
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
	COORD Position = {(SHORT) Location.X, (SHORT) Location.Y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);

	std::cout << Shape;
}
