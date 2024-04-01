#include <iostream>
#include <string>
using namespace std;

int main()
{
	string strName;
	int iCount = 0;
	
	getline(cin, strName);

	auto iter = strName.begin();

	if (strName == " ")
	{
		cout << iCount << endl;
	}
	else
	{
		if ((*iter) == ' ') --iCount;

		iter = strName.end();
		--iter;
		if ((*iter) == ' ')  --iCount;

		for (iter = strName.begin(); iter != strName.end(); ++iter)
		{
			if ((*iter) == ' ')
			{
				++iCount;
			}
		}

		cout << iCount+1 << endl;
	}
	
	return 0;
}