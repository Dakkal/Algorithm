#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <memory>

using namespace std;

enum DATA { CODE, DATE, MAXIMUM, REMAIN, DATA_END };

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) 
{
    vector<vector<int>> answer;

    return answer;
}

int main()
{
    int iDataSize = 0;
    int iData[DATA_END] = { 0 };
    vector<vector<int>> data;
    vector<int> entry_data;
    entry_data.reserve(4);

    cout << "데이터 갯수 : ";
    cin >> iDataSize;

    for (size_t i = 0; i < iDataSize; i++)
    {
        _Fill_zero_memset(iData, DATA_END);

        for (size_t j = 0; j < 4; j++)
        {
            switch (j)
            {
            case DATA::CODE:
                cout << "코드 : ";
                cin >> iData[DATA::CODE];
                entry_data.push_back(iData[DATA::CODE]);
                break;
            case DATA::DATE:
                cout << "날짜 : ";
                cin >> iData[DATA::DATE];
                entry_data.push_back(iData[DATA::DATE]);
                break;
            case DATA::MAXIMUM:
                cout << "최대 수량 : ";
                cin >> iData[DATA::MAXIMUM];
                entry_data.push_back(iData[DATA::MAXIMUM]);
                break;
            case DATA::REMAIN:
                cout << "현재 수량 : ";
                break;
            default:
                break;
            }
        }
    }

    string ext;
    cout << "데이터 기준 : ";
    cin >> ext;

    int val_ext;
    cout << "데이터 기준 값 : ";
    cin >> val_ext;

    string sort_by;
    cout << "데이터 정렬 기준 : ";
    cin >> sort_by;
  
    // 솔루션 
    vector<vector<int>> out_data = solution(data, ext, val_ext, sort_by);
    
    for (size_t i = 0; i < out_data.size(); i++)
    {
        cout << i << "번째 데이터" << endl;

        for (size_t j = 0; j < out_data[i].size(); j++)
        {
            switch (j)
            {
            case DATA::CODE:
                cout << "코드 : " << out_data[i][j];
                break;
            case DATA::DATE:
                cout << " 날짜 : " << out_data[i][j];
                break;
            case DATA::MAXIMUM:
                cout << " 최대 수량 : " << out_data[i][j];
                break;
            case DATA::REMAIN:
                cout << " 현재 수량 : " << out_data[i][j] << endl;
                break;
            default:
                break;
            }
        }
    }


    return 0;
} 