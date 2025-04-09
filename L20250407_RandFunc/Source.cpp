#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int Balls[52];
	// 시드 설정
	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		Balls[i] = i;
	}
	for (int i = 0; i < 52; i++)
	{
		int First = rand() % 52;
		int Second = rand() % 52;
		int Buffer;
		Buffer = Balls[First];
		Balls[First] = Balls[Second];
		Balls[Second] = Buffer;
	}
	for (int i = 0; i < 52; i++)
	{
		cout << Balls[i] << endl;
	}
	return 0;
}