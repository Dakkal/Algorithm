#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <string_view>
#include <vector>
#include <list>
#include <map>

using namespace std;

enum class DATA { CODE, DATE, MAXIMUM, REMAIN, DATA_END };

int by_Data(string_view bench_data)
{
    if ("code" == bench_data)
    {
        return (int)DATA::CODE;
    }
    else if ("date" == bench_data)
    {
        return (int)DATA::DATE;
    }
    else if ("maximum" == bench_data)
    {
        return (int)DATA::MAXIMUM;
    }
    else if ("remain" == bench_data)
    {
        return (int)DATA::REMAIN;
    }
    else
        return -1;
}

vector<vector<int>> Find_Ext_Datas(vector<vector<int>> data, int ext, int val_ext)
{
    vector<vector<int>> ext_data;

    for (auto& data : data)
    {
        if (data[ext] < val_ext)
        {
            ext_data.push_back(data);
        }
    }
    return ext_data;

}

void Sort_Data(vector<vector<int>>& ext_data, int sort_by)
{
    std::stable_sort(ext_data.begin(), ext_data.end(), [&](vector<int> Src, vector<int> Dst) {

        return Src[sort_by] < Dst[sort_by];

        });
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by)
{
    vector<vector<int>> answer;

    int iExt = by_Data(ext);
    int iSort = by_Data(sort_by);

    answer = Find_Ext_Datas(data, iExt, val_ext);

    Sort_Data(answer, iSort);

    return answer;
}

int main()
{
    int iDataSize = 0;
    int iData[(int)DATA::DATA_END] = { 0 };
    vector<vector<int>> data;
    vector<int> entry_data;
    entry_data.reserve(4);

    cout << "데이터 갯수 : ";
    cin >> iDataSize;

    for (size_t i = 0; i < iDataSize; i++)
    {
        _Fill_zero_memset(iData, (int)DATA::DATA_END);

        for (size_t j = 0; j < 4; j++)
        {
            switch (j)
            {
            case (int)DATA::CODE:
                cout << "코드 : ";
                cin >> iData[(int)DATA::CODE];
                entry_data.push_back(iData[(int)DATA::CODE]);
                break;
            case (int)DATA::DATE:
                cout << "날짜 : ";
                cin >> iData[(int)DATA::DATE];
                entry_data.push_back(iData[(int)DATA::DATE]);
                break;
            case (int)DATA::MAXIMUM:
                cout << "최대 수량 : ";
                cin >> iData[(int)DATA::MAXIMUM];
                entry_data.push_back(iData[(int)DATA::MAXIMUM]);
                break;
            case (int)DATA::REMAIN:
                cout << "현재 수량 : ";
                cin >> iData[(int)DATA::REMAIN];
                entry_data.push_back(iData[(int)DATA::REMAIN]);
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
            case (int)DATA::CODE:
                cout << "코드 : " << out_data[i][j];
                break;
            case (int)DATA::DATE:
                cout << " 날짜 : " << out_data[i][j];
                break;
            case (int)DATA::MAXIMUM:
                cout << " 최대 수량 : " << out_data[i][j];
                break;
            case (int)DATA::REMAIN:
                cout << " 현재 수량 : " << out_data[i][j] << endl;
                break;
            default:
                break;
            }
        }
    }


    return 0;
} 