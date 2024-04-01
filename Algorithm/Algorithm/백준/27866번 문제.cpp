#include <iostream>
#include <string>
using namespace std;

int main()
{
    string strName;
    int iCount;

    cin >> strName;
    cin >> iCount;

    if (strName.size() - 1 > 1000)
    {
        cout << "Out of Range index." << endl;
    }
    else if (iCount < 1 || iCount > strName.size())
    {
        cout << "Invalid index." << endl;
    }
    else
    {
        cout << strName[iCount - 1] << endl;
    }

    return 0;
}