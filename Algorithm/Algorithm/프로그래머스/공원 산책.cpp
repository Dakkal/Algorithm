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

vector<int> solution(vector<string> park, vector<string> routes) 
{
    vector<int> answer;
    answer.resize(2);
    
    int iParkH = park.size();
    int iParkW = park[0].length();

    for (size_t i = 0; i < iParkH; i++)
    {
        for (size_t j = 0; j < iParkW; j++)
        {
            if ('S' == park[i][j])
            {
                answer[0] = i;
                answer[1] = j;

                break;
            }
        }
    }
    
    
    vector<int> check;

    for (auto route : routes)
    {
        check = answer;

        if ('N' == route[0])
        {
            check[0] -= (route[2] - '0');
        }
        else if ('S' == route[0])
        {
            check[0] += (route[2] - '0');
        }
        else if ('W' == route[0])
        {
            check[1] -= (route[2] - '0');
        }
        else if ('E' == route[0])
        {
            check[1] += (route[2] - '0');
        }

        if (check[0] < 0 || check[0] >= iParkH || check[1] < 0 || check[1] >= iParkW)
        {
            continue;
        }


        bool bObsCheck = false;
        if (answer[0] == check[0]) 
        {
            int start = min(answer[1], check[1]);
            int end = max(answer[1], check[1]);
            for (int i = start; i <= end; ++i)
            {
                if (park[answer[0]][i] == 'X')
                {
                    bObsCheck = true;
                    break;
                }
            }
        }
        else if (answer[1] == check[1])
        {
            int start = min(answer[0], check[0]);
            int end = max(answer[0], check[0]);
            for (int i = start; i <= end; ++i)
            {
                if (park[i][answer[1]] == 'X')
                {
                    bObsCheck = true;
                    break;
                }
            }
        }

        if (false == bObsCheck)
        {
            answer = check;
        }  
    }

    return answer;
}

int main()
{
    vector<string> park;
    park.resize(4);

    cout << "공원" << endl;
    for (size_t i = 0; i < park.size(); i++)
    {
        cin >> park[i];
    }

    vector<string> routes;
    routes.resize(3);

    cout << "루트" << endl;
    for (size_t i = 0; i < routes.size(); i++)
    {
        cin >> routes[i];
    }


    solution(park, routes);

    return 0;
} 