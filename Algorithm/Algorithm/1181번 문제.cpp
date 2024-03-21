#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int             iStrNumb;
    string          strName;
    vector<string>  vecName;

    cin >> iStrNumb;

    for (size_t i = 0; i < iStrNumb; i++)
    {
        cin >> strName;
       
        vecName.push_back(strName);
    }

    std::stable_sort(vecName.begin(), vecName.end(), [](const string& Src, const string& Dest)
        {
            if (Src.size() != Dest.size())
            {
                return Src.size() < Dest.size();
            }
            else
            {
                return Src < Dest;
            }
        });

    auto last = std::unique(vecName.begin(), vecName.end());
    vecName.erase(last, vecName.end());

    for (size_t i = 0; i < vecName.size(); i++)
    {
        cout << vecName[i] << '\n';
    }

    return 0;
} 