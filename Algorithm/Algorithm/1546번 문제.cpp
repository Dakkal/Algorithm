#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;


int main()
{
	int iSize;
	float iPoint;
	int iMax;
	float SumPoint = 0;
	float avr = 0;

	cin >> iSize;

	vector<float> vecPoint;
	vecPoint.reserve(iSize);

	for (int i = 0; i < iSize; ++i)
	{
		cin >> iPoint;
		vecPoint.push_back(iPoint);
	}

	sort(vecPoint.begin(), vecPoint.end(), greater<float>());

	iMax = vecPoint.front();

	for (auto iter = vecPoint.begin(); iter != vecPoint.end(); ++iter)
	{
		(*iter) = (((*iter)/iMax) * 100);
	}

	for (auto iter = vecPoint.begin(); iter != vecPoint.end(); ++iter)
	{
		SumPoint += (*iter);
	}

	avr = SumPoint / (float)iSize;

	cout << avr << endl;

	return 0;
}