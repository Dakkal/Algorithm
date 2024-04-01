#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using namespace std;

int CheckBox(vector<int>& Cards, bool* pBox, int iSelectNumb)
{
    int iCount = 0;
    while (false == pBox[iSelectNumb])
    {
        pBox[iSelectNumb] = true;
        iSelectNumb = Cards[iSelectNumb] - 1;
        iCount++;
    }
    return iCount;
}

int solution(vector<int> cards) 
{
    int iAnswer = 0;

    for (size_t i = 0; i < cards.size(); i++)
    {
        bool* pBox1 = new bool[cards.size()];
        for (size_t i = 0; i < cards.size(); i++)
        {
            pBox1[i] = false;
        }

        int iCount1 = CheckBox(cards, pBox1, i);

        for (size_t j = 0; j < cards.size(); j++)
        {
            if (true == pBox1[j])
                continue;

            bool* pBox2 = pBox1;

            int iCount2 = CheckBox(cards, pBox2, j);

            int iScore = iCount1 * iCount2;
            iAnswer = max(iAnswer, iScore);
        }
    }

    return iAnswer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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