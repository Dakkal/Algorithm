#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using namespace std;

int CheckBox(vector<int>& Cards, vector<bool>& Box, int iSelectNumb)
{
    int iCount = 0;
    while (false == Box[iSelectNumb])
    {
        Box[iSelectNumb] = true;
        iSelectNumb = Cards[iSelectNumb] - 1;
        iCount++;
    }
    return iCount;
}

int solution(vector<int> cards) 
{
    int iAnswer = 0;

    int iCardSize = cards.size();

    for (size_t i = 0; i < iCardSize; i++)
    {
        vector<bool> Box1(iCardSize, false);

        int iCount1 = CheckBox(cards, Box1, i);

        for (size_t j = 0; j < iCardSize; j++)
        {
            if (true == Box1[j])
                continue;

            vector<bool> Box2 = Box1;

            int iCount2 = CheckBox(cards, Box2, j);

            int iScore = iCount1 * iCount2;
            iAnswer = max(iAnswer, iScore);
        }
    }

    return iAnswer;
}

int main()
{
    vector<int> vecCards;
    size_t iCardNumb = 0;

    cout << "입력할 카드갯수 선택 : ";
    cin >> iCardNumb;

    for (size_t i = 0; i < iCardNumb; i++)
    {
        int iNumb = 0;

        cin >> iNumb;

        vecCards.push_back(iNumb);
    }

    cout << solution(vecCards) << endl;

    return 0;
} 