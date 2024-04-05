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

    cout << "������ ���� : ";
    cin >> iDataSize;

    for (size_t i = 0; i < iDataSize; i++)
    {
        _Fill_zero_memset(iData, DATA_END);

        for (size_t j = 0; j < 4; j++)
        {
            switch (j)
            {
            case DATA::CODE:
                cout << "�ڵ� : ";
                cin >> iData[DATA::CODE];
                entry_data.push_back(iData[DATA::CODE]);
                break;
            case DATA::DATE:
                cout << "��¥ : ";
                cin >> iData[DATA::DATE];
                entry_data.push_back(iData[DATA::DATE]);
                break;
            case DATA::MAXIMUM:
                cout << "�ִ� ���� : ";
                cin >> iData[DATA::MAXIMUM];
                entry_data.push_back(iData[DATA::MAXIMUM]);
                break;
            case DATA::REMAIN:
                cout << "���� ���� : ";
                break;
            default:
                break;
            }
        }
    }

    string ext;
    cout << "������ ���� : ";
    cin >> ext;

    int val_ext;
    cout << "������ ���� �� : ";
    cin >> val_ext;

    string sort_by;
    cout << "������ ���� ���� : ";
    cin >> sort_by;
  
    // �ַ�� 
    vector<vector<int>> out_data = solution(data, ext, val_ext, sort_by);
    
    for (size_t i = 0; i < out_data.size(); i++)
    {
        cout << i << "��° ������" << endl;

        for (size_t j = 0; j < out_data[i].size(); j++)
        {
            switch (j)
            {
            case DATA::CODE:
                cout << "�ڵ� : " << out_data[i][j];
                break;
            case DATA::DATE:
                cout << " ��¥ : " << out_data[i][j];
                break;
            case DATA::MAXIMUM:
                cout << " �ִ� ���� : " << out_data[i][j];
                break;
            case DATA::REMAIN:
                cout << " ���� ���� : " << out_data[i][j] << endl;
                break;
            default:
                break;
            }
        }
    }


    return 0;
} 