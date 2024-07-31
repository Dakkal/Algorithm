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

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    string answer = "Yes";

    vector<int> FirstSen = { -1 };
    vector<int> SecondSen = { -1 };

    int GoalSize = goal.size();
    int Card1Size = cards1.size();
    int Card2Size = cards2.size();

    bool breakpoint = false;

    for (int i = 0; i < GoalSize; i++)
    {
        for (int j = 0; j < Card1Size; j++)
        {
            if (cards1[j] == goal[i])
            {
                if (j < FirstSen.back() || 1 < j - FirstSen.back())
                {
                    answer = "No";
                    breakpoint = true;
                    break;
                }

                FirstSen.push_back(j);
            }
        }

        if (true == breakpoint)
            break;

        for (int k = 0; k < Card2Size; k++)
        {
            if (cards2[k] == goal[i])
            {
                if (k < SecondSen.back() || 1 < k - SecondSen.back())
                {
                    answer = "No";
                    breakpoint = true;
                    break;
                }

                SecondSen.push_back(k);
            }
        }

        if (true == breakpoint)
            break;
    }

    return answer;
}

int main()
{
    vector<string> cards1 = { "i", "drink", "water" };
    vector<string> cards2 = { "want", "to" };
    vector<string> goal = { "i", "want", "to", "drink", "water" };

    solution(cards1, cards2, goal);

    return 0;
} 