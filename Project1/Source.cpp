#include <iostream>
#include <time.h>
#include <string>

using namespace std;

void LottoSet()
{

}

void BallShuffle(int _TargetLottoBalls[])
{
	//Set Random Seed By Time
	srand(time(NULL));
	//ShuffleBalls
	for (int Index = 0; Index < 45 * 100; Index++)
	{
		int FirstBall = rand() % 45;
		int SecondBall = rand() % 45;

		int Temp = _TargetLottoBalls[FirstBall];
		_TargetLottoBalls[FirstBall] = _TargetLottoBalls[SecondBall];
		_TargetLottoBalls[SecondBall] = Temp;
	}
}

void BallPickUp(int _TargetLottoBalls[])
{
	int WinNumbers[6];
	for (int Index = 0; Index < 6; Index++)
	{
		WinNumbers[Index] = _TargetLottoBalls[Index];
	}
	//Bubble Sort
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6 - i; j++)
		{
			//Prevent Index Out Of Range
			if (j < 5)
			{
				if (WinNumbers[j] > WinNumbers[j + 1])
				{
					int Temp = WinNumbers[j];
					WinNumbers[j] = WinNumbers[j + 1];
					WinNumbers[j + 1] = Temp;
				}
			}
		}
	}
	for (int Index = 0; Index < 6; Index++)
	{
		cout << to_string(WinNumbers[Index]) + " ";
	}
}

int main()
{
	int LottoBalls[45] = { 0, };
	//LottoBalls init
	for (int i = 0; i < 45; i++)
	{
		LottoBalls[i] = i + 1;
	}
	BallShuffle(LottoBalls);
	BallPickUp(LottoBalls);
}