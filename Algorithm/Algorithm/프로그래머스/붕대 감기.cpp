#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>

using namespace std;

enum BANDAGE    { TIME, RECOVER, EX_RECOVER, BANDANGE_END };
enum ATTACK     { ATK_TIME, ATK_DMG, ATK_END};


int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    int answer = 0;

    bool bIsAttacked = false;
    int iMaxHealth = health;
    int iHealth = health;
    int iBandageCnt = 0;
    int iMaxAttackTime = 0;

    stable_sort(attacks.begin(), attacks.end(), [](vector<int> SrcTime, vector<int> DstTime) {

            return SrcTime[ATTACK::ATK_TIME] < DstTime[ATTACK::ATK_TIME];
        });


    for (size_t i = 0; i < attacks.back()[ATTACK::ATK_TIME] + 1; i++)
    {
        bIsAttacked = false;

        for (size_t j = 0; j < attacks.size(); j++)
        {
            if (i == attacks[j][ATK_TIME])
            {
                iHealth -= attacks[j][ATK_DMG];
                if (0 < iBandageCnt)
                    iBandageCnt = 0;

                bIsAttacked = true;

                if (iHealth <= 0)
                    return -1;
            }
        }

        if (false == bIsAttacked)
        {
            // ȸ��
            iHealth += bandage[BANDAGE::RECOVER];
            if (iMaxHealth <= iHealth)
            {
                iHealth = iMaxHealth;
            }

            // �߰� ȸ��
            iBandageCnt++;
            if (iBandageCnt >= bandage[BANDAGE::TIME])
            {
                iHealth += bandage[BANDAGE::EX_RECOVER];
                if (iMaxHealth <= iHealth)
                {
                    iHealth = iMaxHealth;
                }

                iBandageCnt = 0;
            }
        }
       
    }

    answer = iHealth;

    return answer;
}

int main()
{
    int iHealth = 0;

    vector<int> Bandages;
    
    int iMonsterNumb = 0;

    // ü�� �Է�
    cout << "ü�� : ";
    cin >> iHealth;

    // �ش� �ɷ� �Է�
    for (size_t i = 0; i < 3; i++)
    {
        int iCaseNumb = 0;

        switch (i)
        {
        case BANDAGE::TIME:
            cout << "���� �ð� : ";
            cin >> iCaseNumb;
            Bandages.push_back(iCaseNumb);
            break;
        case BANDAGE::RECOVER:
            cout << "�ʴ� ȸ���� : ";
            cin >> iCaseNumb;
            Bandages.push_back(iCaseNumb);
            break;
        case BANDAGE::EX_RECOVER:
            cout << "�߰� ȸ���� : ";
            cin >> iCaseNumb;
            Bandages.push_back(iCaseNumb);
            break;
        default:
            break;
        }
    }
   
    // ���� �� �Է�
    cout << "���� �� : ";
    cin >> iMonsterNumb;
    vector<vector<int>> Attacks;
    Attacks.resize(iMonsterNumb);

    int iAttackTime = 0;
    int iAttackDmg = 0;

    // ���� ���� �ɷ� �Է�
    for (size_t i = 0; i < iMonsterNumb; i++)
    {
        cout << "���� �ð� : ";
        cin >> iAttackTime;
        Attacks[i].push_back(iAttackTime);

        cout << "���� ���ط� : ";
        cin >> iAttackDmg;
        Attacks[i].push_back(iAttackDmg);
    }
  
    // �ַ�� 
    cout << solution(Bandages, iHealth, Attacks) << endl;

    return 0;
} 