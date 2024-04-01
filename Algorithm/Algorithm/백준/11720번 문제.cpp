#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int iSize;
	string strNumb;
	int iSum(0);

	cin >> iSize;
	cin >> strNumb;

	int* iArray = new int[iSize];

	for (int i = 0; i < iSize; ++i)
	{
		iArray[i] = (int)strNumb[i] - 48;
	}

	cout << iArray[0] << endl;

	for (int i = 0; i < iSize; ++i)
	{
		iSum += iArray[i];
	}

	cout << iSum << endl;

	return 0;
}

//int main()
//{
//	int iSize;
//	int iNumb;
//	int iNumb2;
//	int iSum(0);
//
//	cin >> iSize;
//	cin >> iNumb;
//
//	int* iArray = new int[iSize];
//
//	for (int i = 0; i < iSize; ++i)
//	{
//		iNumb2 = iNumb / pow(10, iSize - (i + 1));
//		iArray[i] = iNumb2 % 10;
//	}
//
//	for (int i = 0; i < iSize; ++i)
//	{
//		iSum += iArray[i];
//	}
//
//	cout << iSum << endl;
//
//	return 0;
//}