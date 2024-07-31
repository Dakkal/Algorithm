#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <string_view>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <any>
#include <set>
#include <queue>

using namespace std;

void SelectionSort(vector<int>& Array) 
{
    /*
    ��������
    1��°���� ������ �Ⱦ ���� ���� �� 1��°, 2��°���� ������ �Ⱦ ���� ���� �� 2��°... ������ ���� ������ �ݺ��Ѵ�. 
    �̹� ���ĵǾ� �ִ� �ڷᱸ���� ����/���� �� ���� �迭�� ���� ��쿡�� �ſ� ȿ�����̴�.

    �ð����⵵ : O(N^2)
    */

    int ArrSize = Array.size();

    for (int i = 0; i < ArrSize - 1; i++) 
    {
        int minIdx = i;
        for (int j = i + 1; j < ArrSize; j++) 
        {
            if (Array[j] < Array[minIdx])
            {
                minIdx = j;
            }
        }
        swap(Array[i], Array[minIdx]);
    }
}


void InsertionSort(vector<int>& Array)
{
    /*
    ��������
    k��° ���Ҹ� 1���� k-1������ ���� ������ ��ġ�� �����ְ� 
    �� ���� �ڷḦ �� ĭ�� �ڷ� �о�� ����̴�.

    �ð����⵵ : O(N^2)
    */

    int ArrSize = Array.size();

    for (int i = 1; i < ArrSize; i++)
    {
        int tmp = Array[i];
        int j = i - 1;
        while (j >= 0 && tmp < Array[j])
        {
            Array[j + 1] = Array[j];
            j--;
        }
        Array[j + 1] = tmp;
    }
}


void BubbleSort(vector<int>& Array)
{
    /*
    ��������
    �ð� ���⵵�� �������� �ڵ尡 �ܼ��ϴ�. 
    �յ� ������ ũ�⸦ ���Ͽ� �����ϴ� ����̴�.

    �ð����⵵ : O(N^2)
    */

    int ArrSize = Array.size();

    for (int i = 0; i < ArrSize - 1; i++)
    {
        for (int j = 0; j < ArrSize - i - 1; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                swap(Array[j], Array[j + 1]);
            }
        }
    }
}


void Merge(vector<int>& Array, int Left, int Mid, int Right)
{

    int n1 = Mid - Left + 1;
    int n2 = Right - Mid;

    vector<int> LeftArr(n1);
    vector<int> RightArr(n2);

    for (int i = 0; i < n1; ++i)
        LeftArr[i] = Array[Left + i];
    for (int i = 0; i < n2; ++i)
        RightArr[i] = Array[Mid + 1 + i];

    int i = 0, j = 0, k = Left;

    while (i < n1 && j < n2)
    {
        if (LeftArr[i] <= RightArr[j])
        {
            Array[k] = LeftArr[i];
            ++i;
        }
        else
        {
            Array[k] = RightArr[j];
            ++j;
        }
        ++k;
    }

    /* ���� ��� �߰� */
    while (i < n1)
    {
        Array[k] = LeftArr[i];
        ++i;
        ++k;
    }
    while (j < n2)
    {
        Array[k] = RightArr[j];
        ++j;
        ++k;
    }
}
void MergeSort(vector<int>& Array, int Left/*�迭ù��°*/, int Right/*�迭������ -1*/)
{
    /*
    ��������
    �迭�� ���̰� 1�� �� ������ 2���� �κ� �迭�� �����Ѵ�.
    �� ��, 2���� �κ� �迭�� �պ��ϰ� �����Ѵ�. ��� �κ� �迭�� �պ��� ������ �ݺ��Ѵ�.
    �κ� �迭�� ���� �߰����� �޸� ������ �ʿ��ϴٴ� ������ �ִ�.

    �ð����⵵ : O(nlogn)
    */


    if (Left < Right)
    {
        int Mid = Left + (Right - Left) / 2;

        MergeSort(Array, Left, Mid);
        MergeSort(Array, Mid + 1, Right);

        Merge(Array, Left, Mid, Right);
    }
}


void HeapSort(vector<int>& Array);
void Heapify(vector<int>& Array, int parentIdx, int lastIdx);

void HeapSort(vector<int>& Array)
{
    /*
    ������
    ���� ���İ� ���� ������, ���� ����ؼ� ���� ū ���Ҹ� ã�´ٴ� �������� �ִ�.
    Ʈ�� ������� �ִ� �� Ʈ��(��������), �ּ� �� Ʈ��(��������)�� ������ �����Ѵ�.
    �׻� nlogn�� ������ ������ ���� �������� ������ ���δ�.
    �ٸ�, �����δ� �������� �Ϲ������� ������.

    �ð����⵵ : O(nlogn)
    */

    int ArrSize = Array.size();

    for (int i = (ArrSize / 2) - 1; i >= 0; i--)
    {
        Heapify(Array, i, ArrSize - 1);
    }
    for (int i = ArrSize - 1; i >= 0; i--)
    {
        swap(Array[0], Array[i]);
        Heapify(Array, 0, i - 1);
    }
}
void Heapify(vector<int>& Array, int parentIdx, int lastIdx) 
{
    int leftChildIdx;
    int rightChildIdx;
    int largestIdx;

    while (parentIdx * 2 + 1 <= lastIdx) 
    {
        leftChildIdx = (parentIdx * 2) + 1;
        rightChildIdx = (parentIdx * 2) + 2;
        largestIdx = parentIdx;

        if (Array[leftChildIdx] > Array[largestIdx])
        {
            largestIdx = leftChildIdx;
        }
        if (rightChildIdx <= lastIdx && Array[rightChildIdx] > Array[largestIdx])
        {
            largestIdx = rightChildIdx;
        }
        if (largestIdx != parentIdx) 
        {
            swap(Array[parentIdx], Array[largestIdx]);
            parentIdx = largestIdx;
        }
        else 
        {
            break;
        }
    }
}

void QuickSort(vector<int>& Array);
void QuickSort(vector<int>& Array, int Left, int Right);
int Partition(vector<int>& Array, int Left, int Right);

void QuickSort(vector<int>& Array) 
{
    /*
    ������ ���� ���� ���� ����(�ǹ�)���� ���ϰ�, ������ �ش� �ǹ��� �������� �� ���� �κ� �������� ������. 
    �� �� ���տ��� �ǹ����� ���� ����, ������ �� �� ���տ��� �ǹ����� ū ���� �ִ´�. 
    �� �̻� �ɰ� �κ� ������ ���� ������ �� ������ �ݺ��Ѵ�.
    
    �ð����⵵ : O(nlogn) �ٸ� �ǹ��� ����� �������� �־����� �ٲ�
    */

    QuickSort(Array, 0, Array.size() - 1);
}
void QuickSort(vector<int>& Array, int Left, int Right)
{
    if (Left < Right)
    {
        int Part = Partition(Array, Left, Right);

        if (Left < Part - 1)
        {
            QuickSort(Array, Left, Part - 1);
        }
        if (Part < Right)
        {
            QuickSort(Array, Part, Right);
        }
    }
}
int Partition(vector<int>& Array, int Left, int Right)
{
    int Pivot = Array[(Left + Right) / 2];

    while (Left <= Right) // �ش� �κ� �迭�� ���� �ݺ�
    { 
        while (Array[Left] < Pivot) //�ǹ����� ū left�� ã��
        { 
            Left++;
        }
        while (Array[Right] > Pivot) // �ǹ����� ���� right�� ã��
        { 
            Right--;
        }
        if (Left <= Right) //left�� right���� ���ʿ� ������ ���� �ڸ� �ٲ�
        { 
            swap(Array[Left], Array[Right]);
            Left++;
            Right--;
        }
    }
    return Left;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = { 38, 27, 43, 3, 9, 82, 10 };
    QuickSort(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
} 