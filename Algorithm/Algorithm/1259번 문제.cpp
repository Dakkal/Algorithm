#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iNumb;
    int iRevNumb;
    string strNumb;
    string strRevNumb;
    vector<int> vecNumb;
    vector<int> vecRevNumb;

    while (true)
    {
        cin >> iNumb;
        if (0 == iNumb)
            break;

        vecNumb.push_back(iNumb);

        strRevNumb = std::to_string(iNumb);
        std::reverse(strRevNumb.begin(), strRevNumb.end());
        iRevNumb = std::stoi(strRevNumb);
        vecRevNumb.push_back(iRevNumb);
    }

   
    for (size_t i = 0; i < vecNumb.size(); i++)
    {
        if (vecNumb[i] == vecRevNumb[i])
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }


    return 0;
} 