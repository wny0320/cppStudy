#include <iostream>

using namespace std;

int main()
{
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 10 - j; i++)
		{
			cout << " ";
		}
		for (int i = (3 - j) - 1; i < 3 + j; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int j = 0; j < 5; j++)
	{
		for (int i = 21; i > 21 - j; i--)
		{
			cout << " ";
		}
		for (int i = 0; i < 21 - j * 2; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 3-j; i++)
		{
			cout << " ";
		}
		for (int i = 0; i < 10 - (3 + (j * 2)); i++)
		{
			cout << "*";
		}
		for (int i = 0; i < (1 + (j * 6)); i++)
		{
			cout << " ";
		}
		for (int i = 0; i < 10 - (3 + (j * 2)); i++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}