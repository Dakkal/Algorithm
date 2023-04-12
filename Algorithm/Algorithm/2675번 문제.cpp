#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int iMake;
	int iRe;
	int iCount = 0;
	string strName;
	
	cin >> iMake;

	for (int i = 0; i < iMake; ++i)
	{
		cin >> iRe >> strName;
	
		for (int i = 0; i < strName.length(); ++i)
		{
			for (int j = 0; j < iRe; ++j)
			{
				cout << strName[i];

			}
		}

		cout << endl;
	}


	return 0;
}