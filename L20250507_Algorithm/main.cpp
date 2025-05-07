#include <iostream>

int Square(int _Number, int _Index)
{
	int Result = 0;
	if (_Index == 0)
	{
		return _Number;
	}
	else
	{
		_Index--;
		return Square(_Number * 2, _Index);
	}
}

int main()
{
	int Count = 0;
	std::cin >> Count;
	int* Numbers = new int[Count];
	for (int i = 0; i < Count; i++)
	{
		int Number = 0;
		std::cin >> Number;
		int Index = 0;
		while(true)
		{
			int Result = Square(2, Index);
			if (Result >= Number)
			{
				Numbers[i] = Result;
				break;
			}
			else
			{
				Index++;
			}
		}
	}
	int XorResult = 0;
	for (int i = 0; i < Count - 1; i++)
	{
		if (i == 0)
		{
			XorResult = Numbers[i] ^ Numbers[i + 1];
		}
		else
		{
			XorResult = XorResult ^ Numbers[i + 1];
		}
	}
	std::cout << XorResult;
	delete Numbers;
	Numbers = nullptr;
	return 0;
}

