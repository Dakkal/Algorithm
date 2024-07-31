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

int solution(int n, int m, vector<int> section) 
{
    /* 왠만하면 컨테이너의 사이즈를 건들지는 말자 시간초과 오진다*/
    //vector<int> paint = section;
    //int iSize = section.size();
    //int answer = 0;

    //while (0 != paint.size())
    //{
    //    int iPainted = paint.front() + m - 1;

    //    for (auto iter = paint.begin(); iter != paint.end(); )
    //    {
    //        if (*iter >= paint.front() && *iter <= iPainted)
    //        {
    //            iter = paint.erase(iter);
    //        }
    //        else
    //        {
    //            ++iter;
    //        }
    //    }

    //    ++answer;
    //}

    int answer = 1;
    int pivot = section.front();
    for (const auto& wall : section)
    {
        if (wall < pivot + m)
        {
            continue;
        }
        else
        {
            pivot = wall;
            ++answer;
        }
    }

    return answer;
}

int main()
{
    int n = 8;
    int m = 4;
    vector<int> sector = { 2, 3, 6};

    solution(n, m, sector);

    return 0;
} 