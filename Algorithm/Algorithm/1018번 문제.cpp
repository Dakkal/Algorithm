#include <iostream>
#include <string>
using namespace std;

string WB[8] = {
       "WBWBWBWB",
       "BWBWBWBW",
       "WBWBWBWB",
       "BWBWBWBW",
       "WBWBWBWB",
       "BWBWBWBW",
       "WBWBWBWB",
       "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

string ChessBord[50];

int WB_Cnt(int X, int Y)
{
    int iCnt = 0;

    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if (ChessBord[X + i][Y + j] != WB[i][j])
                iCnt++;
        }
    }

    return iCnt;
}

int BW_Cnt(int X, int Y)
{
    int iCnt = 0;

    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if (ChessBord[X + i][Y + j] != BW[i][j])
                iCnt++;
        }
    }

    return iCnt;
}

int main()
{
    unsigned int iMin = -1;
    pair<int, int> p1;
    cin >> p1.first >> p1.second;

    for (int i = 0; i < p1.first; i++)
    {
        cin >> ChessBord[i];
    }

    for (int i = 0; i + 8 <= p1.first; i++)
    {
        for (int j = 0; j + 8 <= p1.second; j++)
        {
            int iResult;
            iResult = min(WB_Cnt(i, j), BW_Cnt(i, j));
            if (iResult < iMin)
            {
                iMin = iResult;
            }
        }
    }

    cout << iMin;
    return 0;
}
   