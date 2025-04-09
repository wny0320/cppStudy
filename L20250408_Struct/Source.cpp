#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;


void GotoXY(int X, int Y)
{
    COORD Cur;
    Cur.X = X;
    Cur.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

struct PlayerInfo
{
    int X;
    int Y;
    string Shape;
};

struct Map
{
    int MapMaxSizeX;
    int MapMaxSizeY;
    string WallShape;
    string FloorShape;
};

void PlayerClipping(PlayerInfo* _PlayerData, Map* _NewMap)
{
    if (_PlayerData->X < 1)
    {
        _PlayerData->X = 1;
    }
    if (_PlayerData->X > _NewMap->MapMaxSizeX - 2)
    {
        _PlayerData->X = _NewMap->MapMaxSizeX - 2;
    }
    if (_PlayerData->Y < 1)
    {
        _PlayerData->Y = 1;
    }
    if (_PlayerData->Y > _NewMap->MapMaxSizeY - 2)
    {
        _PlayerData->Y = _NewMap->MapMaxSizeY - 2;
    }
}

void MovePlayer(PlayerInfo* _PlayerData, Map* _NewMap)
{
    switch (_getch())
    {
        case 80:
            _PlayerData->Y += 1;
            // code for arrow down
            break;
        case 72:
            _PlayerData->Y -= 1;
            // code for arrow up
            break;
        case 77:
            _PlayerData->X += 1;
            // code for arrow right
            break;
        case 75:
            _PlayerData->X -= 1;
            // code for arrow left
            break;
    }
    PlayerClipping(_PlayerData, _NewMap);
}

void PrintGame(PlayerInfo* _PlayerData, Map* _NewMap)
{
    //연속적으로 그릴려면 오래 걸려서 더블 버퍼링으로 그림
    //UE5에선 RenderTarget에 씀
    if (!_kbhit())
    {
        system("cls");
        for (int Y = 0; Y < _NewMap->MapMaxSizeY; Y++)
        {
            for (int X = 0; X < _NewMap->MapMaxSizeX; X++)
            {
                if (X == _PlayerData->X && Y == _PlayerData->Y)
                {
                    GotoXY(_PlayerData->X, _PlayerData->Y);

                    cout << _PlayerData->Shape << endl;
                }
                else if (X == 0 || Y == 0 || X == _NewMap->MapMaxSizeX-1 || Y == _NewMap->MapMaxSizeY - 1)
                {
                    GotoXY(X,Y);
                    cout << _NewMap->WallShape << endl;
                }
                else
                {
                    GotoXY(X, Y);
                    cout << _NewMap->FloorShape << endl;
                }
            }
        }
    }
}

int main()
{
    //Instantiate Player
    PlayerInfo* PlayerData;
    PlayerData = new PlayerInfo;

    //Init Player
    PlayerData->X = 5;
    PlayerData->Y = 5;
    PlayerData->Shape = "P ";

    //Instantiate Player
    Map* NewMap;
    NewMap = new Map;

    //Init Map
    NewMap->MapMaxSizeX = 20;
    NewMap->MapMaxSizeY = 10;
    NewMap->WallShape = "@";
    NewMap->FloorShape = " ";


    PrintGame(PlayerData, NewMap);
    while (true)
    {
        MovePlayer(PlayerData, NewMap);
        PrintGame(PlayerData, NewMap);
    }

    delete PlayerData;
    delete NewMap;
    PlayerData = nullptr;
    NewMap = nullptr;

}