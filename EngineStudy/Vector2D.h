#pragma once
struct FVector2D
{
	//FVector2D();
	FVector2D(int InX = 0 , int InY = 0);
	virtual ~FVector2D();

	FVector2D operator+(const FVector2D& RHS)
	{
		return FVector2D(X + RHS.X, Y + RHS.Y);
		/*X += RHS.X;
		Y += RHS.Y;*/
	}
	bool operator==(const FVector2D& RHS)
	{
		if (X == RHS.X && Y == RHS.Y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int X;
	int Y;
};

