#include <iostream>

using namespace std;

int main()
{
	float Number1 = 5678.0f;
	float Number2 = 3.0f;
	//+, -, *, /, %
	//이항 연산자
	float AddResult = Number1 + Number2;
	float SubResult = Number1 - Number2;
	float MulResult = Number1 * Number2;
	float DivResult = Number1 / Number2;
	// float RemainResult = Number1 % Number2;


	cout << AddResult << endl;
	cout << SubResult << endl;
	cout << MulResult << endl;
	cout << DivResult << endl;
	cout << "float don't have remain" << endl;

	return 0;
}