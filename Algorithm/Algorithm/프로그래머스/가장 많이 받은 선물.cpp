#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<pair<string, string>> SplitGift(vector<string> gifts)
{
    vector<pair<string, string>> SplitGift;

    for (auto& gift : gifts)
    {
        string Give;
        string Take;

        int iBlank = gift.find_first_of(" ");
        Give = gift.substr(0, iBlank);
        Take = gift.substr(iBlank + 1, string::npos);

        SplitGift.push_back(make_pair(Give, Take));
    }

    return SplitGift;
}

/* ±ÚªÔ«— ¡§¥‰ */
int solution(vector<string> friends, vector<string> gifts)
{
    int answer = 0;

    int iFriendSize = friends.size();

    map<string, int> friendsIndex;
    for (int i = 0; i < iFriendSize; i++)
    {
        friendsIndex[friends[i]] = i;
    }
    vector<pair<string, string>> SplitedGifts = SplitGift(gifts);

    map<string, int> GiftCount;
    vector<vector<int>> GiftTable(iFriendSize, vector<int>(iFriendSize, 0));
    vector<int> NextMonthGift(iFriendSize, 0);

    for (auto gift : SplitedGifts)
    {
        int iGive = friendsIndex[gift.first];
        int iTake = friendsIndex[gift.second];

        GiftTable[iGive][iTake]++;
        GiftCount[gift.first]++;
        GiftCount[gift.second]--;
    }

    for (int i = 0; i < iFriendSize; i++)
    {
        for (int j = 0; j < iFriendSize; j++)
        {
            if (i == j) continue;

            if (GiftTable[i][j] > GiftTable[j][i] || (GiftTable[i][j] == GiftTable[j][i] && GiftCount[friends[i]] > GiftCount[friends[j]])) 
            {
                NextMonthGift[i]++;
            }
        }
    }

    answer = *max_element(NextMonthGift.begin(), NextMonthGift.end());


    return answer;
}

//map<string, int> CheckGiftFactor(vector<string> friends, vector<pair<string, string>> gifts)
//{
//    map<string, int> GiftFactor;
//
//
//    for (auto& Name : friends)
//    {
//        int iGive = 0;
//        int iTake = 0;
//
//        for (auto& gift : gifts)
//        {
//           
//            if (gift.first == Name)
//            {
//                iGive++;
//            }
//            else if (gift.second == Name)
//            {
//                iTake++;
//            }
//        }
//
//        int Factor = iGive - iTake;
//        GiftFactor.emplace(Name, Factor);
//    }
//
//    return GiftFactor;
//}
//
//int Find_TopGift(vector<string> friends, vector<pair<string, string>> GiftPair, map<string, int> GiftFactor)
//{
//    int iTopScore = 0;
//
//    for (auto& Name : friends)
//    {
//        int iMonthGift = 0;
//
//        for (auto& CompareName : friends)
//        {
//            if (Name == CompareName)
//                continue;
//
//            int iNameGive = 0;
//            int iComNameGive = 0;
//
//            for (auto& Gift : GiftPair)
//            {
//                if (Name == Gift.first && CompareName == Gift.second)
//                {
//                    iNameGive++;
//                }
//                else if (Name == Gift.second && CompareName == Gift.first)
//                {
//                    iComNameGive++;
//                }
//            }
//
//            if (iNameGive > iComNameGive)
//            {
//                iMonthGift++;
//            }
//            else if (iNameGive == iComNameGive)
//            {
//                if (GiftFactor.find(Name)->second > GiftFactor.find(CompareName)->second)
//                {
//                    iMonthGift++;
//                }
//            }
//        }
//
//        if (iMonthGift > iTopScore)
//            iTopScore = iMonthGift;
//    }
//
//    return iTopScore;
//}
//
//
//int solution(vector<string> friends, vector<string> gifts) 
//{
//    int answer = 0;
//
//    vector<pair<string, string>> GiftPairs = SplitGift(gifts);
//
//    map<string, int> GiftFactors = CheckGiftFactor(friends, GiftPairs);
//
//    answer = Find_TopGift(friends, GiftPairs, GiftFactors);
//
//    return answer;
//}

int main()
{
    int iFriendNumb = 0;
    vector<string> Friends;
    
    int iGiftNumb = 0;
    vector<string> Gifts;

    cout << "ƒ£±∏ ºˆ : ";
    cin >> iFriendNumb;

    for (size_t i = 0; i < iFriendNumb; i++)
    {
        string FriendName;
        
        cin >> FriendName;

        Friends.push_back(FriendName);
    }
   

    cout << "º±π∞ »Ωºˆ : ";
    cin >> iGiftNumb;
    cin.ignore();

    for (size_t i = 0; i < iGiftNumb; i++)
    {
        string GiftName;

        getline(cin, GiftName);

        Gifts.push_back(GiftName);
    }

    cout << solution(Friends, Gifts) << endl;

    return 0;
} 