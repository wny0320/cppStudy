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
	//차후에 연산자 오버로딩 할 것임
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
