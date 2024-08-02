#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <string_view>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <any>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<pair<int, int>>> tree;
int maxWidth = 0;
int dfs(int curNode, int weight)
{
	if (tree[curNode].empty())
		return weight;

	priority_queue<int> branches;
	for (auto& it : tree[curNode])
	{
		int temp = dfs(it.first, it.second);
		branches.push(temp);
	}
	int max1 = branches.top();
	branches.pop();
	if (!branches.empty())
	{
		int max2 = branches.top();
		if (maxWidth < max1 + max2)
			maxWidth = max1 + max2;
	}
	if (maxWidth < max1)
		maxWidth = max1;
	return max1 + weight;
}

int main()
{
	int nodeNum;
	cin >> nodeNum;
	tree = vector<vector<pair<int, int>>>(nodeNum + 1);
	for (int i = 0; i < nodeNum - 1; i++)
	{
		int parent, node, weight;
		cin >> parent >> node >> weight;
		tree[parent].push_back(make_pair(node, weight));
	}
	dfs(1, 0);
	cout << maxWidth;
	return 0;
}

//vector<pair<int, int>> FindFirstSecondWeight(vector<vector<pair<int, int>>> InNodes)
//{
//    int NodesSize = InNodes.size();
//    pair<int, int> Max1 = make_pair(0, 0), Max2 = make_pair(0, 0);
//    pair<int, int> Parents;
//    for (size_t i = 0; i < NodesSize; i++)
//    {
//        if (true == InNodes[i].empty()) continue;
//
//        for (auto Node : InNodes[i])
//        {
//            if (Max1.second < Node.second)
//            {
//                Max1 = Node;
//                Parents.first = i;
//            }
//            else if (Max2.second < Node.second)
//            {
//                Max2 = Node;
//                Parents.second = i;
//            }
//        }
//
//    }
//
//    vector<pair<int, int>> Combine;
//    Combine.push_back(Parents);
//    Combine.push_back(make_pair(Max1.second, Max2.second));
//
//    return Combine;
//}
//
//void FindMaxRad(vector<vector<pair<int, int>>> InNodes, int Max1, int Max2, int& Radius)
//{
// 
//    int NodesSize = InNodes.size();
//    int MaxParent1 = 0, MaxParent2 = 0;
//    for (size_t i = 0; i < NodesSize; i++)
//    {
//        if (true == InNodes[i].empty()) continue;
//       
//        bool SizeCheck = false;
//        if (InNodes[i].size() == 2)
//        {
//            SizeCheck = true;
//        }
//
//        
//        if ((true == SizeCheck) && (Max1 == InNodes[i][0].first && Max2 == InNodes[i][1].first))
//        {
//            int Sum = InNodes[i][0].second + InNodes[i][1].second;
//            Radius += Sum;
//            return;
//        }
//        else if((false == SizeCheck) && (Max1 == InNodes[i][0].first))
//        {
//            MaxParent1 = i;
//            Radius += InNodes[i][0].first;
//        }
//        else if ((true == SizeCheck) && (Max1 == InNodes[i][0].first || Max1 == InNodes[i][1].first))
//        {
//            MaxParent1 = i;
//            Radius += InNodes[i][0].first;
//        }
//        else if ((true == SizeCheck) && (Max2 == InNodes[i][0].first || Max2 == InNodes[i][1].first))
//        {
//            MaxParent2 = i;
//            Radius += InNodes[i][1].first;
//        }
//
//        if (0 != MaxParent1 && 0 != MaxParent2)
//            FindMaxRad(InNodes, MaxParent1, MaxParent2, Radius);
//    }
//   
//    
//
//    return;
//}
//
//int main()
//{
//    int NodeNum;
//    cin >> NodeNum;
//
//    int Parent, Child, Weight;
//    vector<vector<pair<int, int>>> Nodes;
//    Nodes.resize(NodeNum);
//    for (int Index = 1; Index < NodeNum; Index++)
//    {
//        cin >> Parent >> Child >> Weight;
//
//        Nodes[Parent].push_back(make_pair(Child, Weight));
//    }
//
//    int Radius = 0;
//    vector<pair<int, int>> Max1n2Node = FindFirstSecondWeight(Nodes);
//    if (Max1n2Node[0].first == Max1n2Node[0].second)
//    {
//        Radius = Max1n2Node[1].first + Max1n2Node[1].second;
//    }
//    else
//    {
//        Radius = Max1n2Node[1].first + Max1n2Node[1].second;
//        FindMaxRad(Nodes, Max1n2Node[0].first, Max1n2Node[0].second, Radius);
//    }
//    
//    cout << Radius << '\n';
//
//    return 0;
//
//}