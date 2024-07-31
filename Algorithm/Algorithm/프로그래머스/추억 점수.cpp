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

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) 
{
    int iNameCnt = name.size();

    unordered_map<string, int> match;
    match.reserve(iNameCnt);

    for (size_t i = 0; i < iNameCnt; i++)
    {
        match.emplace(name[i], yearning[i]);
    }

    vector<int> answer;

    for (size_t i = 0; i < photo.size(); i++)
    {
        int iAnswer = 0;

        for (size_t j = 0; j < photo[i].size(); j++)
        {
            if (match.end() != match.find(photo[i][j]))
            {
                iAnswer += match[photo[i][j]];
            }
        }

        answer.push_back(iAnswer);
    }

    return answer;
}

int main()
{



    return 0;
} 