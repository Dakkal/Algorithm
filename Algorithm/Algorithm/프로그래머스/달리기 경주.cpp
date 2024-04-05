#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <string_view>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

/* �ӵ��� �̰� �� ���� */
void ReRank(unordered_map<string, int>& nameranking, unordered_map<int, string>& numbranking, string callname)
{
    auto Name_SelectPlayer = nameranking.find(callname);
    auto Numb_SelectPlayer = numbranking.find(Name_SelectPlayer->second);
    auto Numb_ChangePlayer = numbranking.find(Name_SelectPlayer->second - 1);
    auto Name_ChangePlayer = nameranking.find(Numb_ChangePlayer->second);

    Name_SelectPlayer->second--;
    Numb_SelectPlayer->second = Name_ChangePlayer->first;

    Name_ChangePlayer->second++;
    Numb_ChangePlayer->second = callname;
}

vector<string> solution(vector<string> players, vector<string> callings) 
{
    vector<string> answer;

    int iPlayerNumb = players.size();
    int iCallingNumb = callings.size();

    unordered_map<string, int> NameRanking;
    unordered_map<int, string> NumbRanking;

    for (size_t i = 0; i < iPlayerNumb; i++)
    {
        NameRanking.emplace(players[i], i);
        NumbRanking.emplace(i, players[i]);
    }

    for (size_t i = 0; i < callings.size(); i++)
    {
        ReRank(NameRanking, NumbRanking, callings[i]);
    }

    answer.resize(iPlayerNumb);
    for (auto& pair : NameRanking)
    {
        answer[pair.second] = pair.first;
    }
   

    return answer;
}

/* �� ����Ѱ� */
//vector<string> solution(vector<string> players, vector<string> callings)
//{
//    vector<string> answer;
//
//    int iPlayerNumb = players.size();
//    int iCallingNumb = callings.size();
//
//    unordered_map<string, int> Ranking;
//
//    for (size_t i = 0; i < iPlayerNumb; i++)
//    {
//        Ranking.emplace(players[i], i); 
//    }
//
//    int iChange, iSelect;
//    string tmp;
//
//    for (size_t i = 0; i < callings.size(); i++)
//    {
//        iSelect = Ranking[callings[i]];
//        iChange = iSelect - 1;
//
//        Ranking[players[iSelect]]--;
//        Ranking[players[iChange]]++;
//
//        tmp = players[iSelect];
//        players[iSelect] = players[iChange];
//        players[iChange] = tmp;
//    }
//
//    answer = players;
//
//    return answer;
//}

int main()
{
    int iPlayerSize = 0;
    int iCallingSize = 0;
    vector<string> Players;
    vector<string> Callings;
    string PlayerName;
    string CallName;

    cout << "�������� �� : ";
    cin >> iPlayerSize;
    Players.reserve(iPlayerSize);

    for (size_t i = 0; i < iPlayerSize; i++)
    {
        cout << "�������� �̸� : ";
        cin >> PlayerName;
        Players.push_back(PlayerName);
    }

    cout << "�θ� Ƚ�� : ";
    cin >> iCallingSize;
    Callings.reserve(iCallingSize);

    for (size_t i = 0; i < iCallingSize; i++)
    {
        cout << "�θ����� �̸� : ";
        cin >> CallName;
        Callings.push_back(CallName);
    }

    vector<string> Ranking = solution(Players, Callings);
    for (size_t i = 0; i < Ranking.size(); i++)
    {
        cout << Ranking[i] << endl;
    }

    return 0;
} 