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
    선택정렬
    1번째부터 끝까지 훑어서 가장 작은 게 1번째, 2번째부터 끝까지 훑어서 가장 작은 게 2번째... 정렬이 끝날 때까지 반복한다. 
    이미 정렬되어 있는 자료구조에 삽입/제거 할 때나 배열이 작은 경우에는 매우 효율적이다.

    시간복잡도 : O(N^2)
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
    삽입정렬
    k번째 원소를 1부터 k-1까지와 비교해 적절한 위치에 끼워넣고 
    그 뒤의 자료를 한 칸씩 뒤로 밀어내는 방식이다.

    시간복잡도 : O(N^2)
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
    버블정렬
    시간 복잡도가 안좋지만 코드가 단순하다. 
    앞뒤 원소의 크기를 비교하여 스왑하는 방식이다.

    시간복잡도 : O(N^2)
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

    /* 남은 요소 추가 */
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
void MergeSort(vector<int>& Array, int Left/*배열첫번째*/, int Right/*배열마지막 -1*/)
{
    /*
    병합정렬
    배열의 길이가 1이 될 때까지 2개의 부분 배열로 분할한다.
    그 후, 2개의 부분 배열을 합병하고 정렬한다. 모든 부분 배열이 합병될 때까지 반복한다.
    부분 배열을 위한 추가적인 메모리 공간이 필요하다는 단점이 있다.

    시간복잡도 : O(nlogn)
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
    힙정렬
    선택 정렬과 거의 같지만, 힙을 사용해서 가장 큰 원소를 찾는다는 차이점이 있다.
    트리 기반으로 최대 힙 트리(내림차순), 최소 힙 트리(오름차순)을 구성해 정렬한다.
    항상 nlogn의 성능을 발휘해 가장 안정적인 성능을 보인다.
    다만, 실제로는 퀵정렬이 일반적으로 빠르다.

    시간복잡도 : O(nlogn)
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
    데이터 집합 내에 임의 기준(피벗)값을 정하고, 집합을 해당 피벗을 기준으로 두 개의 부분 집합으로 나눈다. 
    한 쪽 집합에는 피벗보다 작은 값을, 나머지 한 쪽 집합에는 피벗보다 큰 값을 넣는다. 
    더 이상 쪼갤 부분 집합이 없을 때까지 위 과정을 반복한다.
    
    시간복잡도 : O(nlogn) 다만 피벗이 제대로 안잡히면 최악으로 바뀜
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

    while (Left <= Right) // 해당 부분 배열에 대해 반복
    { 
        while (Array[Left] < Pivot) //피벗보다 큰 left를 찾음
        { 
            Left++;
        }
        while (Array[Right] > Pivot) // 피벗보다 작은 right를 찾음
        { 
            Right--;
        }
        if (Left <= Right) //left가 right보다 왼쪽에 있으면 둘이 자리 바꿈
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