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

//pair<int, int> Find_RD(pair<int, int> rd, int i, int j)
//{
//    if (i > rd.first && j > rd.second)
//    {
//        return rd;
//    }
//    else if (i < rd.first && j < rd.second)
//    {
//        return { i, j };
//    }
//    else if (i < rd.first)
//    {
//        return { i, rd.second };
//    }
//    else if (j < rd.second)
//    {
//        return { rd.first, j };
//    }
//    else
//        return rd;
//}
//
//pair<int, int> Find_LD(pair<int, int> ld, int i, int j)
//{
//    if (i < ld.first && j < ld.second)
//    {
//        return ld;
//    }
//    else if (i > ld.first && j > ld.second)
//    {
//        return { i, j };
//    }
//    else if (i > ld.first)
//    {
//        return { i, ld.second };
//    }
//    else if (j > ld.second)
//    {
//        return { ld.first, j };
//    }
//    else
//        return ld;
//}

vector<int> solution(vector<string> wallpaper) 
{
    int iHeight = wallpaper.size();
    int iWidth = wallpaper.front().length();

    pair<int, int> rd = {-1,-1};
    pair<int, int> ld = {-1,-1};

    for (int i = 0; i < iHeight; i++)
    {
        for (int j = 0; j < iWidth; j++)
        {
            if ('#' == wallpaper[i][j])
            {
                if (-1 == rd.first)
                {
                    rd = { i, j };
                    ld = { i + 1, j + 1 };
                }
                else
                {
                    rd.first = min(rd.first, i);
                    rd.second = min(rd.second, j);

                    ld.first = max(ld.first, i+1);
                    ld.second = max(ld.second, j+1);
                }
            }
        }
    }

    vector<int> answer;

    answer.push_back(rd.first);
    answer.push_back(rd.second);
    answer.push_back(ld.first);
    answer.push_back(ld.second);

    return answer;
}

int main()
{
  
    int iMax = 5;
    vector<string> wallpaper;
    string iPaper;

    for (size_t i = 0; i < iMax; i++)
    {
        iPaper.clear();
        cin >> iPaper;
        wallpaper.push_back(iPaper);
    }

    solution(wallpaper);

    return 0;
} 