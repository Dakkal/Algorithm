#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <charconv>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) 
{
    int answer = {};
    string strSelectColor = board[h][w];

    int iCheck_H[4] = { h-1, h, h+1, h };
    int iCheck_W[4] = { w, w+1, w, w-1};

    for (size_t i = 0; i < 4; i++)
    {
        if (iCheck_H[i] < 0 || iCheck_H[i] >= board.size() ||
            iCheck_W[i] < 0 || iCheck_W[i] >= board.front().size())
            continue;

        if (strSelectColor == board[iCheck_H[i]][iCheck_W[i]])
        {
            answer++;
        }
    }


    return answer;
}

int main()
{
    vector<vector<string>> Board;
    int iBoardNumb = {};

    int iColorNumb = {};
    string strColor;
  
    int iHeight = {};
    int iWidth = {};

    cout << "보드 수 : ";
    cin >> iBoardNumb;
    Board.resize(iBoardNumb);

    cout << "컬러 수 : ";
    cin >> iColorNumb;

    for (size_t i = 0; i < iBoardNumb; i++)
    {
        cout << i + 1 << "번째 보드" << endl;

        for (size_t j = 0; j < iColorNumb; j++)
        {
            cout << j + 1 << "번째 컬러 : ";
            cin >> strColor;
            Board[i].push_back(strColor);
        }
    }

    cout << endl;
    cout << "높이 : ";
    cin >> iHeight;
    cout << "넓이 : ";
    cin >> iWidth;


    // 솔루션 
    cout << solution(Board, iHeight, iWidth) << endl;

    return 0;
} 