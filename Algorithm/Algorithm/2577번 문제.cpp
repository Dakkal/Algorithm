#include <iostream>
#include <string>
using namespace std;

int main()
{
	int iA;
	int iB;
	int iC;
	int iMulti;
	string strMulti;
	int iArray[10] = { 0, };

	cin >> iA;
	cin >> iB;
	cin >> iC;

	iMulti = (iA * iB * iC);

	strMulti = to_string(iMulti);

	for (int i = 0; i < strMulti.length(); ++i)
	{
		iArray[strMulti[i] - 48]++;
	}


	for (int i = 0; i < 10; ++i)
	{
		cout << iArray[i] << endl;
	}


	return 0;
}