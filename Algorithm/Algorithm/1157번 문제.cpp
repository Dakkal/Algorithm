#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string strName;
	int iArray[26] = { 0, };
	int iMax(0);
	char cAlpha;

	cin >> strName;


	for (auto iter = strName.begin(); iter != strName.end(); ++iter)
	{
		(*iter) = toupper(*iter);
	}

	for (int i = 0; i < strName.length(); ++i)
	{
		iArray[(int)strName[i] - 65] += 1;
	}

	for (int i = 0; i < 26; ++i)
	{
		if (iArray[i] == iMax)
		{
			cAlpha = '?';
		}
		else if (iArray[i] > iMax)
		{
			iMax = iArray[i];
			cAlpha = ('A' + i);
		}
	}


	cout << cAlpha << endl;

	return 0;
}