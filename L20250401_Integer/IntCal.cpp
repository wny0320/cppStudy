#include <iostream>

using namespace std;

int main()
{
	int Number1 = 5678;
	int Number2 = 1234;
	//+, -, *, /, %
	//이항 연산자
	int AddResult = Number1 + Number2;
	int SubResult = Number1 - Number2;
	int MulResult = Number1 * Number2;
	int DivResult = Number1 / Number2;
	int RemainResult = Number1 % Number2;


	cout << AddResult << endl;
	cout << SubResult << endl;
	cout << MulResult << endl;
	cout << DivResult << endl;
	cout << RemainResult << endl;

	return 0;
}