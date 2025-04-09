#include <iostream>

using namespace std;

int main()
{
	int* DynamicArray = new int[10];
	for (int i = 0; i < 10; i++)
	{
		DynamicArray[i] = (i + 1) * 3;
	}
	int* NewDynamicArray = new int[20];
	for (int i = 0; i < 10; i++)
	{
		NewDynamicArray[i] = DynamicArray[i];
	}
	delete[] DynamicArray;

	for (int i = 10; i < 20; i++)
	{
		NewDynamicArray[i] = (i + 1) * 4;
	}
	for (int i = 0; i < 20; i++)
	{
		cout << NewDynamicArray[i] << endl;
	}
	delete[] NewDynamicArray;
	return 0;
}