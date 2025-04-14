//#include <iostream>
//#include <conio.h>
//#include <Windows.h>
//#include <time.h>
//
//using namespace std;
//
//#define UP 72
//#define DOWN 80
//#define LEFT 75
//#define RIGHT 77
//
//#define MaxMapX 10
//#define MaxMapY 20
//struct PlayerData
//{
//	int X = 1;
//	int Y = 1;
//};
//
//void SetCursor(int _X = 0, int _Y = 0)
//{
//	HANDLE handle;
//	COORD coordinates;
//	handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	coordinates.X = _X;
//	coordinates.Y = _Y;
//	SetConsoleCursorPosition(handle, coordinates);
//}
//
//void Clipping(int _MaxMapY, int _MaxMapX, PlayerData& _PlayerData)
//{
//	if (_PlayerData.X < 1)
//	{
//		_PlayerData.X = 1;
//	}
//	else if (_PlayerData.X > _MaxMapX - 2)
//	{
//		_PlayerData.X = _MaxMapX - 2;
//	}
//	if (_PlayerData.Y < 1)
//	{
//		_PlayerData.Y = 1;
//	}
//	else if (_PlayerData.Y > _MaxMapY - 2)
//	{
//		_PlayerData.Y = _MaxMapY - 2;
//	}
//}
//void Init(int _Map[MaxMapY][MaxMapX])
//{
//	for (int i = 0; i < MaxMapY; i++)
//	{
//		for (int j = 0; j < MaxMapX; j++)
//		{
//			if (i == 0 || i == 19 || j == 0 || j == 9)
//			{
//				_Map[i][j] = 1;
//			}
//			else if (rand() % 10 == 0)
//			{
//				_Map[i][j] = 1;
//			}
//			else
//			{
//				_Map[i][j] = 0;
//			}
//		}
//	}
//}
//
//char Input(char& _InputKey)
//{
//	char InputKey = _getch();
//	return InputKey;
//}
//
//void Tick(char& _InputKey, int _Map[MaxMapY][MaxMapX], PlayerData& _PlayerData)
//{
//	switch (_InputKey)
//	{
//	case UP:
//		if (_Map[_PlayerData.Y - 1][_PlayerData.X] == 1)
//		{
//			break;
//		}
//		_PlayerData.Y -= 1;
//		break;
//	case DOWN:
//		if (_Map[_PlayerData.Y + 1][_PlayerData.X] == 1)
//		{
//			break;
//		}
//		_PlayerData.Y += 1;
//		break;
//	case RIGHT:
//		if (_Map[_PlayerData.Y][_PlayerData.X + 1] == 1)
//		{
//			break;
//		}
//		_PlayerData.X += 1;
//		break;
//	case LEFT:
//		if (_Map[_PlayerData.Y][_PlayerData.X - 1] == 1)
//		{
//			break;
//		}
//		_PlayerData.X -= 1;
//		break;
//	default:
//		break;
//	}
//	Clipping(MaxMapY, MaxMapX, _PlayerData);
//}
//
//void Render(int _Map[MaxMapY][MaxMapX], PlayerData _PlayerData, char _MapDraw[MaxMapY][MaxMapX])
//{
//	system("cls");
//	for (int i = 0; i < MaxMapY; i++)
//	{
//		for (int j = 0; j < MaxMapX; j++)
//		{
//			if (_Map[i][j] == 1)
//			{
//				_MapDraw[i][j] = '*';
//			}
//			else if (_PlayerData.Y == i && _PlayerData.X == j)
//			{
//				_MapDraw[i][j] = 'P';
//			}
//			else
//			{
//				_MapDraw[i][j] = ' ';
//			}
//		}
//	}
//
//	for (int i = 0; i < MaxMapY; i++)
//	{
//		for (int j = 0; j < MaxMapX; j++)
//		{
//			cout << _MapDraw[i][j];
//		}
//		cout << endl;
//	}
//}
//int main()
//{
//	int Map[MaxMapY][MaxMapX];
//	char MapDraw[MaxMapY][MaxMapX];
//	srand(time(NULL));
//	Init(Map);
//	bool IsRunning = true;
//	PlayerData MyPlayerData;
//	while (IsRunning)
//	{
//		char InputKey;
//		InputKey = Input(InputKey);
//		Tick(InputKey, Map, MyPlayerData);
//		Render(Map, MyPlayerData, MapDraw);
//	}
//}
// °­»ç´Ô ÄÚµå
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

struct CharacterInfo
{
	int X;
	int Y;
	char Shape;
};


int MapHeight = 10;
int KeyCode = 0;
CharacterInfo* Player = nullptr;
CharacterInfo* Monster = nullptr;

string* Map;
bool IsRunning = true;



void Initialize();
void Input();
void Tick();
void Render();
void GotoXY(int x, int y);
void Terminate();
bool Predict(int PredictX, int PredictY);





int main()
{
	Initialize();

	while (IsRunning)  //frame, game loop
	{
		Input();
		Tick();
		Render();
	}

	Terminate();

	return 0;
}

void Initialize()
{
	//Load
	Map = new string[MapHeight];
	//FILE
	Map[0] = "**************";
	Map[1] = "*        *****";
	Map[2] = "*        *** *";
	Map[3] = "*        **  *";
	Map[4] = "****     **  *";
	Map[5] = "*        *  **";
	Map[6] = "*          ***";
	Map[7] = "*   *    *****";
	Map[8] = "*   *    *****";
	Map[9] = "**************";

	Player = new CharacterInfo();
	Player->X = 1;
	Player->Y = 1;
	Player->Shape = 'P';

	Monster = new CharacterInfo();
	Monster->X = 8;
	Monster->Y = 8;
	Monster->Shape = 'M';

	srand((unsigned int)(time(nullptr)));

}

void Input()
{
	KeyCode = _getch();
}

void Tick()
{
	//Player
	if (KeyCode == 'w' && Predict(Player->X, Player->Y - 1))
	{
		Player->Y--;
	}
	if (KeyCode == 's' && Predict(Player->X, Player->Y + 1))
	{
		Player->Y++;
	}
	if (KeyCode == 'a' && Predict(Player->X - 1, Player->Y))
	{
		Player->X--;
	}
	if (KeyCode == 'd' && Predict(Player->X + 1, Player->Y))
	{
		Player->X++;
	}

	if (KeyCode == 'q')
	{
		IsRunning = false;
	}

	int Direction = rand() % 4;
	if (Direction == 0)
	{
		if (Predict(Monster->X, Monster->Y - 1))
		{
			Monster->Y--;
		}
	}
	if (Direction == 1)
	{
		if (Predict(Monster->X, Monster->Y + 1))
		{
			Monster->Y++;
		}
	}
	if (Direction == 2)
	{
		if (Predict(Monster->X - 1, Monster->Y))
		{
			Monster->X--;
		}
	}
	if (Direction == 3)
	{
		if (Predict(Monster->X + 1, Monster->Y))
		{
			Monster->X++;
		}
	}
}

void Render()
{
	//system("cls");
	for (int Y = 0; Y < MapHeight; ++Y)
	{
		for (int X = 0; X < Map[Y].length(); ++X)
		{
			GotoXY(X, Y);
			cout << Map[Y][X];
		}
	}



	//Actor, Pawn
	GotoXY(Player->X, Player->Y);
	cout << Player->Shape;

	GotoXY(Monster->X, Monster->Y);
	cout << Monster->Shape;
}

void GotoXY(int X, int Y)
{
	COORD Pos;
	Pos.X = X;
	Pos.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Terminate()
{
	delete Player;
	Player = nullptr;

	delete Monster;
	Monster = nullptr;

	delete[] Map;
	Map = nullptr;
}

bool Predict(int PredictX, int PredictY)
{
	if (Map[PredictY][PredictX] == ' ')
	{
		return true;
	}

	return false;
}
