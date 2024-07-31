#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <string_view>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <any>

using namespace std;

int find_key(vector<string> keymap, char target)
{
    int iLeast = -1;

    for (const auto& key : keymap)
    {
        int iPlace = key.find(target);

        if (string::npos == iPlace)
        {
            continue;
        }
        else
        {
            iPlace += 1;

            if (-1 == iLeast)
            {
                iLeast = iPlace;
            }
        }

        if (iPlace < iLeast)
        {
            iLeast = iPlace;
        }
    }

    return iLeast;
}

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    vector<int> answer;

    for (const auto& target : targets)
    {
        int iCnt = 0;
        int iResult = 0;

        for (const auto& target_v : target)
        {
            iResult = find_key(keymap, target_v);

            if (-1 == iResult)
            {
                answer.push_back(iResult);
                iCnt = -1;
                break;
            }

            iCnt += iResult;
        }

        if (-1 != iCnt)
        {
            answer.push_back(iCnt);
        }
    }

    return answer;
}

int main()
{
    vector<string> keymap = { "ABACD", "BCEFD" };
    vector<string> targets = { "ABCD","AABB" };

    solution(keymap, targets);

    return 0;
} 