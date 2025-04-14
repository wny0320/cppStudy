#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define MaxMapX 10
#define MaxMapY 20
struct PlayerData
{
	int X = 1;
	int Y = 1;
};

void SetCursor(int _X = 0, int _Y = 0)
{
	HANDLE handle;
	COORD coordinates;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = _X;
	coordinates.Y = _Y;
	SetConsoleCursorPosition(handle, coordinates);
}

void Clipping(int _MaxMapY, int _MaxMapX, PlayerData &_PlayerData)
{
	if (_PlayerData.X < 1)
	{
		_PlayerData.X = 1;
	}
	else if (_PlayerData.X > _MaxMapX - 2)
	{
		_PlayerData.X = _MaxMapX - 2;
	}
	if (_PlayerData.Y < 1)
	{
		_PlayerData.Y = 1;
	}
	else if (_PlayerData.Y > _MaxMapY - 2)
	{
		_PlayerData.Y = _MaxMapY - 2;
	}
}

int main()
{
	int Map[MaxMapY][MaxMapX];
	for (int i = 0; i < MaxMapY; i++)
	{
		for (int j = 0; j < MaxMapX; j++)
		{
			if (i == 0 || i == 19 || j == 0 || j == 9)
			{
				Map[i][j] = 1;
			}
			else
			{
				Map[i][j] = 0;
			}
		}
	}

	bool IsRunning = true;
	PlayerData MyPlayerData;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Map[i][j] == 1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	SetCursor(MyPlayerData.X, MyPlayerData.Y);
	cout << "P";
	while (IsRunning)
	{
		if (_kbhit())
		{
			char InputKey = _getch();
			switch (InputKey)
			{
			case UP:
				MyPlayerData.Y -= 1;
				break;
			case DOWN:
				MyPlayerData.Y += 1;
				break;
			case RIGHT:
				MyPlayerData.X += 1;
				break;
			case LEFT:
				MyPlayerData.X -= 1;
				break;
			default:
				break;
			}
			Clipping(MaxMapY, MaxMapX, MyPlayerData);
			system("cls");
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (Map[i][j] == 1)
					{
						cout << "*";
					}
					else
					{
						cout << " ";
					}
				}
				cout << endl;
			}
			SetCursor(MyPlayerData.X, MyPlayerData.Y);
			cout << "P";
		}

	}
}