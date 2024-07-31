#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <string_view>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <any>

using namespace std;

enum { YEAR, MONTH, DATE };

vector<int> dividedate(string day)
{
    vector<int> date;
    string divide = day;
    string forStoi;

    for (size_t i = 0; i < 3; i++)
    {
        forStoi.clear();
        auto pos = divide.find('.');

        if (string::npos != pos)
        {
            forStoi = divide.substr(0, pos);
        }
        else
        {
            forStoi = divide;
        }

        int day = stoi(forStoi);
        date.push_back(day);

        if (string::npos != pos) 
        {
            divide.erase(0, pos + 1);
        }
    }

    return date;
}

bool checkexpire(vector<int> today, vector<int> cmpday, string arg, unordered_map<string, int> termmap)
{
    auto iter = termmap.find(arg);
    int termdate = iter->second;

    int calmonth = cmpday[MONTH] + termdate;

    while (calmonth > 12)
    {
        calmonth -= 12;
        ++cmpday[YEAR];
    }

    cmpday[MONTH] = calmonth;
    cmpday[DATE] -= 1;
    if (cmpday[DATE] <= 0)
    {
        cmpday[MONTH] -= 1;
        if (cmpday[MONTH] <= 0)
        {
            cmpday[MONTH] = 12;
            --cmpday[YEAR];
        }
        cmpday[DATE] = 28;
    }

    if (today[YEAR] > cmpday[YEAR])
    {
        return true;
    }
    else if (today[YEAR] == cmpday[YEAR] && today[MONTH] > cmpday[MONTH])
    {
        return true;
    }
    else if (today[YEAR] == cmpday[YEAR] && today[MONTH] == cmpday[MONTH] && today[DATE] > cmpday[DATE])
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    vector<int> answer;

    vector<int> divtoday = dividedate(today);

    unordered_map<string, int> termmap;
    for (auto term : terms)
    {
        string arg;
        size_t spacePos = term.find(' ');
        arg = term.substr(0, spacePos);
        int expire = stoi(term.substr(spacePos + 1));
        termmap[arg] = expire;
    }

    int iCnt = 0;
    for (auto privacy : privacies)
    {
        string date;
        string arg;

        auto pos = privacy.find(' ');

        date = privacy.substr(0, pos);
        arg = privacy.substr(pos + 1);

        ++iCnt;
        if (true == checkexpire(divtoday, dividedate(date), arg, termmap))
        {
            answer.push_back(iCnt);
        }
    }

    return answer;
}

int main()
{
    string today = "2022.05.19";
    vector<string> terms = { "A 6", "B 12", "C 3" };
    vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };

    solution(today, terms, privacies);

    return 0;
} 