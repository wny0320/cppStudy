#include <conio.h>
#include "Player.h"
#include "Input.h"
APlayer::APlayer()
{
	Shape = 'P';
	Location.X = 1;
	Location.Y = 1;
	Collision = true;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	if (UInput::KeyCode != 0)
	{
		FVector2D Direction;
		switch (UInput::KeyCode)
		{
		case 'w':
			Direction = FVector2D(0, -1);
			break;
		case 's':
			Direction = FVector2D(0, 1);
			break;
		case 'a':
			Direction = FVector2D(-1, 0);
			break;
		case 'd':
			Direction = FVector2D(1, 0);
			break;
		}
		if (CollisionCheck(Direction) == true)
		{
			AddActorWorldOffset(Direction);
		}
	}
}

bool APlayer::CollisionCheck(FVector2D _Direction)
{
	FVector2D PredictPos = Location + _Direction;
	AActor* FindedActor = MyWorld->GetPositionActor(PredictPos);
	if (FindedActor != nullptr)
	{
		if (FindedActor->Collision == true)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return false;
}
