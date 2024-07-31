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

string solution(string s, string skip, int index) 
{
    string answer;

    int iA = static_cast<int>('a');
    int iZ = static_cast<int>('z');

    set<int> Alphabet;

    for (size_t i = iA; i < iZ + 1; i++)
    {
        Alphabet.emplace(i);
    }
   
    for (size_t i = 0; i < skip.size(); i++)
    {
        auto iter = Alphabet.find(static_cast<int>(skip[i]));
        if (Alphabet.end() != iter)
        {
            Alphabet.erase(iter);
        }
    }

    for (size_t i = 0; i < s.size(); i++)
    {
        auto Start = Alphabet.find(static_cast<int>(s[i]));
        for (size_t j = 0; j < index; j++)
        {
            Start++;
            if (Alphabet.end() == Start)
                Start = Alphabet.begin();
        }

        answer.push_back(static_cast<char>(*Start));
    }


    return answer;
}

int main()
{
    string s = "aukks";
    string skip = "wbqd";
    int index = 5;

    solution(s, skip, index);

    return 0;
} 